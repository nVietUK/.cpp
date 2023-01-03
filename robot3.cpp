#include <bits/stdc++.h>

using namespace std;

struct robot3
{
    pair<int, int> di;
    string pa = "";
};

vector<int> ro = {1, 0, 0, -1};
vector<int> co = {0, -1, 1, 0};
vector<char> c = {'D', 'L', 'R', 'U'};

// communist variable
    int n, m, a, b, q, x, y;
    vector<vector<bool>> ta;

vector<vector<bool>> ck;
string bfs()
{   ck.clear(); ck.resize(n); for (auto& a : ck) a.resize(m, false); 
    queue<robot3> wa; while (wa.size()) wa.pop(); wa.push({make_pair(a, b), ""});
    while (wa.size())
    {
        auto cur = wa.front(); wa.pop();
        if ((cur.di.first < 0) || (cur.di.first >= n) || 
            (cur.di.second < 0) || (cur.di.second >= m) ||
            (ck[cur.di.first][cur.di.second]) || (!ta[cur.di.first][cur.di.second])
        ) continue;
        ck[cur.di.first][cur.di.second] = true;
        if ((cur.di.first == x) &&
            (cur.di.second == y))
            return cur.pa;
        for (unsigned i = 0; i < 4; i++)
            wa.push({make_pair(cur.di.first + ro[i], cur.di.second + co[i]), cur.pa + c[i]});
    }
    return "Impossible";
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("robot3.inp", "r", stdin);
    freopen("robot3.out", "w", stdout);
    
    cin >> n >> m; ta.clear(); char s;
    for (unsigned i = 0; (i < n); i++)
    {   ta.push_back({});
        for (unsigned j = 0; (j < m) && (cin >> s); j++)
            ta[i].push_back(s == '.');
    }

    cin >> q;
    while (q-- && (cin >> a >> b >> x >> y))
    if (ta[--a][--b] && ta[--x][--y]){
        cout << bfs() << "\n";
    }
}