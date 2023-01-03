#include <bits/stdc++.h>

using namespace std;

vector<vector<short>> ta;
unsigned short n;
void quet(short x, short y, short dd, short qq)
{
    ta[x][y] = dd;
    for (short i = x-1; i <= x+1; i++)
        for (short j = y-1; j <= y+1; j++)
            if (
                (
                    (i < n) &&
                    (j < n) &&
                    (i >= 0) &&
                    (j >= 0)
                ) &&
                (ta[i][j] == qq)
            )
                quet(i, j, dd, qq);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("ctmatrix.inp", "r", stdin);
    freopen("ctmatrix.out", "w", stdout);
    
    unsigned short in, ou = 0;
    cin >> n;
    for (unsigned i = 0; i < n; i++)
    {
        ta.push_back({});
        for (unsigned j = 0; (j < n) && (cin >> in); j++)
            ta[ta.size()-1].push_back(in);
    }
    for (unsigned i = 0; i < n; i++)
        if (ta[0][i]) quet(0, i, 3, 1);
    for (unsigned i = 0; i < n; i++)
        if (ta[i][0]) quet(i, 0, 4, 2);
    for (int i = n-1; i; i--)
        if (ta[n-1][i] == 3) { ou += 1; break; };
    for (int i = n-1; i; i--)
        if (ta[i][n-1] == 4) { ou += 2; break; };
    cout << ou;
}