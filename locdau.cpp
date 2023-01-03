#include <stdio.h>
#include <algorithm>
#include <queue>
#include <climits>

#define digitf "%d"
#define digit int

using namespace std;
const int _SZ = 100+3;
const int INF = INT_MAX;
typedef pair<int, int> ii;
digit N, M, B, D, c[_SZ][_SZ];
vector<int> adj[_SZ*2];

digit bfs(digit s, digit t, int *par) {
    fill(par, par+(N+2)*2, -1);
    par[s] = -2;
    queue<ii> q; q.push({s, INF});

    while (q.size()) {
        int curr = q.front().first;
        int f = q.front().second;
        q.pop();

        for (int next : adj[curr]) {
            if (par[next] ==-1 && c[curr][next]) {
                par[next] = curr;
                int nextf = min(f, c[curr][next]);
                if (next == t)
                    return nextf;
                q.push({next, nextf});
            }
        }
    }
    return 0;
}

digit ketqua() {
    int par[(N+2)*2], curr, de, ou = 0;
    do {
        curr = N+1;
        ou += (de = bfs(0, curr, par));
        if (!de) return ou;
        do {
            int prev = par[curr];
            c[prev][curr] -= de;
            curr = prev;
        }
        while (curr);
    }
    while (true);
}

signed main() {
#if not nVietUK
    freopen("LOCDAU.OUT", "w", stdout);
    freopen("LOCDAU.INP", "r", stdin);
#else
    freopen("test.txt", "r", stdin);
#endif // not

    scanf(digitf, &N); digit tram[N+2];
    fill(c[0], c[0]+_SZ*_SZ, 0);
    for (int i = 1; i <= N; i++) {
        scanf(digitf, &tram[i]); 
        c[i+N+1][i] = tram[i]; adj[i+N+1].push_back(i);
    }
    scanf(digitf, &M);
    for (digit i = 1, x, y, z; i <= M; i++) {
        scanf(digitf digitf digitf, &x, &y, &z);
        c[x][y+N+1] = z; adj[x].push_back(y+N+1);
    }
    scanf(digitf digitf, &B, &D);
    for (digit i = 1, x; i <= B+D; i++) {
        scanf(digitf, &x);
        if (i <= B) { c[0][x+N+1] = INF; adj[0].push_back(x+N+1); }
        else { c[x][N+1] = INF; adj[x].push_back(N+1); }
    }
    printf(digitf, ketqua());
}
