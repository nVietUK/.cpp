#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    long long n, s=0, mx=0, in; scanf("%lld", &n);
    for (int i = 0; i < n && scanf("%lld", &in); i++) 
        mx = max(mx, in), s+=in;
    printf("%lld", max(2*mx, s));
}
