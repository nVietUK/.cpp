#include <stdio.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

int main() {
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s; int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        s.insert(i);

    int ind = k % n; while (n--) {
        auto y = s.find_by_order(ind);
        printf("%d ", *y); s.erase(y);
        if (n) ind = (ind%n + k) % n;
    }
}
