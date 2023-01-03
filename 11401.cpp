#include <bits/stdc++.h>
#define ONLINE false
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<unsigned, unsigned> uu;

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        freopen("11401.out", "w", stdout);
    #endif
    freopen("11401.inp", "r", stdin);
#endif

    ull dp[1000001], s[1000001], curr = 0;
    dp[2] = dp[3] = s[2] = s[3] = 0; 
    for(int i = 5; i <= 1000000; i++) {
        if (i%2==0) curr++;
        s[i] = s[i-1]+curr;
        dp[i] = dp[i-1]+s[i];
    }
    int n;
    while(cin >> n && n >= 3)
        cout << dp[n] << "\n";
}