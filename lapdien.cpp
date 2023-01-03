#include <bits/stdc++.h>
#define pp pair<int, int>
#define length(x, y) \
    sqrt( \
        pow( \
            cotdien[x].first - cotdien[y].first, 2 \
        ) +  \
        pow( \
            cotdien[x].second - cotdien[y].second, 2 \
        ) \
    )

using namespace std;

// communist variables
    unsigned x, y, n;
    pp cotdien[1001];
    unsigned s[1001][1001];
    double k;

bool vi[1001];
#define obj pair<double, unsigned>
double djk()
{
    priority_queue<obj, vector<obj>, greater<obj>> wa; wa.push(obj(0, 1));
    memset(vi, false, sizeof(vi));
    while (wa.size())
    {
        auto curr = wa.top(); wa.pop();
        if (vi[curr.second])
            continue;
        if (curr.second == n)
            return curr.first * 1000;
        vi[curr.second] = true;
        for (unsigned i = 1; i <= n; i++)
        {
            double le = length(curr.second, i);
            if (curr.second != i && le <= k && le < s[curr.second][i])
            {
                s[curr.second][i] = s[i][curr.second] = le;
                wa.push(obj(curr.first + le, i));
            }
            else 
            if (!s[curr.second][i])
                wa.push(obj(curr.first, i));
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("lapdien.inp", "r", stdin);
    freopen("lapdien.out", "w", stdout);
#endif
    
    unsigned m; cin >> n >> m >> k;
    memset(s, -1, sizeof(s));
    for (unsigned i = 1; i <= n && cin >> x >> y; i++)
        cotdien[i] = pp(x, y);
    while (m-- && cin >> x >> y)
        s[x][y] = s[y][x] = 0;
    cout << setprecision(0) << fixed;
    cout << trunc(djk());
}