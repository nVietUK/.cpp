#include <bits/stdc++.h>

using namespace std;
vector<unsigned> g[70009];
unsigned h[70009], up[70009][18], u, v, N, Q;
int i;

void dfs(unsigned u) {
    for (unsigned v : g[u]) {
        if (up[u][0] == v) continue;

        up[v][0]=u, h[v]=h[u]+1;
        for (i = 1; i < 18; i++) 
            up[v][i] = up[up[v][i-1]][i-1];
        dfs(v);
    }
}

unsigned solve(unsigned u, unsigned v) {
    if (u == v) return u;
    int mid = u+v >> 1, k; 
    u = solve(u, mid), v = solve(mid+1, v);
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        k = h[u] - h[v];
        for (i = 0; (1 << i) <= k; i++) 
            if (k >> i & 1)
                u = up[u][i];
    }
    if (u == v) return u;
    k = __lg(h[u]);
    for (i = k; i >= 0; i--)
        if (up[u][i] != up[v][i]) 
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N >> Q;
    for (i = 1; i < N; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);

    while (Q--) {
        cin >> u >> v;
        cout << solve(u, v) << '\n';
    }
}
