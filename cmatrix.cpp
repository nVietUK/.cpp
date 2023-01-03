#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("cmatrix.inp", "r", stdin);
    freopen("cmatrix.out", "w", stdout);
    
    int r, c, x, y;
    cin >> r >> c >> x >> y;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << max(abs(x-i), abs(y-j)) << " ";
        cout << endl;
    }
}