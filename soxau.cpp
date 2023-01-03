#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long 

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("soxau.inp", "r", stdin);
    freopen("soxau.out", "w", stdout);
    
    set<ll> temp; temp.clear(); temp.insert(0);

    for (short nam = 0; nam <= 12; nam++)
        for (short ba = 0; ba <= 18; ba++)
            for (short hai = 0; hai <= 29; hai++)
                temp.insert((pow(2,hai) * pow(3,ba) * pow(5,nam)));
    short n; while ((cin >> n) && (n))
    {
        set<ll>::iterator i = temp.begin(); advance(i, n);
        cout << *i << "\n";
    }

    return 0;
}