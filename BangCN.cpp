#include <bits/stdc++.h>

using namespace std;

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("BangCN.inp", "r", stdin);
    freopen("BangCN.out", "w", stdout);
#endif
    
    unsigned k, r, n, m, tp;
    cin >> k >> r >> n >> m;
    unsigned long long ta[n+1][m+1]; memset(ta, 0, sizeof(ta)); 
    unsigned long long lh[n+1][m+1]; memset(lh, 0, sizeof(lh)); 
    unsigned long long lc[n+1][m+1]; memset(lc, 0, sizeof(lc));
    for (unsigned i = 1; i <= n; i++)
        for (unsigned j = 1; j <= m; j++)
        {
            if (i == 2 && j == 2) tp = 1; else tp = 2;
            ta[i][j] = (tp*ta[i-1][j-1] + lc[i-1][j] + lh[i][j-1]) % r;
            if (i == 1 && j == 1) ta[i][j] = k; 
            lh[i][j] = (lh[i][j-1] + ta[i][j]);
            lc[i][j] = (lc[i-1][j] + ta[i][j]);
        }
    cout << ta[n][m];
}