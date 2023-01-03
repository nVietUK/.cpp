#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;
#define notTERMINAL true
#define FILENAME ""
#define intf "%d"
#define floatf "%f"
int c;

signed main() {
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    scanf(intf, &c);
    if (c&1) {
        if (c > 1) printf("YES\n" intf " " intf, (c+1)/2, (c+1)/2-1);
        else printf("NO");
    }
    else {
        if (c%4) printf("NO");
        else printf("YES\n" intf " " intf, (c/4)+1, (c/4)-1);
    }
}