#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
#define FILENAME ""
#define intf "%d"
int n,m;

signed main() {
#if not nVietUK
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif

    vector<int> q;
    scanf(intf intf, &n, &m);
    for (int i = 1, t; i <= n; i++) {
        scanf(intf, &t); q.push_back(t);
    }
    sort(q.begin(), q.end());
    for (int i = 1, t; i <= m; i++) {
        scanf(intf, &t); vector<int>::iterator ti;
        if (*((ti = lower_bound(q.begin(), q.end(), t))-1) <= t && ti != q.begin())
            q.erase(ti-1);
    }
    if (q.size())
        printf(intf, *q.rbegin());
    else printf("-1");
}