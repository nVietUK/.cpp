#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
#define floatf "%f"
#define intf "%d"
#define FILENAME "chuotchui"
#define dis(a, b) (sqrt(pow(abs(a.x-b.x), 2)+pow(abs(a.y-b.y), 2)))
typedef pair<int, int> ii;
int n, m, s, v;
struct obj {
    float x, y;
    obj(int x, int y) : x(x), y(y) {};
    obj() : x(0), y(0) {};
};
obj arr[210];
int adj[210][210];
vector<int> sub[210];

int bfs(int s, int t = 0, int *par = NULL) {
    fill(par, par+210, -1); par[s] = -2;
    queue<int> q; q.push(0);

    while (q.size()) {
        int curr = q.front(); q.pop();

        for (int next : sub[curr])
            if (par[next] ==-1 && adj[curr][next] > 0) {
                par[next] = curr;
                if (next == t) return 1;
                q.push(next);
            }
    }
    return -1;
}

int solve(int start, int last) {
    int par[210], cur, de, ou=0, tmp;
    while (true) {
        cur = last; ou += ((de = bfs(start, cur, par))!=-1);
        if (de == -1) return ou;
        do
            tmp = par[cur], adj[tmp][cur] -= de, adj[cur][tmp] += de, cur = tmp;
        while (cur != start);
    }
    return ou;
}

signed main() {
#if not nVietUK
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif // nVietUK

    fill(adj[0], adj[0]+210*210, 0);
    while (scanf(intf intf intf intf, &n, &m, &s, &v) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf(floatf floatf, &arr[i].x, &arr[i].y);
            adj[0][i] = 1; sub[0].push_back(i);
        }
        for (int i = 1; i <= m; i++) {
            scanf(floatf floatf, &arr[i+100].x, &arr[i+100].y);
            for (int j = 1; j <= n; j++) {
                float run = dis(arr[j], arr[i+100]);
                if (run <= v*s)
                    adj[j][i+100] = 1, sub[j].push_back(i+100), sub[i+100].push_back(j);
            }
            adj[i+100][201] = 1, sub[i+100].push_back(201);
        }
        printf(intf "\n", n - solve(0, 201));
    }
}
