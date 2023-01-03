#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

signed main() {
    int n, m, in; scanf("%d%d", &n, &m); multiset<int> h;
    for (unsigned i = 0; i < n && scanf("%d", &in); i++) h.insert(in);

    while (m-- && scanf("%d", &in)) {
        auto i = h.upper_bound(in);
        if (i!=h.begin()) { printf("%d\n", *(--i)); h.erase(i); } else printf("-1\n");
    }
}
