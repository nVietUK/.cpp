#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

signed main() {
    unsigned n, cur = 0, t = 0; scanf("%u", &n); vector<pair<unsigned, unsigned>> arr(n); while (n--) 
        scanf("%u%u", &arr[n].second, &arr[n].first);
    sort(arr.begin(), arr.end());
    for (auto e : arr) 
        if (e.second >= cur) 
            cur = e.first, t++;
    printf("%u", t);
}
