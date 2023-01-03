#include <bits/stdc++.h>
#define ONLINE false
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<unsigned, unsigned>uu;

#define convert(in, function) transform(in.begin(), in.end(), in.begin(), [](unsigned char c) { return function(c); });
template <typename T> struct dyArray {
    dyArray(T* first, T* last)
        : begin_ {first}, end_ {last} {}
    dyArray(T* first, std::ptrdiff_t size)
        : dyArray {first, first + size} {}
    T* begin() const noexcept { return begin_; } T* begin_;
    T* end() const noexcept { return end_; } T* end_;
};

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen("phepchia.out", "w", stdout);
    #endif
    freopen("phepchia.inp", "r", stdin);
#endif

    ull m, n; while (cin >> m >> n) {
        map<int, int> mp; for (unsigned i = 2; i*i <= n; i++)
            while (n%i==0) mp[i]++, n/=i;
        if (n>1) mp[n]++;
        bool ok = true;
        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            int v = it->first, c = it->second, t = m, cnt = 0;
            while (t >= v) cnt+= t/v, v*=v;
            ok &= (cnt >= c);
        }
        cout << (ok ? "yes" : "no") << "\n";
    }
}