#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("bthuyen.inp", "r", stdin);
    freopen("bthuyen.out", "w", stdout);
    
    unsigned n, m, inn, inm;
    cin >> n >> m;

    vector<vector<unsigned> > ta(n+1);
    while ((m--) && (cin >> inn) && (cin >> inm)) { ta[inn].push_back(inm); ta[inm].push_back(inn); }

    vector<bool> ba(n+1, false);
    stack<unsigned> wa; wa.push(1);
    while (wa.size())
    {
        unsigned pos=wa.top(); ba[pos] = true;
        wa.pop();
        for (unsigned a : ta[pos])
            if (!(ba[a])) { ba[a] = true; wa.push(a); };
    }
    if (find(ba.begin()+1, ba.end(), false) == ba.end()) { cout << 0; return 0; };
    for (m = 1; m <= n; m++) if (!ba[m]) cout << m << endl;
}