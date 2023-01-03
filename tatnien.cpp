#include <bits/stdc++.h>
#define pp pair<unsigned, unsigned>
#define limax 1001

using namespace std;

// communist variables
    unsigned ta[limax][limax];
    vector<unsigned> go[limax];
    unsigned ti[limax];

void bfs(unsigned& pos)
{
    memset(ti, -1, sizeof(ti)); ti[pos] = 0;
    bool vi[limax]; memset(vi, false, sizeof(vi));
    priority_queue<pp, vector<pp>, greater<pp>> wa; wa.push(pp(0, pos));
    while (wa.size())
    {
        auto curr = wa.top(); wa.pop(); vi[curr.second] = true;
        for (auto& temp : go[curr.second])
            if (!vi[temp])
            {
                auto temp2 = curr.first + ta[curr.second][temp];
                if (temp2 < ti[temp])
                {
                    wa.push(pp(curr.first + ta[curr.second][temp], temp));
                    ti[temp] = temp2;
                }
            }        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("tatnien.inp", "r", stdin);
    freopen("tatnien.out", "w", stdout);
#endif
    
    unsigned n, m, x, a, b, y;
    cin >> n >> m >> x; memset(ta, -1, sizeof(ta));
    while (m--)
    {
        cin >> a >> b >> y;
        if (ta[a][b] == (unsigned)-1) 
        {
            go[a].push_back(b);
            go[b].push_back(a);
        }
        ta[a][b] = ta[b][a] = min(y, ta[a][b]);
    }
    bfs(x);
    unsigned ou = 0; for (unsigned i = 1; i <= n; i++)
        if (i != x)
            ou = max(ou, ti[i]);
    cout << ou * 2;
}