#include <bits/stdc++.h>

using namespace std;

// communist variables
    bool passed[500001];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("chepnhac.inp", "r", stdin);
    freopen("chepnhac.out", "w", stdout);
#endif
    
    vector<unsigned> ta {0}; memset(passed, false, sizeof(passed));
    unsigned n, in, maxUnsigned = 0; cin >> in >> n;
    while (cin >> in)
    {        
        unsigned j = ta.size(), temp2Unsigned; for (unsigned i = 0; i < j; i++)
            if ((temp2Unsigned = (in + ta[i])) <= n && !passed[temp2Unsigned])
            {
                ta.push_back(temp2Unsigned);
                maxUnsigned = max(maxUnsigned, temp2Unsigned);
                passed[temp2Unsigned] = true;
            }
    }
    cout << maxUnsigned;
}