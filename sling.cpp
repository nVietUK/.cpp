#include <bits/stdc++.h>
#define pp pair<unsigned, unsigned>
#define py(a, b) pow(a.x - b.x, 2) + pow(a.y - b.y, 2)

using namespace std;

struct 
{
    int x, y;
    unsigned r;
} plan[5001];

// communist variables
    int x, y;
    unsigned r;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("sling.inp", "r", stdin);
    freopen("sling.out", "w", stdout);
#endif
    
    unsigned t; cin >> t; while (t--)
    {
        unsigned n; cin >> n;
        for (unsigned i = 1; i <= n && cin >> x >> y >> r; i++)
            plan[i] = {x, y, r};
        cin >> x >> y;

        priority_queue<pp, vector<pp>, greater<pp>> wa; bool _a[n+1]; 
        memset(_a, false, sizeof(_a));
        bool vi[n+1], run = true; memset(vi, false, sizeof(vi));
        for (unsigned i = 1; i <= n; i++)
        {
            if (abs(y - plan[i].y) <= plan[i].r)
            { wa.push(pp(1, i)); vi[i] = true; }
            if (abs(x - plan[i].y) <= plan[i].r)
                _a[i] = true;
        }
        while (wa.size())
        {
            auto curr = wa.top(); wa.pop();
            if (_a[curr.second])
            { run = false; cout << curr.first << "\n"; break; }
            for (unsigned i = 1; i <= n; i++)
            {
                auto length = py(plan[curr.second], plan[i]);
                auto Rs     = pow(plan[curr.second].r + plan[i].r, 2);
                if (i != curr.second && length <= Rs && !vi[i])
                {
                    wa.push({curr.first + 1, i});
                    vi[i] = true;
                }
            }
        }
        if (run) cout << -1 << "\n";
    }
}