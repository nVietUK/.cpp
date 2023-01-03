#include <bits/stdc++.h>
#define ONLINE false
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<unsigned, unsigned>uu;

#define convert(in, function) transform(in.begin(), in.end(), in.begin(), [](unsigned char c) { return function(c); });
template <typename T> struct wrapped_array {
    wrapped_array(T* first, T* last)
        : begin_ {first}, end_ {last} {}
    wrapped_array(T* first, std::ptrdiff_t size)
        : wrapped_array {first, first + size} {}
    T* begin() const noexcept { return begin_; } T* begin_;
    T* end() const noexcept { return end_; } T* end_;
};
unsigned N, top; 
unsigned hamiltonctl(int pos, int prev, unsigned **arr, bool *in_path, int deep, int *pathMin) {
    if (deep == N) { pathMin[deep-1] = pos; return arr[pos][top]; }

    unsigned minVal = INT_MAX; int *path = new int[N];
    for (int v = 0; v < N; v++) {
        if ((arr[pos][v] > 0) && !in_path[v]) {
            in_path[v] = true;
            unsigned currVal = hamiltonctl(v, pos, arr, in_path, deep+1, path) + arr[pos][v];
            if (currVal < minVal) {
                minVal = currVal;
                for (unsigned i = 0; i < N; i++) pathMin[i] = path[i];
                pathMin[deep-1] = pos;
            }
            in_path[v] = false;
        }
    }
    return minVal;
};
bool hamilton(unsigned **arr) {
    int *pathMin = new int[N], *ou = new int[N]; bool *in_path = new bool[N];
    for (unsigned i = 0; i < N; i++) { in_path[i] = false; }

    unsigned minVal = INT_MAX; 
    for (top = 0 ; top < N; top++) {
        in_path[top] = true;
        unsigned curr = hamiltonctl(top, top, arr, in_path, 1, pathMin);
        in_path[top] = false;

        if (curr < minVal) {
            minVal = curr;
            for (unsigned i = 0; i < N; i++) ou[i] = pathMin[i];
        }
    }

    cout << minVal << "\n";
    for (unsigned i = 0; i < N; i++)
        cout << ou[i]+1 << " ";
    cout << ou[0]+1;
    return true;
}

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen("hamiltonNN.out", "w", stdout);
    #endif
    freopen("hamiltonNN.inp", "r", stdin);
#endif

    cin >> N; unsigned **arr = new unsigned*[N];
    for (auto&& e : wrapped_array(arr, N)) {
        e = new unsigned[N];
        for (auto& e0 : wrapped_array(e, N))
            cin >> e0;
    }
    hamilton(arr);
}