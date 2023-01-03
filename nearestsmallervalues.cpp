#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

signed main() {
    int n, x; scanf("%d", &n);
    vector<ii> v;
    for (int i = 1, ans; i <= n && scanf("%d", &x); i++, ans = 0) {
        while (v.size())
            if (v.back().first >= x) v.pop_back();
            else {ans=v.back().second; break;}
        printf("%d ", ans); v.push_back({x, i});
    }
}
