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
        freopen("10689.out", "w", stdout);
    #endif
    freopen("10689.inp", "r", stdin);
#endif

    ull a, b, n, m, arr[15001]; unsigned k, t; cin >> t; while (t--) {
        cin >> a >> b >> n >> m;
        arr[0]=a%10000, arr[1]=b%10000;
        for (int i=2; i <= 15000; i++)
            arr[i]=(arr[i-1]+arr[i-2])%10000;
        k = pow(10, m);
        cout << arr[n%15000]%k << "\n";
    }
}