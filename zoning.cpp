#include <stdio.h>
#include <algorithm>

using namespace std;
#define notTERMINAL true
#define FILENAME ""
#define intf "%d"

void solve() {
    int n, x, in; scanf(intf intf, &n, &x);
    int arr[1000000000+1];fill(arr, arr+x+1, 0); arr[0] = 1;
    while (n--) {
        scanf(intf, &in);
        for (int i = x; i >= in; i--)
            arr[i] += arr[i-in];
    }
    printf(intf "\n", arr[x]);
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

    int t; scanf(intf, &t); while (t--) solve();
}