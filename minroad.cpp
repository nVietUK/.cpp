#include <stdio.h>
#include <algorithm>
#include <climits>

using namespace std;
#define notTERMINAL true
#define FILENAME ""
#define intf "%d"

struct minroad
{
    int dis=0, typ=0;
    inline bool operator<(const minroad &a) {
        return this->dis < a.dis;
    }
};


signed main() {
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    int n, a, b; scanf(intf intf intf, &n, &a, &b);
    int x=0, y=0, res=INT_MAX;
    minroad arr[n];
    for (int i = 0; i < n; i++) 
        scanf(intf intf, &arr[i].dis, &arr[i].typ);
    sort(arr, arr+n); int pos1[n], pos2[n];
    for (int i = 0; i < n; i++) {
        if (arr[i].typ == 1)
            pos1[x++] = arr[i].dis;
        else pos2[y++] = arr[i].dis;
        if (x >= a && y >= b) 
            res = min(res, arr[i].dis - min(pos1[x-a], pos2[y-b]));
    }
    printf(intf, (res != INT_MAX) ? res : -1);
}