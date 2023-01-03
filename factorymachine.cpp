#include <stdio.h>
#include <algorithm>

using namespace std;

long long package[200001], l = 1, r = 1e18, m, ou, n, k;
bool check(long long x) { unsigned long long ou = 0;
    for (long long i = 0; i < n; i++)
        ou += x / package[i];
    return ou >= k;
}

int main() {
    scanf("%lld %lld", &n, &k); 
    for (int i = 0; i < n && scanf("%lld", package+i); i++);
    while (l <= r) 
        if (check(m = (l+r)>>1)) 
            ou = m, r = m-1;
        else 
            l = m+1;
    printf("%lld", ou);
}
