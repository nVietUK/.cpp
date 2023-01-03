#include <bits/stdc++.h>
#define limax 400 + 1
#define pp pair<unsigned, unsigned>

using namespace std;

// communist variables
    set<pp> from[limax];    
    unsigned ta[limax][limax], n;

void run(unsigned pos)
{
    bool vi[limax]; memset(vi, false, sizeof(vi));
    priority_queue<pp, vector<pp>, greater<pp>> wa; wa.push({0, pos}); auto curr = wa.top();
    while (wa.size())
    {
        curr = wa.top(); wa.pop(); vi[curr.second] = true;
        for (auto& temp2 : from[curr.second])
            if (!vi[temp2.second])
            {
                ta[pos][temp2.second] = min(ta[pos][temp2.second], curr.first + temp2.first);
                wa.push({curr.first + temp2.first, temp2.second});
            }
    }
}

void chay(unsigned pos)
{
    bool vi[limax]; memset(vi, false, sizeof(vi)); vi[pos] = true;
    priority_queue<pp, vector<pp>, greater<pp>> wa; wa.push({0, pos}); auto curr = wa.top();
    while (wa.size())
    {
        curr = wa.top(); wa.pop(); vi[curr.second] = true;
        for (auto& temp2 : from[curr.second])
            if (!vi[temp2.second])
            {
                ta[pos][temp2.second] = max(ta[pos][temp2.second], curr.first + temp2.first);
                wa.push({curr.first + temp2.first, temp2.second});
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("banhang.inp", "r", stdin);
    freopen("banhang.out", "w", stdout);
#endif
    
    unsigned m, x, u, v, l;
    cin >> n >> m >> x;
    while (m-- && cin >> u >> v >> l)
        from[u].insert(pp(l, v));
    
    thread mainThread[limax];

    memset(ta, -1, sizeof(ta));
    for (unsigned i = 1; i <= n; i++)
        mainThread[i] = thread(run, i);
    unsigned ou = 0;
    for (unsigned i = 1; i <= n; i++)
        mainThread[i].join();
    for (unsigned i = 1; i <= n; i++)
    {
        if (i != x)
            ou = max(ou, ta[x][i] + ta[i][x]);
    }
    cout << ou << "\n";

    memset(ta, -1, sizeof(ta));
    for (unsigned i = 1; i <= n; i++)
        mainThread[i] = thread(run, i);
    unsigned pos = 0; ou = -1;
    for (unsigned i = 1; i <= n; i++)
        mainThread[i].join();
    for (unsigned i = 1; i <= n; i++)
    {
        unsigned temp2U = 0;
        for (unsigned j = 1; j <= n; j++)
            if (j != i)
                temp2U = max(ta[i][j] + ta[j][i], temp2U);
        if (ou > temp2U)
        { ou = temp2U; pos = i; }
    }
    cout << pos << "\n";
}