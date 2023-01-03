#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
#define intf "%d"
#define FILENAME "doanstt"
const int sz = 5000;
int n;
struct obj {
    int x1, y1, x2, y2;
};
obj arr[sz];
bool adj[sz][sz], passed[sz];

int bfs(int s) {
    for (int i = 1; i <= n; i++) {
        if (adj[s][i] && !passed[i]) { 
            passed[i]=true;
            if (par[i]==-1 || bfs(par[i])) {
                par[i]=s;
                return 1;
            }
        }
    }
    return 0;
}

int par[sz];
int solve() {
    int ans=0; fill(par, par+sz, -1);
    for (int i = 1; i <= n; i++) {
        fill(passed, passed+sz, false);
        ans += bfs(i);
    }
    return ans;
}

signed main() {
#if not nVietUK
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif // nVietUK

    fill(adj[0], adj[0]+sz*sz, 0); int t = 0;
    while (scanf(intf, &n) != EOF) { t++;
        if (!n) return 0;
        for (int i = 1; i <= n; i++) 
            scanf(intf intf intf intf, &arr[i].x1, &arr[i].x2, &arr[i].y1, &arr[i].y2);
        for (int i = 1; i <= n; i++) {
            scanf(intf intf, &arr[i+n].x1, &arr[i+n].y1);
            for (int j = 1; j <= n; j++) {
                if (
                    (arr[i+n].x1 < arr[j].x2 && arr[i+n].x1 > arr[j].x1) &&
                    (arr[i+n].y1 < arr[j].y2 && arr[i+n].y1 > arr[j].y1)
                )
                    adj[j][i+n] = 1; 
            }
        }
        printf("Heap " intf "\n", t);
        bool passed = false;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) {
                if (!adj[i][j])
                    continue;
                adj[i][j]=0;
                if (solve() < n) {
                    passed = true;
                    printf("\(%c," intf "\)", 'A'+(i-1), j);
                }
                adj[i][j]=1;
            }
        if (!passed) printf("none");
        printf("\n\n");
    }
}
