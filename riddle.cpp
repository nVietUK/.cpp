#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

void solve() {
    int n, k, can = 0; scanf("%d%d", &n, &k); int a[n+1], cnt[100111];
    for (int i = 1; i <= n; i++) scanf("%d", a+i);

    memset(cnt, 0, sizeof cnt);
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] > can + 1) {
            ++cnt[a[i]]; 
            continue;
        }
        int save = can;
        can += a[i];
        for (int x = save+1; x <= can+1 && x <= 100001; ++x) 
            can += cnt[x]*x;

        if (can >= k) {
            ok = true;
            printf("%d\n", i);
            break;
        }
    }
    if (!ok) printf("-1\n");
}

signed main() {
    unsigned t; scanf("%u", &t); while (t--) solve();
}
