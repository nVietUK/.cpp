#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("sodu.inp", "r", stdin);
    freopen("sodu.out", "w", stdout);
    
    unsigned n, p, a, b, r, ou = 1, tp;
    cin >> n >> p >> a >> b >> r;
    queue<unsigned> wa, st; wa.push(n); st.push(1);
    map<unsigned, bool> vi; vi[n] = true;
    while (wa.size())
    {
        n = wa.front(); wa.pop();
        ou = st.front(); st.pop();
        if (!vi[tp = ((n + a) % p)])
        { wa.push(tp); vi[tp] = true; st.push(ou + 1);
            if (tp == r)
            { cout << ou; return 0; }
        }
        if (!vi[tp = ((n + b) % p)])
        { wa.push(tp); vi[tp] = true; st.push(ou + 1);
            if (tp == r)
            { cout << ou; return 0; }
        }
    }
    cout << -1;
}