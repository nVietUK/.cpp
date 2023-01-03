#include <bits/stdc++.h>

using namespace std;

struct di
{
    unsigned diem;
    vector<unsigned> last;
};

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("dulich.inp", "r", stdin);
    freopen("dulich.out", "w", stdout);
    
    unsigned m, n, t, c, inn, inm, x, y;
    cin >> n >> m >> t >> c;
    vector<vector<unsigned> > ta(n+1);
    while ((m--) && (cin >> inn) && (cin >> inm)) { ta[inn].insert(upper_bound(ta[inn].begin(), ta[inn].end(), inm),inm); ta[inm].insert(upper_bound(ta[inm].begin(), ta[inm].end(), inn),inn); }
    cin >> x >> y;
    if (x == y)
    {
        cout << 1 << endl << x;
    }

    vector<di> wa;
    wa.push_back(di{x, {}});
    while (wa.size())
    {
        for (auto a : ta[wa[0].diem])
        {
            if (find(wa[0].last.begin(), wa[0].last.end(), a) != wa[0].last.end()) continue;
            if (a == y)
            {
                cout << wa[0].last.size()+2 << endl;
                while (wa[0].last.size()) 
                {
                    cout << wa[0].last[0] << " ";
                    wa[0].last.erase(wa[0].last.begin());
                }
                cout << wa[0].diem << " " << y;
                return 0;
            }
            wa.push_back(di{a, wa[0].last});
            wa[wa.size()-1].last.push_back(wa[0].diem);
        }
        wa.erase(wa.begin());
    }
}