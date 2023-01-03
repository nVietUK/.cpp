#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;
#define notTERMINAL true
#define FILENAME ""
#define intf "%ld"

signed main() {
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    long int n, m, t;
    scanf(intf intf, &n, &m);
    long int arr[301]; for (int i = 0; i < n; i++) scanf(intf, arr+i);
    set<int> q; arr[n] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++)
            for (int z = j+1; z <= n; z++)
                if ((t = arr[i]+arr[j]+arr[z]) <= m)
                    q.insert(t);
        if (arr[i] <= m)
            q.insert(arr[i]);
    }
    printf(intf, q.size());
}