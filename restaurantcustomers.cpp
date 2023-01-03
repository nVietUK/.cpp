#include <stdio.h>
#include <algorithm>

using namespace std;

struct customer {
    unsigned a, b;
} lis[200000];
unsigned man[200000];

signed main() {
    unsigned n; scanf("%u", &n); for (unsigned i = 0; i < n && scanf("%u%u", &lis[i].a, &lis[i].b); i++);
    sort(lis, lis+n, [] (customer a, customer b) { return a.a < b.a; });
    for (unsigned i = 0; i < n; i++) {

    }
}
