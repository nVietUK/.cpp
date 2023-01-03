#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
ll *arr, *p1, *p2, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#if (__linux__ || _WIN32)
    freopen("shopping.inp", "r", stdin);
    freopen("shopping.out", "w", stdout);
#endif

    cin >> n >> d; 
    ll res = 0;
    arr = new ll[n+1]; p1 = new ll[n+1]; p2 = new ll[n+1];
    for (unsigned i = 1; i <= n; i++) {
        cin >> arr[i];
        if (i%2)    p1[i] = p1[i-1]+arr[i];
        else        p1[i] = p1[i-2]+(arr[i-1]*arr[i]);
        if (i>1) {
            if (i%2)p2[i] = p2[i-2]+(arr[i-1]*arr[i]);
            else    p2[i] = p2[i-1]+arr[i];
        }
        res += (arr[i] <= d);
    }

    for (unsigned i = 1; i <= n; i++) {
        auto pos = lower_bound(p1+1, p1+i+1, p1[i]-d) - (p1+1);
        if (((i-pos) % 2) && pos) pos++;
        res += (i-pos+1)/2 - ((i%2) && (pos != i));
    }
    for (unsigned i = 2; i <= n; i++) {
        auto pos = lower_bound(p2+2, p2+i+2, p2[i]-d) - (p2+2) + 1;
        if (((i-pos) % 2) && (pos!=1)) pos++;
        res += (i-pos+1)/2 - 1 + (i%2);
    }
    cout << res;
}