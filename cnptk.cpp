#include <bits/stdc++.h>

using namespace std;

map<unsigned, unsigned> ta;
unsigned ins(unsigned in)
{
    unsigned p = 0, s = 0;
    while (true)
    {
        if (!ta[p])
        { ta[p] = in; return s; }
        else 
        if (ta[p] < in) p = p*2 + 2;
        else            p = p*2 + 1;
        s++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("cnptk.inp", "r", stdin);
    freopen("cnptk.out", "w", stdout);
    
    unsigned n, in, ou = 0;
    cin >> n;
    while (n-- && (cin >> in))
    {
        ou += ins(in);
        cout << ou << "\n";
    }
}