#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct edge{int des, len; 
    edge(int des = 0, int len = 0) : des(des), len(len) {};
};

unsigned n, m, x, y, l; 
vector<edge> arr[200000];
long long from1[200001], fromN[200001];

void dja(unsigned pos, long long *from) {
    fill(from+1, from+n+1, 1e10);

    bool P[n+1]; fill(P, P+n+1, false); from[pos] = 0;
    
    for (unsigned i = 1; i <= n; i++) {
        int uBest; long long Max = 1e10;
        for (unsigned u = 1; u <= n; u++) {
            if (from[u] < Max && !P[u]) 
                uBest = u,
                Max = from[u];
        }

        int u = uBest;
        P[u] = true; for (auto e : arr[u]) {
            int v = e.des, l = e.len;
            if (from[v] > from[u]+l) 
                from[v] = from[u]+l;
        }
    }
}

unsigned innode[200001], anstp[200001], ans[200001];
void val(vector<unsigned> *d) {
    for (unsigned i = 1; i <= n; i++) 
        for (auto e : arr[i])
            if (from1[i] + e.len == from1[e.des] || from1[i] + e.len + fromN[e.des] == from1[n])
                d[i].push_back(e.des),
                innode[e.des]++;
}

void topo(vector<unsigned> *d) {
    queue<unsigned> listsource;
    vector<unsigned> tp;
    for (unsigned i = 1; i <= n; i++)
        if (!innode[i]) listsource.push(i);

    fill(ans, ans+n+1, 0);

    while (listsource.size()) {
        x = listsource.front(); listsource.pop();
        tp.push_back(x); ans[x] = 2;
        if (x == n) break;
        for (auto e : d[x]) {
            innode[e]--;
            if (!innode[e]) listsource.push(e);
        }
    }

    for (unsigned i = tp.size() - 2; i > 0; i--) 
        for (unsigned j = 0; j < i; j++)
            for (unsigned l = i+1; l < tp.size(); l++)
                if (find(d[tp[j]].begin(), d[tp[j]].end(), tp[l]) != d[tp[j]].end())
                    ans[tp[i]] = 1;

    for (unsigned i = 1; i <= n; i++) 
        printf("%s\n", (!ans[i]) ? "none" : ((ans[i] == 1) ? "some" : "all"));
}

signed main() {
    freopen("toporso.inp", "r", stdin);
    freopen("toporso.out", "w", stdout);
    scanf("%u%u", &n, &m);
    while (m-- && scanf("%u%u%u", &x, &y, &l)) 
        arr[x].push_back(edge(y, l)),
        arr[y].push_back(edge(x, l));
    dja(1, from1), dja(n, fromN);
    vector<unsigned> d[n+1]; val(d); topo(d);
}
