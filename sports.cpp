#include <bits/stdc++.h>

using namespace std;

map<unsigned, vector<unsigned>> ta;
map<unsigned, pair<unsigned, unsigned>> vi;
unsigned n, m, k, t, u, v;

stack<unsigned> dt;
void duong(unsigned pos)
{
    vi[pos].first = vi[pos].second = ++k; dt.push(pos);
    for (auto a : ta[pos])
    {
        if (vi.find(a) != vi.end())
        {   if (vi[a].first)
                vi[pos].second = min(vi[pos].second, vi[a].first);
        }
        else 
        {   duong(a);
            if (vi[a].second)
                vi[pos].second = min(vi[pos].second, vi[a].second);
        }
    }
    if (vi[pos].first == vi[pos].second)
    {   do 
        {   t = dt.top(); dt.pop();
            vi[t].first = vi[t].second = 0;
        } while (t != pos);
        v++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("sports.inp", "r", stdin);
    freopen("sports.out", "w", stdout);
    
    cin >> n >> m >> k;
    while (m-- && (cin >> t >> u >> v))
        if (k <= v)
            ta[t].push_back(u);
    k = 0; v = 0; while (n--) 
        if (vi.find(n+1) == vi.end()) duong(n+1);
    cout << v;
}