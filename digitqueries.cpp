#include <stdio.h>

long long power[19];

void init() {
    power[0] = 1; for (unsigned i = 1; i < 19; i++) 
        power[i] = power[i-1]*10;
}

long long pow10(unsigned x) {
    long long res = 1, y = 10; while (x > 0) {
        if (x&1) res *= y; x>>=1, y*=y;
    }
    return res;
}

signed main() {
    init(); unsigned t; scanf("%u",&t); while (t--) {
        long long n, numDig = 0, di = 0, prevDig = 0; scanf("%llu", &n);
        for (unsigned i = 1; i < 19; i++) {
            di += (power[i] - power[i-1]) *i;
            if (di >= n) { numDig = i; break; }
            prevDig = di;
        }
        long long low = power[numDig-1], high = power[numDig]-1, ans = 0, startPosAns = 0;
        while (low <= high) {
            long long mid = (high+low)/2, startPos = (mid - power[numDig-1]) * numDig + prevDig + 1;
            if (startPos <= n) {
                if (mid > ans) {
                    ans = mid, startPosAns = startPos;
                }
                low = mid +1;
            }
            else 
                high = mid - 1;
        }
        printf("%llu\n", (ans/pow10(numDig-(n-startPosAns)-1))%10);
    }
}
