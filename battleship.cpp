#include <bits/stdc++.h>

using namespace std;

unsigned h, w;
vector<vector<bool>> ta;
vector<int> ro = {-1, 0 , 1, 0};
vector<int> co = {0 , -1, 0, 1};
unsigned quet(int x, int y)
{
    if (!ta[x][y]) return 0;
    ta[x][y] = false; unsigned l = 0;    
    queue<pair<int, int>> wa; wa.push(make_pair(x, y));
    while (wa.size())
    {
        l++;
        int i = 4; while (i--)
            if (
                (
                    ((x = wa.front().first+ro[i]) < h) &&
                    ((y = wa.front().second+co[i]) < w) &&
                    ((x) >= 0) && ((y) >= 0)
                ) &&
                (ta[x][y])
            )
            {
                wa.push(make_pair(x, y));
                ta[x][y] = false;
            }
        wa.pop();
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("battleship.inp", "r", stdin);
    freopen("battleship.out", "w", stdout);
    
    unsigned k, t = 0, m, n = 0;
    cin >> h >> w >> k;

    ta.resize(h); char in;
    for (int i = 0; i < h; i++)
        for (int j = 0; (j < w) && (cin >> in); j++)            
            { ta[i].push_back(in == '1'); if (ta[i][ta[i].size()-1]) t++; }
    while (k--)
    {
        cin >> m >> n;
        cout << (t -= quet(--m, --n)) << "\n";
    }
}