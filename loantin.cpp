#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define notTERMINAL true
#define FILENAME ""
#define intf "%d"

const int limit_n=10001;
vector<int> child[limit_n];

void solve(int x, int *day, int *cnt) {
    day[x]=0; queue<int> q; q.push(x);
    while (q.size()) {
        int u=q.front(); q.pop(); 
        ++cnt[day[u]];
        for (int v : child[u]) 
            if (day[v]==-1) {
                day[v]=day[u]+1;
                q.push(v);
            }
    }
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

    int n; scanf(intf, &n);
    for (int u=0, m, v; u<n; u++) {
        scanf(intf, &m);
        while (m--) {
            scanf(intf, &v);
            child[u].push_back(v);
        }
    }
    int t, x, day[n], cnt[n]; scanf(intf, &t); while (t--) {
        scanf(intf, &x); 
        if (child[x].empty()) {
            printf("0\n"); continue;
        }
        fill(day, day+n, -1); fill(cnt, cnt+n, 0);
        solve(x, day, cnt); x=max_element(cnt, cnt+n)-cnt; printf(intf " " intf "\n", cnt[x], x);
    }
}