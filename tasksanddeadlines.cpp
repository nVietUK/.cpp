#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long n, x, y, ans = 0, c = 0; scanf("%lld", &n);
    vector<pair<long long, long long>> v; 
    for (long long i = 0; i < n && scanf("%lld%lld", &x, &y); i++) 
        v.push_back({x,y});
    sort(v.begin(), v.end());
    for (long long i = 0; i < n; i++) 
        c += v[i].first, ans += v[i].second - c;
    printf("%lld", ans);
}
