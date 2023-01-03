#include <stdio.h>
#include <algorithm>
#include <climits>

using namespace std;

signed main() {
    int n, x, y, z, ox = 0, oy = 0, oz = 0; scanf("%d", &n); while (n-- && scanf("%d %d %d", &x, &y, &z)) 
        ox += x, oy += y, oz += z;
    if (oz == oy && oy == ox && ox == 0)
        printf("YES");
    else 
        printf("NO");
}
