#include <stdio.h>

void solve(unsigned a, unsigned b, unsigned c, unsigned n) {
    if (n) {
        solve(a, c, b, n-1);
        printf("%u %u\n", a, c);
        solve(b, a, c, n-1);
    }
}

signed main() {
    unsigned n; scanf("%u", &n); printf("%d\n", (1<<n)-1); solve(1, 2, 3, n);
}
