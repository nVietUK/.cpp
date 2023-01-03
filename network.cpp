#include <bits/stdc++.h>

using namespace std;

int n, m, c[110][110], b[110][110], a[110][110], p[1000];
bool mst[1000];

int minpri(int p[], bool mst[]) {
    int mi=1000000, vtri=0;
    for (int v = 1; v <= n; v++)
        if (mst[v] == false && p[v] < mi) {
            mi = p[v];
            vtri = v;
        }
    return vtri;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    freopen("NETWORK.INP","r",stdin);
    freopen("NETWORK.OUT","w",stdout);

    cin >> n >> m;
    for (int i = 0; i<=n; i++)
        for (int j = 0; j<=n; j++)
            a[i][j] = a[j][i] = 1000000;
    for (int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        b[t1][t2] = b[t2][t1] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            c[j][i] = c[i][j];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (b[i][j] == 1 || b[j][i] == 1) 
                a[i][j] = a[j][i] = 0;
            else 
                a[i][j] = a[j][i] = c[i][j];
        }
    p[1] = 0; int v;
    for (int i = 2; i <= n; i++)
        p[i]=1000000;
    for (int i = 1; i <= n; i++)
        mst[i]=false;
    int tmp = n;
    int w = 0;
    while (tmp > 0) {
        v = minpri(p,mst);
        mst[v] = true;
        w += p[v];
        tmp--;
        for (int u = 1; u <= n; u++)
            if (!mst[u]) {
                int w = a[u][v];
                if (w<p[u]) 
                    p[u] = w;
            }
    }
    cout << w << "\n";
    return 0;
}