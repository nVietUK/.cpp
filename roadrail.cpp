#include <stdio.h>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>

using namespace std;
#define FILENAME ""
#define intf "%d"
const int INF = INT_MAX/2-50;
int N, M, L, Q;
struct way{
    bool isWalk = false;
    int cost = INF, des;
    way(bool isWalk = false, int des = 0, int cost = INF) : isWalk(isWalk), cost(cost), des(des) {};
    bool operator<(const way &a) const {
        return this->cost > a.cost;
    }
};
vector<way> arr[1000];

int solve(int &x, int &y) {
    priority_queue<way> q; 
    for (way e : arr[0])
        q.push(e);
    while (q.size()) {
        way cur = q.top(); q.pop();
        if (cur.des == y) return cur.cost;

        for (way e : arr[cur.des]) 
            q.push(way(e.isWalk, e.des, cur.cost+e.cost+((e.isWalk!=cur.isWalk)?x:0)));
    }
    return 0;
}

signed main() {
#if not nVietUK
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif

    scanf(intf intf intf intf, &N, &M, &L, &Q);
    for (int i = 0, x, y, z; i < M; i++) {
        scanf(intf intf intf, &x, &y, &z); 
        arr[x].push_back(way(true, y, z));
    }
    for (int i = 0, x, y, z; i < L; i++) {
        scanf(intf intf intf, &x, &y, &z);
        arr[x].push_back(way(false, y, z));
    }
    int x, y;
    while (Q--) {
        scanf(intf intf, &x, &y);
        printf(intf "\n", (y)?solve(x, y):0);
    }
}