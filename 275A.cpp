#include <stdio.h>
#include <algorithm>

#define tong(x, y, z, t, c) !((x+y+z+t+c)%2)

using namespace std;

signed main() {
    int aa, ab, ac, ba, bb, bc, ca, cb, cc;
    scanf("%d%d%d%d%d%d%d%d%d", &aa, &ab, &ac, &ba, &bb, &bc, &ca, &cb, &cc);

    printf("%d%d%d\n%d%d%d\n%d%d%d",
        tong(0, ab, ba, 0, aa), tong(0, aa, ac, bb, ab), tong(0, 0, ab, bc, ac),
        tong(aa, bb, ba, ca, 0), tong(bb, ab, ba, bc, cb), tong(ac, bb, bc, cc, 0),
        tong(ba, ca, cb, 0, 0), tong(bb, ca, cb, cc, 0), tong(bc, cb, cc, 0, 0)
    );
}