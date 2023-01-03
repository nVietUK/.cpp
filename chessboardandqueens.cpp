#include <algorithm>
#include <cstdio>
#include <numeric>
#include <stdio.h>
#include <algorithm>

using namespace std;

signed main() {
    char c; bool cb[8][8]; for (unsigned i = 0; i < 8; i++) { 
        for (unsigned j = 0; j < 8; j++) {
            scanf("%c", &c); cb[i][j] = (c == '.');
        }
        scanf("%c", &c);
    }
    unsigned ar[9], ou = 0; iota(ar, ar+9, 0);
    do { bool valid = true;
        for (unsigned i = 0; i < 8 && valid; i++)
            valid = valid && cb[i][ar[i]];
        bool al[15]; fill(al, al+15, false);
        for (unsigned i = 0; i < 8 && valid; i++) {
            valid = valid && !al[i+ar[i]];
            al[i+ar[i]] = true;
        }
        fill(al, al+15, false);
        for (unsigned i = 0; i < 8 && valid; i++) {
            valid = valid && !al[i+7-ar[i]];
            al[i+7-ar[i]] = true;
        }
        ou += valid;
    } while(next_permutation(ar, ar+8));
    printf("%u", ou);
}
