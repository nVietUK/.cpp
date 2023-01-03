#include<bits/stdc++.h>

using namespace std;

typedef pair<unsigned, unsigned> pp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    freopen("Hainam.inp", "r", stdin);
    freopen("Hainam.out", "w", stdout);

    int n, m, r, k, res = 0, i, j;
    cin >> n >> m >> r >> k;
    char a[n+5][m+5]; int p[n+5][m+5];
    memset(p, 0, sizeof(p)); stack<pp> q;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            cin >> a[i][j]; 
            if (a[i][j] == 'S') 
                p[i][j]++;
            else 
            if (a[i][j] == 'M') 
                q.push(pp(i, j));
            p[i][j] += -p[i-1][j-1] + p[i][j-1] + p[i-1][j];
        }
    while (q.size()) {
        i = q.top().first, j = q.top().second; q.pop();
        int iv = max(i-r, 1), jv = max(j-r, 1), ui = min(i+r, n), uj = min(j+r, m), 
        sl = p[ui][uj] - p[iv-1][uj] - p[ui][jv-1] + p[iv-1][jv-1];
        res += sl >= k;
    }
    cout << res;
}