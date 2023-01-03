#include <bits/stdc++.h>

using namespace std;

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("dance.inp", "r", stdin);
    freopen("dance.out", "w", stdout);
#endif
    
    unsigned n, m, in; cin >> n >> m;
    priority_queue<unsigned> nam, nu;
    while (n-- && cin >> in)
        nam.push(in);
    while (m-- && cin >> in)
        nu.push(in);
    
    in = 0; while (nam.size() && nu.size())
    {
        if (nam.top() > nu.top())
        { in++; nam.pop(); nu.pop(); }      
        else 
            nu.pop();
    }
    cout << in;
}