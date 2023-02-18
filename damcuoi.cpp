#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
#define notTERMINAL true
#define FILENAME "damcuoi"
#define intf "%d"

const int limit_n = 101;
bool isconnected[limit_n][limit_n];
int d[limit_n], t, a[limit_n], b[limit_n];

bool dfs(int x, int &n) { 
    for (int i=1; i<=n; i++) {
        if (isconnected[x][i] && !d[i]) {
            t=i; d[i]=x;
            if (!b[i] || dfs(b[i], n)) return true;
        }
    }
    return 0;
}

bool find(int &m, int &n) {
    fill(d, d+limit_n, 0);
    for (int i=1; i<=m; i++) 
        if (!a[i])
            if (dfs(i, n)) return true;
    return false;
}

void inc() {
    int x, y; while (t) {
        x=d[t]; y=t;
        t=a[x]; a[x]=y; b[y]=x;
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

    int m, n; string s;
    fill(isconnected[0], isconnected[0]+limit_n*limit_n, false);
    cin >> m >> n; getline(cin, s);
    for (int i=1; i<=m; i++) {
        getline(cin, s); stringstream ss(s);
        while (ss >> t, t) {
            isconnected[i][t]=true;
        }
    }
    while (find(m, n)) inc(); t=0;
    for (int i=1; i<=m; i++) t+=(a[i]>0);
    printf(intf "\n", t); for (int i=1; i<=m; i++) 
        if (a[i])
            printf(intf " " intf "\n", i, a[i]);
}