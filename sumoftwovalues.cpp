#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

map<unsigned, unsigned> t;

signed main() {
    unsigned n, k, y; scanf("%u%u", &n, &k); vector<unsigned> arr(n); for (unsigned i = 0; i < n && scanf("%u", &arr[i]); i++);
    for (unsigned i = 0; i < n; i++) {
        if (t.count(k-arr[i])) { printf("%u %u", i+1, t[k-arr[i]]); return 0; };
        t[arr[i]] = i+1;
    }
    printf("%s", "IMPOSSIBLE");
}
