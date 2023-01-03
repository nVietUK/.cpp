#include <bits/stdc++.h>

using namespace std;
vector<int> g[100009];
int n, v, u, h[100009], up[100009][17], m, root=1;
int i;
char c;

void dfs(int u) {
    for (int &v : g[u]) {
        if (v == up[u][0]) continue;

        h[v] = h[u]+1, up[v][0] = u;
        for (i = 1; i < 17; i++)
            up[v][i] = up[up[v][i-1]][i-1];
        dfs(v);
    }
}

int lca(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);

        n = h[u] - h[v];
        for (i = 0; (1 << i) <= n; i++)
            if (n >> i & 1)
                u = up[u][i];
    }
    if (u == v) return u;

    n = __lg(h[u]);
    for (i = n; i >= 0; i--)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    while (cin >> n, n) {
        for (i = 1; i <= n; i++) { g[i].clear(); }
        for (i = 1; i < n; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        
        cin >> m; while (m--) {
            cin >> c;
            if (c == '!') cin >> root;
            else {
                cin >> u >> v;
                cout << (lca(u, v) ^ lca(u, root) ^ lca(v, root)) << '\n';
            }
        }
    }
}
