#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, k; scanf("%d", &n);
    multiset<int> ans;
    for (int i = 0; i < n && scanf("%d", &k); i++) {
        auto it = ans.upper_bound(k);
        if (it == ans.end()) ans.insert(k);
        else 
            ans.erase(it),
            ans.insert(k);
    }
    printf("%lu", ans.size());
}
