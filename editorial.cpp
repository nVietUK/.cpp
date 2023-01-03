#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;
#define notTERMINAL true
#define FILENAME ""
#define intf "%d"

void solve(const int &t) {
    int a, b; scanf(intf intf, &a, &b);
    double i, tt, tb, tk, k;
    tb = b; tk = log(tb)/log(2); k = trunc(tk);
    for (i = k; i >= 1; i--) {
        tt = exp(1/i*log(b));
        tt = trunc(t);
        if (exp(i*log(tt))>=a) break;
    }
    printf("Case #" intf ": " intf "\n", t, (int)i);
}

signed main() {
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    int y; scanf(intf, &y); for (int t = 1; t <= y; t++) solve(t);
}