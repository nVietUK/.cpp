#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("dclt.inp", "r", stdin);
    freopen("dclt.out", "w", stdout);
    
    unsigned n, m, in, ou = 0;
    double t;
    vector<unsigned> wa;
    cin >> n >> m;

    while ((wa.size() < n) && (cin >> in)) wa.push_back(in);

    while (n--)
    {
        t = 0;
        for (auto i = n; i < wa.size(); i++)
        {
            t += wa[i];
            if (t >= m)
            {
                if (t == m)
                    ou++;
                break;
            }
        }
    }
    cout << ou;
}
