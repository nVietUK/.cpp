#include <bits/stdc++.h>
#define ONLINE false
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<unsigned, unsigned> uu;
typedef pair<int, int> ii;
typedef unsigned short us;

#define convert(in, function) transform(in.begin(), in.end(), in.begin(), [](unsigned char c) { return function(c); });
template <typename T> struct wrapped_array {
    wrapped_array(T* first, T* last)
        : begin_ {first}, end_ {last} {}
    wrapped_array(T* first, std::ptrdiff_t size)
        : wrapped_array {first, first + size} {}
    T* begin() const noexcept { return begin_; } T* begin_;
    T* end() const noexcept { return end_; } T* end_;
};

us **lengthXtoY, N, M, K;
bool *Free;
int *X, *Xmin, Lmin, L;

void readTable() {
    us k = K; vector<ii> q; int x, y; while (K--) {
        cin >> x >> y;
        for (unsigned i = 0; i < q.size(); i++) 
            lengthXtoY[q.size()][i] = lengthXtoY[i][q.size()] = abs(x - q[i].first) + abs(y - q[i].second);
        lengthXtoY[q.size()][q.size()] = min(abs(N-x+1), min(min(x, abs(M-y+1)), y));
        q.push_back(uu(x, y));
    }
    K = k;
}

void Optimize() {
    if (L + lengthXtoY[X[K-1]][X[K-1]] + lengthXtoY[X[0]][X[0]] < Lmin) 
        Lmin = L + lengthXtoY[X[K-1]][X[K-1]] + lengthXtoY[X[0]][X[0]];
    L += lengthXtoY[X[K-1]][X[0]];
    for (unsigned i = 1; i < K; i++)
        if (L - lengthXtoY[X[i-1]][X[i]] + lengthXtoY[X[i-1]][X[i-1]] + lengthXtoY[X[i]][X[i]] < Lmin) 
            Lmin = L - lengthXtoY[X[i-1]][X[i]] + lengthXtoY[X[i-1]][X[i-1]] + lengthXtoY[X[i]][X[i]];
}

void Run(int i) {
    int j, k;
    for (j = 1; j < K; j++) {
        if (lengthXtoY[X[i-1]][j] && Free[j]) {
            X[i] = j;
            Free[j] = false;
            L += lengthXtoY[X[i-1]][j];
            if (i < K-1) { Run(i+1); }
            else if (lengthXtoY[X[i]][X[0]]) { Optimize(); }
            Free[j] = true;
            L -= lengthXtoY[X[i-1]][j];
        }
    }
}

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen("tuoicay.out", "w", stdout);
    #endif
    freopen("tuoicay.inp", "r", stdin);
#endif

    cin >> N >> M >> K; 
    Free = new bool[K]; for (auto&& e : wrapped_array(Free, K)) e = true;
    X = new int[K]; for (auto&& e : wrapped_array(X, K)) e = 0;
    Xmin = new int[K]; for (auto&& e : wrapped_array(Xmin, K)) e = 0;
    X[0] = 0; Free[0] = false;
    lengthXtoY = new us*[N]; Lmin = INT_MAX; L = 0;
    for (auto&& e : wrapped_array(lengthXtoY, N)) {
        e = new us[M]; 
        for (auto&& e0 : wrapped_array(e, M))
            e0 = us(0);
    }
    readTable();
    Run(1);
    cout << Lmin;
}