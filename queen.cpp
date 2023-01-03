#include <bits/stdc++.h>
#define ONLINE false
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int>uu;
typedef unsigned short us;
typedef pair<unsigned, uu> uuu;

#define convert(in, function) transform(in.begin(), in.end(), in.begin(), [](unsigned char c) { return function(c); });
template <typename T> struct dyArray {
    dyArray(T* first, T* last)
        : begin_ {first}, end_ {last} {}
    dyArray(T* first, std::ptrdiff_t size)
        : dyArray {first, first + size} {}
    T* begin() const noexcept { return begin_; } T* begin_;
    T* end() const noexcept { return end_; } T* end_;
};

unsigned N, M;
us **arr;

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen("queen.out", "w", stdout);
    #endif
    freopen("queen.inp", "r", stdin);
#endif

    cin >> N >> M; vector<uuu> que;
    arr = new us*[N]; for (unsigned i = 0; i < N; i++) {
        arr[i] = new us[M]; for (unsigned j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j])
                que.push_back(uuu(arr[i][j], uu(i, j)));
        }
    }
    sort(que.begin(), que.end());

    arr[que.begin()->second.first][que.begin()->second.second] = 1;
    for (vector<uuu>::iterator i = next(que.begin()); i != que.end(); i++) {
        if ((abs(i->second.first - (i-1)->second.first) != abs(i->second.second - (i-1)->second.second)) && (i->second.first == (i-1)->second.first) && (i->second.second == (i-1)->second.second)) {
            cout << -1; return 0;
        }
        arr[i->second.first][i->second.second] = i - que.begin() +1;
    }
    for(auto&& e : dyArray<us*>(arr, N)) {
        for (auto&& e0 : dyArray<us>(e, M)) 
            cout << e0 << " ";
        cout << "\n";
    }
}