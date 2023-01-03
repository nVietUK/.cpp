#include <bits/stdc++.h>

using namespace std;

long long s(int& x)
{
    if (x)
    {
        return (pow(-1, x + 1) * x) + s(--x);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int x; cin >> x;

    cout << s(x);
}