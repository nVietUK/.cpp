#include <bits/stdc++.h>
#define ONLINE false
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<unsigned, unsigned> uu;
typedef pair<int, int> ii;

#define convert(in, function) transform(in.begin(), in.end(), in.begin(), [](unsigned char c) { return function(c); });
template <typename T> struct wrapped_array {
    wrapped_array(T* first, T* last)
        : begin_ {first}, end_ {last} {};
    wrapped_array(T* first, std::ptrdiff_t size)
        : wrapped_array {first, first + size} {};
    T* begin() const noexcept { return begin_; }; T* begin_;
    T* end() const noexcept { return end_; }; T* end_;
};

#define chk(curr, l, r) ((curr >= l) && (curr < r))
typedef pair<unsigned, ii> uii;
short **arr; unsigned N, M; bool **pass; 

bool up(const ii &in, unsigned &value) {
    
}
bool down(const ii &in, unsigned &value) {
    
}
bool right(const ii &in, unsigned &value) {
    
}
bool left(const ii &in, unsigned &value) {
    
}

void check(unsigned x, unsigned y) {
    queue<ii> q; q.push(ii(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second; q.pop();

        if (pass[x][y])
            continue;
        pass[x][y] = true;

        if (chk(x-1, 0, N) && up(x-1, y))      q.push(ii(x-1, y)); 
        if (chk(x+1, 0, N) && down(x+1, y))    q.push(ii(x+1, y)); 
        if (chk(y-1, 0, M) && left(x, y-1))   q.push(ii(x, y-1)); 
        if (chk(y+1, 0, M) && right(x, y+1))  q.push(ii(x, y+1));
    }
}

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen("laudai.out", "w", stdout);
    #endif
    freopen("laudai.inp", "r", stdin);
#endif

    cin >> N >> M ;
    arr = new short*[N]; for (auto&& e : wrapped_array<short*>(arr, N)) { 
        e = new short[M]; for (auto&& e0 : wrapped_array<short>(e, M)) 
            cin >> e0; 
    };
    **pass = new bool*[N]; for (auto&& e : wrapped_array<bool*>(pass, N)) { e = new bool[M]; for (auto&& e1 : wrapped_array<bool>(e, M)) e1 = false; }

    unsigned cou = 0; for (unsigned i = 0; i < N; i++)
        for (unsigned j = 0; j < M; j++) 
            if (pass[i][j]) 
            { check(i, j); cou++; }
}