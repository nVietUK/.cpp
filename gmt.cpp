#include <stdio.h>
#include <algorithm>

using namespace std;
#define notTERMINAL true
#define FILENAME ""
#define intf "%d"

signed main() {
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    int h, m, a, b; scanf(intf intf intf intf, &h, &m, &a, &b);
    printf(intf " " intf, (48+h+(b-a))%24, m);
}