#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

signed main() {
    int n, mid; long long ou = 0; scanf("%u", &n); vector<int> arr(n); for (unsigned i = 0; i < n && scanf("%u", &arr[i]); i++);
    sort(arr.begin(), arr.end());

    mid = (n%2) ? arr[n/2] : (arr[n/2] + arr[n/2-1])/2;

    for (unsigned i = 0; i < n; i++) 
        ou += abs(mid-arr[i]);
    printf("%lld", ou);
}
