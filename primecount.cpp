#include <bits/stdc++.h>
#define ONLINE false
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<unsigned, unsigned> uu;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        cout.tie(NULL);
        freopen("primecount.out", "w", stdout);
    #endif
    freopen("primecount.inp", "r", stdin);
#endif

    unsigned t; cin >> t;
    while(t--) {
        unsigned x, y, xx, ou = 0; cin >> x >> y; 
        vector<bool> isprime(y-x+1, true);
        for (ull i = 2; i*i <= y; i++)
            for (ull j = max(i*i, (x+i-1)/i*i); j <= y; j+= i)
                isprime[j-x] = false;
        if (1>=x) isprime[1-x] = false; xx = x;
        for (; x <= y; x++)
            if (isprime[x-xx]) ou++;
        cout << ou << "\n";
    }
}