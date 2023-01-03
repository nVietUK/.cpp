#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

signed main() {
    unsigned n, x, y; vector<pair<unsigned, int>> arr; scanf("%u", &n); while (n--) {
        scanf("%u%u", &x, &y);
        arr.push_back(make_pair(x, 1)); 
        arr.push_back(make_pair(y, -1));
    }

    sort(arr.begin(), arr.end()); int sum = 0, ans = 0;
    for (auto e : arr) 
        sum += e.second, ans = max(ans, sum);

    printf("%d", ans);
}
