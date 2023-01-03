#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
#define FILENAME "Taxi"
#define inf "%d"
int n;
const int sz = 1001;
struct pas {
    int h, m, bx, by, fx, fy;
} pass[sz];
vector<int> sub[sz];
bool adj[sz][sz];

int time(const int &h, const int &m) {
    return h*60+m;
}

int spend(const pas &a) {
    return time(a.h, a.m) + abs(a.bx - a.fx) + abs(a.by - a.fy);
}

bool bfs(int s, int t = 0, int *par = NULL) {
    fill(par, par+210, -1); par[s] = -2;
    queue<int> q; q.push(0);

    while (q.size()) {
        int curr = q.front(); q.pop();

        for (int next : sub[curr])
            if (par[next] ==-1 && adj[curr][next] > 0) {
                par[next] = curr;
                if (next == t) return true;
                q.push(next);
            }
    }
    return false;
}

int findP(int start, int last) {
    int par[sz], taxi[sz], cur, de, ou=0, tmp, taxiID = 0;
    fill(taxi, taxi+sz, -1);
    while (true) {
        fill(par, par+sz, -1);
        cur = last; de = bfs(start, cur, par);
        if (!de) break; taxiID++;
        do
            tmp = par[cur], adj[tmp][cur]=false, adj[cur][tmp]=true, cur = tmp, taxi[tmp>500 ? tmp-500 : tmp]=taxiID;
        while (cur != start);
    }
    fill(par, par+sz, 1);
    for (int i = 0; i < n; i++) {
        ou += par[taxi[i]];
        par[taxi[i]] = 0;
    }
    return ou;
}

void solve() {
    scanf(inf, &n);
    for (int i = 1; i <= n; i++) {
        char com; scanf(inf "%c" inf inf inf inf inf, &pass[i].h, &com, &pass[i].m, &pass[i].bx, &pass[i].by, &pass[i].fx, &pass[i].fy);
        for (int j = 1; j < i; j++) {
            if (spend(pass[j]) < time(pass[i].h, pass[i].m))
                sub[i+500].push_back(j), sub[j+500].push_back(i), adj[j+500][i]=true,
                sub[i].push_back(j), sub[j].push_back(i), adj[j][i]=true;
        }
    }
    for (int i = 1; i <= n; i++) {
        sub[i+500].push_back(500), adj[i+500][500]=true; sub[0].push_back(i), adj[0][i]=true;
        sub[i].push_back(i+500); sub[i+500].push_back(i); adj[i][i+500]=true;
    }
    printf(inf "\n", findP(0, 500));
}

signed main() {
#if not nVietUK
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif // not

    int t; scanf(inf, &t); while (t--) solve();
}