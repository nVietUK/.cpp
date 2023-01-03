#include <bits/stdc++.h>
#define limax 100000 + 1

using namespace std;

// communist variables
    unsigned ta[limax], in[limax], bo[limax], ou[limax];
    set<unsigned> nhanh[limax];

bool vi[limax]; unsigned ti = 0;
void bfs(unsigned pos, unsigned par)
{
    in[pos] = ++ti; bo[pos] = par; vi[pos] = true;
    for (auto& a : nhanh[pos])
    {
        if (!vi[a])
        {
            nhanh[a].erase(pos);
            bfs(a, pos);
            ta[pos] = min(ta[pos], ta[a]);
        }
        else 
            ta[pos] = min(ta[pos], in[a]);
    }
}

void dfs(unsigned n, unsigned chay)
{
    auto par = bo[n]; vi[n] = true;
    if (par && ta[n] >= in[n])
        chay++;
    ou[n] += chay;
    for (auto& a : nhanh[n])
        if (!vi[a])
            dfs(a, chay);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("FREQPATH.INP", "r", stdin);
    freopen("FREQPATH.out", "w", stdout);
#endif
    
    unsigned n, m, u, v; cin >> n >> m; memset(ta, -1, sizeof(ta));
    while (m-- && cin >> u >> v)
    {
        nhanh[u].insert(v); nhanh[v].insert(u);
    }

    memset(vi, false, sizeof(vi));
    bfs(n, 0); 
    memset(vi, false, sizeof(vi));
    dfs(n, 0);
    
    cin >> m;
    while (m-- && cin >> u)
        cout << ou[u] << "\n";
}