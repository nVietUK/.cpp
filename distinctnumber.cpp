#include <stdio.h>

bool a[1000000001];

signed main() {
    //freopen("test.inp", "r", stdin);
    unsigned n, ou = 0, in; scanf("%u", &n); while (n--) {
        scanf("%u", &in); ou += !a[in];
        a[in] = true;
    }
    printf("%u", ou);
}
