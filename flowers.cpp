#include <bits/stdc++.h>

using namespace std;

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Flowers.inp", "r", stdin);
    freopen("Flowers.out", "w", stdout);
#endif
    
    unsigned n, m, S, x = 0, y = 0, minTien = 0, in, thu[1000006];
    cin >> n >> m >> S; vector<unsigned> co;

    for (unsigned i = 1; i <= n && cin >> in; i++)
    {   
        thu[in] = i;
        co.push_back(in);
    }
    sort(co.begin(), co.end());
    for (unsigned i = 1; i <= m && cin >> in; i++)
    {
        int pos = upper_bound(co.begin(), co.end(), S-in) - co.begin() - 1;
        if (pos < 0)
            continue;
        if (minTien <= co[pos] + in && in + co[pos] <= S)
        {
            x = thu[co[pos]];
            y = i;
            minTien = co[pos] + in;
        }
    }
    cout << x << " " << y;
}