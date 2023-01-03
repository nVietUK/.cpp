#include <bits/stdc++.h>
#define limax 100000 + 1
#define pp pair<unsigned long long, unsigned>

using namespace std;

// communist variables
    set<pp> diem[limax];
    unsigned long long ou[limax];
    unsigned n;

bool vi[limax]; 
priority_queue<pp, vector<pp>, greater<pp>> wa; 
void bfs()
{
    memset(vi, false, sizeof(vi));
    while (wa.size())
    {
        auto curr = wa.top(); wa.pop(); 
        if (vi[curr.second])
            continue;
        vi[curr.second] = true;
        for (auto& temp2 : diem[curr.second])
            if (ou[temp2.second] > curr.first + temp2.first)
            {
                ou[temp2.second] = curr.first + temp2.first;
                wa.push({curr.first + temp2.first, temp2.second});                 
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("rbpath.inp", "r", stdin);
    freopen("rbpath.out", "w", stdout);
#endif
    memset(ou, -1, sizeof(ou));

    // read input
    unsigned m, u, v, l;
    cin >> n >> m;
    while (m-- && cin >> u >> v >> l)
    {
        diem[u].insert(pp(l, v)); 
        diem[v].insert(pp(l, u));       
    }
    cin >> m; 
    for (v = 0; v < m && cin >> u; v++)
    {
        wa.push(pp(0, u));
        ou[u] = 0;
    }
    bfs();
    for (v = 1; v <= n; v++)
        cout << ou[v] << "\n";
}