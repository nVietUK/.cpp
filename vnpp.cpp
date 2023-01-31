#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;
#define notTERMINAL true
#define FILENAME ""
#define intf "%d"

const int limit_n = 100;
vector<int> child[limit_n];

int dfs_low[limit_n], dfs_num[limit_n], dfs_par[limit_n], dfs_pointTH=0, dfs_childTH=0, dfs_root;
bool isChokePoint[limit_n];
void findBridge(int u) {
    dfs_low[u] = dfs_num[u] = ++dfs_pointTH;
    for (int v : child[u]) {
        if (dfs_num[v] == 0) {
            dfs_par[v] = u; dfs_childTH+=(u==dfs_root);
            findBridge(v);
            if (u != dfs_root && dfs_low[v] >= dfs_num[u]) isChokePoint[u] = true;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v!=dfs_par[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    int n; while (cin >> n, n != 0) {
        string s;
        for (int i=0; i<limit_n; i++) child[i].clear();
        fill(dfs_low, dfs_low+limit_n, 0);
        fill(dfs_num, dfs_num+limit_n, 0);
        fill(dfs_par, dfs_par+limit_n, 0);
        while (getline(cin, s), s != "0") {
            stringstream ss(s); int u, v;
            ss >> u; while (ss >> v) {
                child[u].push_back(v);
                child[v].push_back(u);
            }
        }

        for (int i=1; i<=n; i++) {
            if (dfs_num[i] == 0) {
                dfs_root=i, dfs_childTH=0;
                fill(isChokePoint, isChokePoint+limit_n, false);
                findBridge(dfs_root); isChokePoint[dfs_root]=(dfs_childTH>1);
            }
        }

        printf(intf "\n", count(isChokePoint, isChokePoint+limit_n, true));
    }
}