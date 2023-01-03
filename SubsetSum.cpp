#include <bits/stdc++.h>
#define limax 100 + 1

using namespace std;

// communist variables
    unsigned ta[limax], val[limax][100000 + 1];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("SubsetSum.inp", "r", stdin);
    freopen("SubsetSum.out", "w", stdout);
#endif
    
    unsigned n, m;
    cin >> n >> m;

    for (unsigned i = 1; i <= n; i++)
        cin >> ta[i];

    memset(val, 0, sizeof(val)); val[0][0] = 1;
    for (unsigned i = 1; i <= n; i++)
    {
        val[i][0] = 1;
        for (unsigned j = 1; j <= m; j++)
            if (j >= ta[i])
                val[i][j] = val[i-1][j] + val[i-1][j-ta[i]];
            else 
                val[i][j] = val[i-1][j];
    }
    cout << val[n][m];
}