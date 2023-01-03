#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

struct block { int h, c, a;
    block(int h = 0, int c = 0, int a = 0) : h(h), c(c), a(a) {};
    inline bool operator< (const block &x) {return this->a < x.a; }
} blocks[401];

signed main() {
    int k, i, t; scanf("%d", &k); for (int i = 1; i <= k && scanf("%d%d%d", &blocks[i].h, &blocks[i].a, &blocks[i].c); i++);
    sort(blocks+1, blocks+k+1);

    long long f[2][40001]; memset(f, 0, sizeof f); f[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        t = i % 2; memcpy(f[t], f[1-t], sizeof f[1-t]);
        for (int j = 1; j <= blocks[i].c; j++) {
            int p = blocks[i].h*j;
            for (int k = p; k <= blocks[i].a; k++) 
                if (f[1-t][k-p] == 1)
                    f[t][k] = 1;
        }
    }
    for (i = blocks[k].a; i >= 0; i--) 
        if (f[t][i] == 1) 
            break;
    printf("%d", i);
}
