#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
#define notTERMINAL true
#define FILENAME "gallery"
#define intf "%d"

struct guard {
    int start, end, cost, id;
    guard(int start=-1, int end=-1, int cost=-1, int id=-1) : start(start), end(end), cost(cost), id(id) {};
    inline bool operator<(guard a) const { return cost>a.cost; }
};

int solve(vector<guard> guards[], int &n, int &m) {
    priority_queue<guard> p; for (guard i : guards[0]) p.push(i);
    bool passed[m+1]; fill(passed, passed+m+1, false);

    while (p.size()) {
        guard cur=p.top(); p.pop();

        if (passed[cur.id]) continue;
        passed[cur.id]=true;
        if (cur.end==n) return cur.cost;

        for (int i=cur.start+1; i<=cur.end && i<=n; i++)
            for (guard ii : guards[i])
                p.push(guard(ii.start, ii.end, ii.cost+cur.cost, ii.id));
    }
    return -1;
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

    int n, m; scanf(intf intf, &n, &m);
    vector<guard> guards[n+1];
    for (int i=1, e, c, s; i<=m; i++) {
        scanf(intf intf intf, &s, &e, &c);
        guards[s].push_back(guard(s, e, c, i));
    }
    printf(intf, solve(guards, n, m));
}