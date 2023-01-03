#include <bits/stdc++.h>

using namespace std;

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("dcln.inp", "r", stdin);
    freopen("dcln.out", "w", stdout);
#endif
    
    int n, in, sum = 0, ou = 0; cin >> n;
    while (n-- && cin >> in)
    {
        sum += in;
        ou = max(ou, sum);
        if (sum < 0) sum = 0;
    }
    cout << ou;
}