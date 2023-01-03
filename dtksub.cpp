#include <algorithm>
#include <stdio.h>

using namespace std;
const int base = 31;
const long long mod = 1e5+3;
int n, k; 

bool check(int len, long long *hashS, long long *pow) {
    unsigned pass[mod] = {0};
    for (int i = 0; i <= n-len; i++) {
        int j = i + len;
        if (++pass[(hashS[j]-hashS[i]*pow[len]+mod*mod)%mod] >= k) return true;
    }
    return false;
}

signed main() {
    scanf("%d%d", &n, &k);
    char s[n+1]; scanf("%s", s+1);
    long long pow[n+1], hashS[n+1]; pow[0] = 1; hashS[0] = 0;
    for (int i = 1; i <= n; i++)
        pow[i] = (pow[i-1]*base)%mod,
        hashS[i] = (hashS[i-1]*base+s[i]-'a'+1)%mod;
    int l = 1, r = n, mid, ans; while (l <= r) 
        if (check(mid = (l+r)>>1, hashS, pow)) 
            ans = mid, 
            l = mid+1;
        else r = mid -1;
    printf("%d", ans);
}
