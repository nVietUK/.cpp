#include <stdio.h>
#include <algorithm>

using namespace std;

signed main() {
    int m[6][6], in; for (int i = 1; i <= 5; i++) for (int j = 1; j <= 5; j++) {
        scanf("%d ", &in);
        if (in == 1) 
            printf("%d", abs(i-3)+abs(j-3));
    }
}
