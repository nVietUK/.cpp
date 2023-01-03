#include <bits/stdc++.h>

using namespace std;

map<unsigned, vector<unsigned>> ta;
vector<bool> ba;
unsigned n, m, k, u, v, t;

unsigned dfs (unsigned p)
{
    if (ba[p]) return 0;
    ba[p] = true;
    stack<unsigned> wa; wa.push(p);
    while (wa.size())
    {
        u = wa.top(); wa.pop();
        if (ta.find(u) != ta.end())
            for (auto& a : ta[u])
                if (!ba[a])
                    { wa.push(a); ba[a] = true; }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("giaosua.inp", "r", stdin);
    freopen("giaosua.out", "w", stdout);
    
    cin >> n >> m >> k;
    ba.resize(n+1, false);
    while (m-- && (cin >> u) && (cin >> v) && (cin >> t))
        if (t >= k)
        {
            ta[u].push_back(v);
            ta[v].push_back(u);
        }
    t = 0; while (n--)
        t += dfs(n+1);
    cout << t;
}