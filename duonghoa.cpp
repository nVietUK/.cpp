#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
#define notTERMINAL true
#define FILENAME ""
#define intf "%d"

const int limit_p=1e4, inf=INT_MAX/2-10;
typedef long long int lli;
struct point {
    int u, v; lli l;
    point(int u=0, int v=0, lli l=0) : u(u), v(v), l(l) {};
    inline bool operator<(point a) const { return u < a.u; }
};
struct pointer {
    int x; lli len;
    pointer(int x=0, lli len=-1) : x(x), len(len) {};
    inline bool operator<(pointer a) const { return len < a.len; }
};

lli dfs(lli *goW, vector<pointer> child[limit_p], int start, int end=-1) {
    fill(goW, goW+limit_p, inf); goW[start]=0; lli ou=inf;
    priority_queue<pointer> pq; pq.push(pointer(start, 0));
    
    while (pq.size()) {
        pointer cur=pq.top(); pq.pop();

        if (cur.len > goW[cur.x]) continue;
        if (end==cur.x) ou=cur.len;
        
        for (pointer to : child[cur.x])
            if (cur.len+to.len<goW[to.x]) {
                goW[to.x]=cur.len+to.len;
                pq.push(pointer(to.x, goW[to.x]));
            }
    }
    if (end>0) return ou;
    return -1;
}

lli solve(vector<pointer> child[limit_p], vector<point> path, int p) {
    lli goS[limit_p], goF[limit_p], minL=dfs(goF, child, 0, p-1), ou=0; dfs(goS, child, p-1);
    for (point cur : path) {
        if (
            (goS[cur.u]+cur.l+goF[cur.v] == minL) ||
            (goS[cur.v]+cur.l+goF[cur.u] == minL)
        )
            ou+=cur.l;
    }
    return ou;
}

int main() {
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    int p, t; scanf(intf intf, &p, &t);
    vector<pointer> child[limit_p]; vector<point> path;
    while (t--) {
        int x, y, l; scanf(intf intf intf, &x, &y, &l);
        child[x].push_back(pointer(y, l)), child[y].push_back(pointer(x, l));
        path.push_back(point(x, y, l));
    }
    printf("%lld", solve(child, path, p)*2);
}