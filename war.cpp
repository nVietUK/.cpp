#include <bits/stdc++.h> 
#include <cstdio>

using namespace std;

unsigned *parr, N, i, q, x, y, a, b, c, d; 
void init() { parr = new unsigned[N*2]; for (i = 0; i < N*2; i++) parr[i] = i; }

unsigned getparr(unsigned p) { return (p != parr[p]) ? getparr(parr[p]) : p; }

signed main() {
//    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N; init(); while (cin >> q >> x >> y && q) {
        a = getparr(x), b = getparr(y), c = getparr(x+N), d = getparr(y+N);
        if (q == 1) {
            if (a == d) 
                puts("-1");
            else 
                parr[a] = b, parr[c] = d;
        }
        else if (q == 2) {
            if (a == b)
                puts("-1");
            else 
                parr[a] = d, parr[c] = b;
        }
        else if (q == 3) cout << ((a == b) ? 1 : 0) << '\n';
        else if (q == 4) cout << ((a == d) ? 1 : 0) << '\n';
    }
}
