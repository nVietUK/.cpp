#include <stdio.h>
#include <algorithm>

using namespace std;

signed main() {
    unsigned n, q, x, y; scanf("%u%u", &n, &q);

    char s[100001]; scanf("%s", s+1);
    while (q--) {
        scanf("%u%u", &x, &y); unsigned ou = 0;
        for (unsigned i = x; i < y; i++) 
            ou += (s[i] == '(' && s[i+1] == ')');
        if (ou >= 2) printf("2");
        else if (ou == 1) printf("1");
        else printf("0");
        printf("\n");
    }
}
