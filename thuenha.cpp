#include <bits/stdc++.h>
#define limax 10000 + 1
#define pp pair<unsigned, unsigned>

using namespace std;

struct thuenha
{
    unsigned current, traveled;
};

struct myless : public binary_function<thuenha, thuenha, bool>
    {
      _GLIBCXX14_CONSTEXPR
      bool
      operator()(const thuenha& __x, const thuenha& __y) const
      { return __x.traveled > __y.traveled; }
    };

// communist variables
    vector<unsigned> places;
    unsigned x, y, length[limax][limax];
    set<pp> from[limax];    

unsigned dj(unsigned start)
{
    priority_queue<thuenha, vector<thuenha>, myless> wait;
    bool vi[limax]; memset(vi, false, sizeof(vi));
    wait.push({start, 0}); unsigned pos;
    while (wait.size())
    {
        auto curr = wait.top(); wait.pop();
        if (vi[curr.current])
            continue;
        vi[curr.current] = true;
        for (auto& pos : from[curr.current])
            if (length[start][pos.second] > curr.traveled + pos.first)
            {
                length[start][pos.second] = curr.traveled + pos.first;
                wait.push({pos.second, length[start][pos.second]});
            }
    }
    return pos;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("thuenha.inp", "r", stdin);
    freopen("thuenha.out", "w", stdout);
#endif
    
    unsigned n, m, p, in;
    cin >> n >> m >> p;
    while (p-- && cin >> in)
        places.push_back(in);
    while (m-- && cin >> x >> y >> in)
    {
        from[x].insert(pp(in, y));
        from[y].insert(pp(in, x));
    }
    memset(length, -1, sizeof(length));
    for (auto& place : places)
        dj(place);
    sort(places.begin(), places.end()); p = places.size()-1;
    unsigned go = INT_MAX, first, last;
    do
    {
        unsigned tempU = 0;
        for (unsigned i = 0; i < p; i++)
            tempU += length[places[i]][places[i+1]];
        if (tempU < go)
        {
            go = tempU;
            first = places[0];
            last = places[p];
        }
    }
    while (next_permutation(places.begin(), places.end()));
    unsigned ou = INT_MAX;
    for (unsigned i = 1; i <= n; i++)
        if (find(places.begin(), places.end(), i) == places.end())
            ou = min(ou, go + length[first][i] + length[last][i]);
    cout << ou;
}