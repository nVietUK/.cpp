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

unsigned x; 



unsigned run() {
    cout << x << " : ";
    unsigned count = 0;
    for (auto& e : prime) {
        if (e*e > x)
            return count + (x != 1);
        count += ((x % e)==0);
        while (!(x%e)) x /= e;
    }
}

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen("10699.out", "w", stdout);
    #endif
    freopen("10699.inp", "r", stdin);
#endif

    init(1000000); while (cin >> x) {
        if (!x) return 0;

        cout << run() << "\n";
    }
}