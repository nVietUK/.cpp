#include <bits/stdc++.h>
#define ONLINE false
#define DEBUG true
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

int main() {
    ios_base::sync_with_stdio(DEBUG);
    cin.tie(NULL); cout.tie(NULL);
#if ((__linux__ || _WIN32) && !ONLINE && !ONLINE_JUDGE)
    freopen("test.inp", "r", stdin);
    if (!DEBUG) freopen("test.out", "w", stdout);
#endif

    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;

            cout << left << hex << showbase << nouppercase;
            cout << (long long) A << endl;

            cout.precision(2);
            cout << showpos << fixed << setfill('_') << setw(15) << right;
            cout << B << endl;

            cout.precision(9);
            cout << noshowpos << uppercase << scientific;
            cout << C << endl;
    }
}