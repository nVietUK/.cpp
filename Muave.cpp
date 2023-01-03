#include <bits/stdc++.h>

using namespace std;

struct muave
{
    unsigned a, b, c;
};


// communist variables
    vector<muave> wa;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("muave.inp", "r", stdin);
    freopen("muave.out", "w", stdout);
#endif
    
    unsigned n, a, b, c; cin >> n;
    while (n-- && cin >> a >> b >> c)
        wa.push_back({a, b, c});
    n = wa.size();
    unsigned T[n+1]; memset(T, 0, sizeof(T));
    T[1] = wa[0].a;
    T[2] = min(wa[0].a+wa[1].a, wa[0].b);
    wa.insert(wa.begin(), {0, 0, 0});
    for (unsigned i = 3; i <= n; i++)
    {  
        T[i] = min(T[i-1] + wa[i].a, min(T[i-2] + wa[i-1].b, T[i-3] + wa[i-2].c));
    }
    cout << T[n];
}