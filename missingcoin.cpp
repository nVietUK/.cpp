#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

signed main() {
    unsigned n; scanf("%u", &n); vector<unsigned long long> arr(n+1), dp(n+1);
    for (unsigned i = 1; i <= n && scanf("%llu", &arr[i]); i++); 
    dp[0] = 1; sort(arr.begin()+1, arr.end());
    for (unsigned i = 1; i <= n; i++) {
        if (dp[i-1] < arr[i]) 
            return printf("%llu", dp[i-1]), 0;
        dp[i] = dp[i-1] + arr[i];
    }
    printf("%llu", dp[n]);
}
