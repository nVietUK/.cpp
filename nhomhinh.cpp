#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> ta;
vector<vector<short>> sa;
short n, m;
short quet(short& x, short& y, short& o)
{
    if (sa[x][y]) { --o; return sa[x][y]; }
    sa[x][y] = o;
    for (short i = x; i <= x+1; i++)
        for (short j = y; j <= y+1; j++)
            if (
                (
                    (i < n) &&
                    (j < m)
                ) &&
                (
                    (
                        (
                            (
                                (ta[x][y] == 'B') &&
                                (
                                    (x == i) &&
                                    (y == j - 1)
                                )
                            ) ||
                            (
                                (ta[x][y] == 'C') &&
                                (
                                    (x == i - 1) &&
                                    (y == j)
                                )
                            )
                        ) &&
                        (ta[i][j] == 'A')
                    ) ||
                    (
                        (ta[x][y] == 'D') &&
                        (
                            (
                                (ta[i][j] == 'B') &&
                                (
                                    (x == i-1) &&
                                    (y == j)
                                )
                            ) ||
                            (
                                (ta[x][y] == 'A') &&
                                (
                                    (x == i - 1) &&
                                    (y == j - 1)
                                )
                            ) ||
                            (
                                (ta[x][y] == 'C') &&
                                (
                                    (x == i) &&
                                    (y == j - 1)
                                )
                            )
                        )
                    )
                )
            )
                sa[x][y] = quet(i, j, o);
    return sa[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("nhomhinh.inp", "r", stdin);
    freopen("nhomhinh.out", "w", stdout);
    
    short o = 1;
    cin >> n >> m;
    ta.resize(n); for (auto& a : ta) a.resize(m);
    sa.resize(n); for (auto& a : sa) a.resize(m, 0);

    for (short i = 0; i < n; i++)
        for (short j = 0; j < m; j++)
            cin >> ta[i][j];
    for (short i = 0; i < n; i++)
        for (short j = 0; j < m; j++)
            if (sa[i][j] == 0)
                { quet(i, j, o); ++o; };
    cout << o-1;
}