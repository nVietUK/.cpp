#include <cstdio>
#include <ios>
#include <iostream>

using namespace std;

void solve() {
    long long a, b; scanf("%lld %lld", &a, &b);
    if (a > b) swap(a, b);
    if (a*2 < b || (a+b)%3!=0) 
        printf("NO\n");
    else 
        printf("YES\n");
}

signed main() {
    unsigned t; scanf("%u", &t); while(t--) solve();
}
