#include <bits/stdc++.h>

using namespace std;

// communist variables
    vector<vector<bool>> ta;
    vector<int> bo;
    unsigned n, m, a, b; 

unsigned k = 0; vector<pair<unsigned, unsigned>> vi; vector<unsigned> pa;
void duong(unsigned pos)
{
    vi[pos].first = ++k; vi[pos].second = n+1; pa[pos] = true;
    for (unsigned a = 1; a <= n; a++)
        if (ta[pos][a])
        {
            if (pa[a])
                vi[pos].second = min(vi[pos].second, vi[a].first);
            else 
            {   
                bo[a] = pos; ta[pos][a] = ta[a][pos] = false; duong(a);
                vi[pos].second = min(vi[pos].second, vi[a].second);
            }
        }
}

unsigned ou1 = 0, ou2 = 0;
void chay()
{
    for (unsigned i = 1; i <= n; i++)
        if (bo[i] != -1)
        {
            if (vi[i].second >= vi[i].first)
            { ou1++; }
            pa[bo[i]]++;
        }
    for (unsigned i = 1; i <= n; i++)
        if (
            ((bo[i] == -1) && (pa[i] > 1)) ||
            ((bo[i] != -1) && (bo[bo[i]] != -1) && (vi[i].second >= vi[bo[i]].first))
        )
            ou2++;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("truyentin.inp", "r", stdin);
    freopen("truyentin.out", "w", stdout);
    
    cin >> n >> m; 

    ta.clear(); ta.resize(n+1); for (auto& a : ta) a.resize(n+1, false);
    while (m-- && (cin >> a >> b))
    {   ta[a][b] = ta[b][a] = true; }
    vi.clear(); vi.resize(n+1, make_pair(0, 0));
    pa.clear(); pa.resize(n+1, false);
    bo.clear(); bo.resize(n+1, 0);
    for (unsigned i = 1; i <= n; i++)
        if (!bo[i])
        {   bo[i] = -1; duong(i);}
    pa.clear(); pa.resize(n+1, 0);
    chay();
    cout << ou1 << ' ' << ou2;
}