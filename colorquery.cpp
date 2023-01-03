#include <bits/stdc++.h> 

using namespace std;
unsigned N, Q, *arr, i, op, x, y;

struct DSU {
	map<unsigned, unsigned> *color;
	int *parent, *sz;

	DSU(int n) {
		color = new map<unsigned, unsigned>[n];
		parent = new int[n]; sz = new int[n];
	}

	void makeset(int v) {
		color[v][arr[v]] = 1;
		parent[v] = v;
		sz[v] = 1;
	}

	unsigned findset(int v) {
		if (v == parent[v]) return v;
		return parent[v] = findset(parent[v]);
	}

	void unionsets(unsigned a, unsigned b) {
		a = findset(a), b = findset(b);
		if (a != b) {
			if (sz[a] < sz[b]) swap(a, b);
			parent[b] = a;
			sz[a] += sz[b];

			for (auto p : color[b]) color[a][p.first] += p.second;
			color[b].clear();
		}
	}

	int query(unsigned a, unsigned b) {
		a = findset(a);
		return color[a].find(b) != color[a].end() ? color[a][b] : 0;
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> Q; arr = new unsigned[N+1];
	for (i = 1; i <= N && cin >> arr[i]; i++);
	DSU g(N+5);
	for (i = 1; i <= N; i++) g.makeset(i);
	while (Q--) {
		cin >> op >> x >> y;
		if (op == 1) g.unionsets(x, y);
		else cout << g.query(x, y) << "\n";
	}
}
