#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int a, b; scanf("%d %d", &a, &b);
    printf("%lld", a*(b+1) + b*(a+1));
}