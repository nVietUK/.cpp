#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>

using namespace std;
#define notTERMINAL true
#define FILENAME ""
#define intf "%d"

const int limit_n=2e4+10;
const int inf=INT_MAX/2-10;
int low[limit_n], num[limit_n], bel[limit_n], in[limit_n], scc=0, timer=0;
vector<int> adj[limit_n];

stack<int> s;
void dfs(int u) {
    low[u]=num[u]=++timer;
    s.push(u); for (int v : adj[u]) 
        if (num[v]) 
            low[u]=min(low[u], num[v]);
        else {
            dfs(v); 
            low[u]=min(low[u], low[v]);
        }
    if (low[u]==num[u]) {
        scc++; int v; do {
            v=s.top(); s.pop();
            low[v]=num[v]=inf; 
            bel[v]=scc;
        } while (v!=u);
    }
}

void nen(int n) {
    fill(low, low+limit_n, 0); fill(num, num+limit_n, 0);
    fill(in, in+limit_n, 0); timer=scc=0;
    for (int i=1; i<=n; i++) 
        if (!num[i]) dfs(i);
    for (int u=1; u<=n; u++) 
        for (int v : adj[u])
            if (bel[u]!=bel[v]) 
                in[bel[v]]++;
}

void solve(int i) {
    int n, m; scanf(intf intf, &n, &m);
    for (int z=0; z<limit_n; z++) 
        adj[z].clear();
    for (int z=1, u, v; z<=m; z++) {
        scanf(intf intf, &u, &v);
        adj[u].push_back(v);
    }
    int ou=0; nen(n); for (int z=1; z<=scc; z++) 
        if (!in[z])
            ou++;
    printf("Case " intf ": " intf "\n", i, ou);
}

signed main() {
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    int t; scanf(intf, &t);
    for (int i=1; i<=t; i++) solve(i);
}