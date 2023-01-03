#include <bits/stdc++.h>
#define posPP(pp) [pp.first][pp.second]
#define limax 6
#define pp pair<int, int>

using namespace std;

// communist variables
    long long ta[limax][limax];
    unsigned n, m, trace[limax][limax];

int tru(int so, int tru)
{
    if (!so && tru == -1)
        return n-1;
    if (so + tru >= n)
        return 0;
    return so + tru;
}

void chay(int inp, int jnp)
{
    pp o[3];
    o[0] = make_pair(tru(inp, -1), jnp + 1);
    o[1] = make_pair(inp         , jnp + 1);
    o[2] = make_pair(tru(inp, 1) , jnp + 1);
    sort(o, o + 3);
    auto go = min(ta posPP(o[0]), min(ta posPP(o[1]), ta posPP(o[2])));
    if (go == ta posPP(o[0]))
    {
        trace[inp][jnp] = o[0].first;
        ta[inp][jnp] += ta posPP(o[0]);
    }
    else 
    if (go == ta posPP(o[1]))
    {
        trace[inp][jnp] = o[1].first;
        ta[inp][jnp] += ta posPP(o[1]);
    }
    else 
    if (go == ta posPP(o[2]))
    {
        trace[inp][jnp] = o[2].first;
        ta[inp][jnp] += ta posPP(o[2]);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("timduong.inp", "r", stdin);
    freopen("timduong.out", "w", stdout);
#endif
    
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> ta[i][j];
        for (int i = n-1; i >= 0; i--)
            for (int j = m-2; j >= 0; j--)
                    chay(i, j);
        unsigned long long ou = -1, pos;
        for (unsigned i = 0; i < n; i++)
        {
            if (ou > ta[i][0])
            {
                ou = ta[i][0];
                pos = i;
            }
        }
        n = 0; do 
        {
            cout << pos + 1 << " ";
            pos = trace[pos][n++];
        }
        while (n < m);
        cout << "\n" << ou << "\n";
    }
}