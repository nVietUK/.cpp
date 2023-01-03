#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> ta;

unsigned w, h;

unsigned run(int c, int d)
{
    if (
        (
            (!(0 <= c) || !(c <= h)) ||
            (!(0 <= d) || !(d <= w)) 
        ) ||
        (ta[c][d] != '*')
    )
    return 0;
    else ta[c][d] = '-';
    auto ou = run(c+1, d) + run(c, d+1) + run(c-1, d) + run(c, d-1);
    return (ou) ? ou+1 : 1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("farm.inp", "r", stdin);
    freopen("farm.out", "w", stdout);
    
    unsigned pos, tp = 0, max = 0;
    cin >> w >> h;

    char inc;
    while (ta.size() < h)
    {
        pos = ta.size();
        ta.resize(ta.size() + 1);
        while ((ta[pos].size() < w) && (cin >> inc)) ta[pos].push_back(inc);
    }

    while (h--)
        for (unsigned pos = 0; pos < w; pos++)
        {
            if (ta[h][pos] == '*') tp = run(h, pos);
            if (tp > max) max = tp;
        }

    cout << max;
}