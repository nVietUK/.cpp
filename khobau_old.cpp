#include <bits/stdc++.h>
#define liMax 100000 + 1
#define pp pair<unsigned, unsigned>

using namespace std;

// communist variables
    char ch[liMax];
    bool it[256], vi[liMax];
    vector<unsigned> ta[liMax];
    unsigned n;

pair<unsigned, unsigned> run(unsigned& in)
{
    priority_queue<pp, vector<pp>, greater<pp>> q; q.push(make_pair(it[ch[in]], in));
    pair<unsigned, unsigned> ou;
    while (q.size())
    {
        ou = q.top(); q.pop();
        vi[ou.second] = true;
        for (auto& tp : ta[ou.second])
            if (!vi[tp])
                q.push(make_pair(ou.first + it[ch[tp]], tp));
    }
    return ou;
}

void install()
{
    memset(it, false, sizeof(it));
    it['a'] = it['e'] = it['o'] = it['i'] = it['u'] = true;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("khobau.inp", "r", stdin);
    freopen("khobau.out", "w", stdout);
#endif
    
    unsigned u, v; install();
    cin >> n; 
    memset(ta, {}, sizeof(ta));

    for (unsigned i = 1; i <= n; i++)
        cin >> ch[i]; 
    for (unsigned i = 1; i < n; i++)
    {
        cin >> u >> v;
        ta[u].push_back(v);
        ta[v].push_back(u);
    }
    if (n-1)
    {
        u = 0; pair<unsigned, unsigned> maxU = make_pair(0, 0);
        memset(vi, false, sizeof(vi));
        for (unsigned i = 1; i <= n; i++)
            if (!vi[i])
                maxU = max(maxU, run(i));
        memset(vi, false, sizeof(vi));
        cout << run(maxU.second).first;
    }
}