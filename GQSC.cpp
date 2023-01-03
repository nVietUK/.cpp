#include <bits/stdc++.h>

using namespace std;
unsigned N, M, **arr, i, t, x, y, *trace, **value;

bool isPath() {
	memset(trace, 0, sizeof(unsigned) * (N+1));
	queue<unsigned> q; q.push(1);
	trace[1] = N+1;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (t = 1; t <= N; t++)
			if (!trace[t] && arr[u][t] > value[u][t]) {
				trace[t] = u;
				if (t == N) return true;
				q.push(t);
			}
	}
	return false;
}

void increaseFlow() {
	x = N; t = INT_MAX;
	do 
		y = trace[x], t = min(t, arr[y][x]-value[y][x]), x = y;
	while (x != 1);
	x = N;
	do 
		y = trace[x], value[y][x] += t, value[x][y] -= t, x = y;
	while (x != 1);
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	freopen("GQSC.INP", "r", stdin);
	freopen("GQSC.OUT", "w", stdout);

	cin >> N >> M;
	arr = new unsigned * [N+1]; 
	trace = new unsigned[N+1];
	value = new unsigned * [N+1];
	for (i = 1; i <= N; i++) {
		arr[i] = new unsigned [N+1];
		value[i] = new unsigned [N+1];
		memset(value[i], 0, sizeof(unsigned) * (N+1));
		memset(arr[i], 0, sizeof(unsigned) * (N+1));
	}
	while (M--) {
		cin >> x >> y >> t;
		arr[x][y] += t;
	}
	while (isPath()) increaseFlow();
	
	t = 0; for (i = 1; i <= N; i++)
		if (value[i][N]>0) t += value[i][N];
	cout << t;
}
