#include <bits/stdc++.h>

using namespace std;

// communist variable
    unsigned n, m, a, b, i;
    string s;
    vector<unsigned> ta;

unsigned goc(unsigned in)
{
    while (ta[in]) in = ta[in];
    return in;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("decode.inp", "r", stdin);
    freopen("decode.out", "w", stdout);
    
    unsigned t; cin >> t;
    while (t--)
    {
        cin >> n >> m; ta.clear(); ta.resize(n+1, 0); bool run = true;
        for (i = 0; (i < m) && (cin >> a >> s >> b); i++)
        if (run) {   
            if (a < b) swap(a, b);
            if (s == "=")
            {   if (ta[a]) 
                {
                    a = goc(a); b = goc(b);
                    if (a == b) continue;
                    if (a < b) swap(a, b);
                }
                ta[a] = goc(b);
            }
            else
            {   if (goc(a) == goc(b)) 
                {   cout << "NO" << "\n"; run = false; };
            }
        }
        if (run) cout << "YES" << "\n";
    }
}