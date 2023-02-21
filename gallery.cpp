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
    int start, end, cost;
    guard(int start=-1, int end=-1, int cost=-1) : start(start), end(end), cost(cost) {};
    inline bool operator<(guard a) const { return start<a.start; }
    inline bool operator>(guard a) const { return cost>a.cost; }
};

int solve(guard guards[], int &n, int &m) {
    int cost[n+1], cur=1; cost[n]=INT_MAX; cost[0]=0;
    priority_queue<guard, vector<guard>, greater<guard>> pq;
    
    for (int i=1; i<=m; i++) {
        while (cur<=guards[i].start) {
            while (pq.top().end<cur) pq.pop();
            cost[cur]=pq.top().cost; cur++;
        }

        pq.push(guard(guards[i].start, guards[i].end, cost[cur-1]+guards[i].cost));
    }

    int tmp=INT_MAX;
    while (pq.size()) {
        if (pq.top().end>=n) {
            tmp=pq.top().cost; break;
        }
        pq.pop();
    }
    return min(cost[n], tmp);
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
    guard guards[m+1];
    for (int i=1, e, c, s; i<=m; i++) {
        scanf(intf intf intf, &s, &e, &c);
        guards[i]=guard(s, e, c);
    }
    sort(guards+1, guards+m+1);
    printf(intf, solve(guards, n, m));
}