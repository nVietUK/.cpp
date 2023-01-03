#include <bits/stdc++.h>

using namespace std;
struct edge {
    unsigned v, l;
    edge(unsigned v=0, unsigned l=0) : v(v), l(l) {};
};
vector<edge> *g;
unsigned N, Q, u, v, l, *h, *f, **up;
int i;

void dfs(unsigned u) {
    for (edge &e : g[u]) {
        v = e.v, l = e.l;
        if (v == up[u][0]) continue;

        h[v] = h[u] + 1;
        f[v] = f[u] + l;

        up[v][0] = u;
        for (i = 1; i < 10; i++)
            up[v][i] = up[up[v][i-1]][i-1];
        
        dfs(v);
    }
}

unsigned lca(unsigned &u, unsigned &v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        l = h[u] - h[v];
        for (i = 0; (1 << i) <= l; i++)
            if (l >> i & 1)
                u = up[u][i];
    }
    if (v == u) return u;
    l = __lg(h[u]);
    for (i = l; i >= 0; i--)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

unsigned dist(unsigned &u, unsigned &v) {
    l = lca(u, v);
    return f[u] + f[v] - 2*f[l];
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N >> Q; 
    g = new vector<edge>[N+10]; h = new unsigned[N+10]; f = new unsigned[N+10]; up = new unsigned*[N+10];
    for (i = 0; i < N+10; i++) up[i] = new unsigned[10]; fill(up[0], up[0]+(N+10)*10, 0);
    for (i = 1; i < N; i++) {
        cin >> u >> v >> l;
        g[u].emplace_back(v, l);
        g[v].emplace_back(u, l);
    }
    dfs(1); while (Q--) {
        cin >> u >> v;
        cout << dist(u, v) << '\n';
    }
}
