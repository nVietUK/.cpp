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

unsigned x, y, z;

unsigned run(const unsigned& x, unsigned const y, const unsigned& z) {
    if (!y) return 1;
    if (y % 2) 
        return (run(x, y-1, z) * (x%z)) % z;
    unsigned n = run(x, y/2, z);
    return (n*n) % z;
}

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen("374.out", "w", stdout);
    #endif
    freopen("374.inp", "r", stdin);
#endif

    while (cin >> x >> y >> z) {
        cout << run(x, y, z) << "\n";
    }
}