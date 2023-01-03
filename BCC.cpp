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

set<pair<unsigned, char>> setchar;
map<char, int> chartable;

bool arr['z'+1]['z'+1]; string temp_string = "";
void makemap(string curr) {
    int i; if (temp_string != "") {
        for (i = 0; (i < temp_string.size()) && (i < curr.size()); i++) 
            if ((temp_string[i] != curr[i]))
                break;
        arr[curr[i]][temp_string[i]] = true;
    }
    temp_string = curr;
    for (i = 0; i < curr.size(); i++) 
        chartable[curr[i]] = 1;
}

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen("BCC.out", "w", stdout);
    #endif
    freopen("BCC.inp", "r", stdin);
#endif

    string inp;
    unsigned n; cin >> n; for (unsigned i = 0; i < n; i++) 
    { cin >> inp; makemap(inp); }
    for (char a = 'a'; a <= 'z'; a++)
        for (char b = 'a'; b <= 'z'; b++)
            for (char c = 'a'; c <= 'z'; c++)
                arr[b][c] = (arr[b][a] && arr[a][c]) || arr[b][c];
    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++)
            chartable[a] += arr[a][b];
        if (chartable[a])
            setchar.insert(make_pair(chartable[a], a));
    }
    int cou = 0; inp = ""; for (set<pair<unsigned, char>>::iterator i = setchar.begin(); i != setchar.end(); i++) {
        if (i->first == 1)
            cou++;
        if ((prev(i)->first == i->first) && (i->first != 1))
        { cout << "!"; return 0; }
        inp += i->second;
    }
    if (cou > 1) cout << "?";
    else cout << inp;
}