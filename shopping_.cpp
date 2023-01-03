#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef pair<unsigned, unsigned> uu;

template <typename T> struct wrapped_array {
    wrapped_array(T* first, T* last)
        : begin_ {first}, end_ {last} {}
    wrapped_array(T* first, std::ptrdiff_t size)
        : wrapped_array {first, first + size} {}

    T* begin() const noexcept { return begin_; }
    T* end() const noexcept { return end_; }

    T* begin_;
    T* end_;
};

unsigned n;
ull d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#if (__linux__ || _WIN32)
    freopen("shopping.inp", "r", stdin);
    freopen("shopping.out", "w", stdout);
#endif

    cin >> n >> d;
    for (unsigned i = 1; i <= n; i++) {
        cin >> a[i];
    }
}