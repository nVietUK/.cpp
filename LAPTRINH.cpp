#include <bits/stdc++.h>
#define pos(x) (int)(x - 'A')

using namespace std;
unsigned N, M, **arr, i, t, *trace, **value;
char x, y;

bool isPath() {
	memset(trace, 0, sizeof(unsigned) * (N));
	queue<unsigned> q; q.push(0);
	trace[0] = N+1;
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
	int x = N, y; t = INT_MAX;
	do 
		y = trace[x], t = min(t, arr[y][x]-value[y][x]), x = y;
	while (x != 0);
	x = N;
	do 
		y = trace[x], value[y][x] += t, value[x][y] -= t, x = y;
	while (x != 0);
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	freopen("LAPTRINH.INP", "r", stdin);
	freopen("LAPTRINH.OUT", "w", stdout);

	cin >> M; N = pos('Z');
	arr = new unsigned * [N]; 
	trace = new unsigned[N];
	value = new unsigned * [N];
	for (i = 0; i <= N; i++) {
		arr[i] = new unsigned [N];
		value[i] = new unsigned [N];
		memset(value[i], 0, sizeof(unsigned) * (N));
		memset(arr[i], 0, sizeof(unsigned) * (N));
	}
	while (M--) {
		cin >> x >> y >> t;
		arr[pos(x)][pos(y)] += t;
	}
	while (isPath()) increaseFlow();
	
	t = 0; for (i = 1; i <= N; i++)
		if (value[i][N]>0) t += value[i][N];
	cout << t;
}
