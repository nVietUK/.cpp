#include <bits/stdc++.h>
#define ONLINE false
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<unsigned, unsigned>uu;

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen("sochia.out", "w", stdout);
    #endif
    freopen("sochia.inp", "r", stdin);
#endif

    unsigned t, u, l, r, kq; cin >> t; while (t--) {
        cin >> l >> r; u = INT_MIN;
        vector<bool> m (r-l+1, true);
        vector<int> uoc (r-l+1, true);
        for (ull i = 2; i*i <= r; i++) 
            for (ull j = max(i*i, (l+i-1)/i*i); j <= r; j+=i) {
                m[j-l] = false;
                uoc[j-l]+=2;
                if (j/i==i) uoc[j-l]--;
                if (uoc[j-l]>u) kq=j, u=uoc[j-l];
            }
        printf("Giua %d va %d, co so uoc nhieu nhat la %d.\n", l, r, kq, u+1);
    }
}