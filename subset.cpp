#include <bits/stdc++.h>
#define limax 40
#define ham(n) (n * (n+1)) / 2

using namespace std;

// communist variables
    long long way[limax][ham(limax) + 1];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("subset.inp", "r", stdin);
    freopen("subset.out", "w", stdout);
#endif
    
    unsigned n, t; cin >> n;
    if ((t = ham(n)) % 2)
        cout << 0;
    else 
    {
        auto s = t/2; memset(way, 0, sizeof(way));
        for (unsigned i = 0; i <= n; i++)
            way[i][0] = 1;
        for (unsigned i = 1; i <= s; i++)
            way[0][i] = 0;
        for (unsigned i = 1; i <= n; i++)
            for (unsigned j = 1; j <= ham(i); j++)
                if (j >= i) 
                    way[i][j] = way[i-1][j] + way[i-1][j-i];
                else 
                    way[i][j] = way[i-1][j];
        cout << way[n][s] /2;
    }
}