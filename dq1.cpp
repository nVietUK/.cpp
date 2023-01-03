#include <bits/stdc++.h>

using namespace std;

long long luythua(int& x, int& y)
{
    if (y)
    {
        return luythua(x, --y) * x;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int x, y; cin >> x >> y;

    cout << luythua(x,y);
}