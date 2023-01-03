#include <bits/stdc++.h>

using namespace std;

vector<vector<short>> ta;
short n, m;
void quet(short x, short y)
{
    ta[x][y] = 0;
    for (short i = x-1; i <= x+1; i++)
        for (short j = y-1; j <= y+1; j++)
            if (
                (
                    (i < n) &&
                    (j < m) &&
                    (i >= 0) &&
                    (j >= 0)
                ) &&
                (ta[i][j] != 0)
            )
                quet(i, j);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("mienso.inp", "r", stdin);
    freopen("mienso.out", "w", stdout);
    
    short o = 0;
    cin >> n >> m;
    ta.resize(n); for (auto& a : ta) a.resize(m);

    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j < m; j++)
            cin >> ta[i][j];
    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j < m; j++)
            if (ta[i][j] != 0)
                { quet(i, j); o++; };
    cout << o;
}