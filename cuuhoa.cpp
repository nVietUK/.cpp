#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("cuuhoa.inp", "r", stdin);
    freopen("cuuhoa.out", "w", stdout);
    
    int n, k;
    cin >> n >> k;

    if (n > k) { cout << n - k; return 0; }
    queue<pair<int, unsigned>> wa; wa.push(make_pair(n, 0));
    vector<bool> ba (k*2, false);
    while (wa.size())
    {
        if (!ba[n = wa.front().first])
        {
            ba[n] = true;
            if (n == k) { cout << wa.front().second; return 0; };
            if (n-1 >= 0) wa.push(make_pair(n-1, wa.front().second+1));
            wa.push(make_pair(n+1, wa.front().second+1));
            if (n*2 <= k) wa.push(make_pair(n*2, wa.front().second+1));
        }
        wa.pop();
    }
    cout << 0;
}