#include <stdio.h>
#include <algorithm>
#include <vector>

#define FILENAME "dutcap"
#define intf "%d"

using namespace std;
const int limit_n = 100001;
pair<bool, bool> sta[limit_n];
vector<int> child[limit_n];
vector<pair<bool, bool>> bridge;

int k, l;
int chk_num[limit_n], chk_low[limit_n], chk_par[limit_n], chk_pointTH=0;
void subcheckpoint(int u, int o, int &net, int &cap) {
    chk_low[u] = chk_num[u] = ++chk_pointTH;
    for (int v : child[u]) {
        if (chk_num[v] == 0 && v != o) {
            chk_par[v]=u;
            subcheckpoint(v, o, net, cap);
        }
    }
    net += sta[u].second;
    cap += sta[u].first;
}
bool checkpoint(int u, int v) {
    int net=0, cap=0;
    fill(chk_num, chk_num+limit_n, 0);
    fill(chk_low, chk_low+limit_n, 0);
    fill(chk_par, chk_par+limit_n, 0);
    subcheckpoint(u, v, net, cap);
    return (net==0 || net==l || cap==0 || cap==k);
}

int dfs_low[limit_n], dfs_num[limit_n], dfs_par[limit_n], dfs_pointTH=0, dfs_root;
int findBridge(int u) {
    dfs_low[u] = dfs_num[u] = ++dfs_pointTH;
    int ou=0;
    for (int v : child[u]) {
        if (dfs_num[v] == 0) {
            dfs_par[v] = u;

            ou += findBridge(v);

            if (dfs_low[v] > dfs_num[u]) ou += checkpoint(u, v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v!=dfs_par[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
    return ou;
}

signed main() {
#if not nVietUK
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif // not

    int n, m, t, z;
    scanf(intf intf intf intf, &n, &m, &k, &l);
    for (int i=0; i<limit_n; i++) { sta[i].first = sta[i].second = false; }
    for (int i=0; i<k; i++) { scanf(intf, &t); sta[t].first = true; }
    for (int i=0; i<l; i++) { scanf(intf, &t); sta[t].second = true; }
    for (int i=0; i<m; i++) { scanf(intf intf, &t, &z); child[t].push_back(z); child[z].push_back(t); }

    fill(dfs_num, dfs_num+limit_n, 0); dfs_root=1;
    printf(intf, findBridge(dfs_root));
}
