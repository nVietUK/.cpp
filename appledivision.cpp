#include <stdio.h>
#include <algorithm>

using namespace std;

unsigned a[20];

signed main() {
    unsigned n; scanf("%u", &n); for (unsigned i = 0; i < n; i++) scanf("%u", &a[i]); long long ou = 1e18;

    for (unsigned i = 1; i < (1<<n); i++) {
        long long sumA = 0, sumB = 0;
        for (unsigned p = 0; p < n; p++)
            if (i & (1<<p))
                sumA += a[p];
            else 
                sumB += a[p];
        ou = min(ou, abs(sumA - sumB));
    }
    printf("%lld", ou);
}
