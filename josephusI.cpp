#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n, a = 1, b = 0; scanf("%d", &n); while (n > 0) {
        for (int i = 2; i <= n; i += 2)
            printf("%d ", a*i+b);
        if (n&1) printf("%d ", a+b), b += a;
        else b -= a;
        a <<= 1, n >>= 1;
    }
}
