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
char **arr;
ii start, stop;

map<char, unsigned> charvalue;

void init() {
    charvalue['A'] = charvalue['K'] = 0;
    charvalue['B'] = 1; charvalue['C'] = 2;
    charvalue['D'] = 3; charvalue['E'] = 7;
    charvalue['F'] = 8; charvalue['G'] = 6;
    charvalue['H'] = 7; charvalue['I'] = 8;
    charvalue['J'] = 9;
}

#define charchk(x, y) ((x != y) && (x != 'A') && (x != 'K'))
bool down(const ii &in, unsigned &value);
bool up(const ii &in, unsigned &value) {
    char 
        curr = arr[in.first][in.second], 
        next = arr[in.first-1][in.second]; 
    bool out = true;
    if (curr > next) {
        out = down(ii(in.first-1, in.second), value);
        value = charvalue[next];
        return (out && charchk(next, 'J'));
    }
    if ((curr == 'C') || (curr == 'G')) { out = (next != 'E') && (next != 'I'); }
    if ((curr == 'D') || (curr == 'I')) { out = (next != 'G') && (next != 'J'); }
    value = charvalue[next];
    return (out && charchk(next, 'J'));
}
bool down(const ii &in, unsigned &value) {
    char 
        curr = arr[in.first][in.second], 
        next = arr[in.first+1][in.second]; 
    bool out = true;
    if (curr > next) {
        out = up(ii(in.first+1, in.second), value);
        value = charvalue[next];
        return (charchk(next, 'H') && out);
    }
    if ((curr == 'B') || (curr == 'G')) { out = (next != 'D') && (next != 'I'); }
    if ((curr == 'E') || (curr == 'I')) { out = (next != 'G') && (next != 'C'); }
    value = charvalue[next];
    return (charchk(next, 'H') && out);
}

bool left(const ii &in, unsigned &value);
bool right(const ii &in, unsigned &value) {
    char 
        curr = arr[in.first][in.second], 
        next = arr[in.first][in.second+1]; 
    bool out = true;
    if (curr > next) {
        out = left(ii(in.first, in.second+1), value);
        value = charvalue[next];
        return (charchk(next, 'G') && out);
    }
    if ((curr == 'D') || (curr == 'H')) { out = (next != 'B') && (next != 'J'); }
    if ((curr == 'E') || (curr == 'J')) { out = (next != 'C') && (next != 'H'); }
    value = charvalue[next];
    return (charchk(next, 'G') && out);
}
bool left(const ii &in, unsigned &value) {
    char 
        curr = arr[in.first][in.second], 
        next = arr[in.first][in.second-1]; 
    bool out = true;
    if (curr > next) {
        out = right(ii(in.first, in.second-1), value);
        value = charvalue[next];
        return (charchk(next, 'I') && out);
    }
    if ((curr == 'B') || (curr == 'J')) { out = (next != 'D') && (next != 'H'); }
    if ((curr == 'C') || (curr == 'H')) { out = (next != 'J') && (next != 'E'); }
    value = charvalue[next];
    return (charchk(next, 'I') && out);
}

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen("robot.out", "w", stdout);
    #endif
    freopen("robot.inp", "r", stdin);
#endif

    unsigned N, M; cin >> N >> M >> start.first >> start.second >> stop.first >> stop.second;
    start.first--; start.second--; stop.first--; stop.second--;
    arr = new char*[N]; for (auto&& e : wrapped_array<char*>(arr, N)) { 
        e = new char[M]; for (auto&& e0 : wrapped_array<char>(e, M)) 
        cin >> e0; 
    };
    bool **pass = new bool*[N]; for (auto&& e : wrapped_array(pass, N)) { e = new bool[M]; for (auto&& e1 : wrapped_array(e, M)) e1 = false; }

    init(); try {
        priority_queue<uii, vector<uii>, greater<uii>> q; q.push(uii(charvalue[arr[start.first][start.second]], start));
        while (q.size()) {
            unsigned currval = q.top().first;
            ii currpos = q.top().second; q.pop();

            if (pass[currpos.first][currpos.second])
                continue;
            pass[currpos.first][currpos.second] = true;

            if (stop == currpos) { throw currval; }

            unsigned value = 0;
            if (chk(currpos.first-1, 0, N) && up(currpos, value)) { q.push(uii(currval + value, ii(currpos.first-1, currpos.second))); }
            if (chk(currpos.first+1, 0, N) && down(currpos, value)) { q.push(uii(currval + value, ii(currpos.first+1, currpos.second))); }
            if (chk(currpos.second-1, 0, M) && left(currpos, value)) { q.push(uii(currval + value, ii(currpos.first, currpos.second-1))); }
            if (chk(currpos.second+1, 0, M) && right(currpos, value)) { q.push(uii(currval + value, ii(currpos.first, currpos.second+1))); }
        }
    }
    catch (unsigned out) { cout << out; }
}