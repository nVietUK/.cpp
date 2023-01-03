#include <stdio.h>
#include <algorithm>

#define file "test"
#define type int
#define typef "%d "

using namespace std;

signed main() {
#if nVietUK
    freopen(file".INP", "r", stdin);
    #if not LOCAL
        freopen(file".OUT", "w", stdout);
    #endif
#endif
    type x, a, b, c, d;scanf(typef, &x);
    while (true) {
        x++;
        a = x/1000, b = x/100%10, c = x/10%10, d = x%10;
        if (a != b && a != c && a != d && b != c && b != d && c != d) {
            printf(typef, x);
            break;
        }
    }
}
