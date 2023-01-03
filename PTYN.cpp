#include <bits/stdc++.h>

using namespace std;

// communist variables
    unsigned maxI[100];
    unsigned n, m;
    unsigned cot[100], hang[100];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("PTYN.inp", "r", stdin);
    freopen("PTYN.out", "w", stdout);
#endif
    
    cin >> n >> m; unsigned in;
    memset(maxI, 0, sizeof(maxI));
    for (unsigned i = 0; i < m; i++)
    {
        unsigned minJ = -1;
        for (unsigned j = 0; j < n; j++)
        {
            cin >> in;
            if (minJ > in)
            {
                minJ = in;
                hang[i] = j;
            }
            if (maxI[j] < in)
            {
                maxI[j] = in;
                cot[j] = i;
            }
        }
    }
    for (unsigned i = 0; i < m; i++)
        for (unsigned j = 0; j < n; j++)
            if (hang[i] == j && cot[j] == i)
            {
                cout << "(" << i+1 << "," << j+1 << ")";
                return 0;
            }
    cout << "Khong co phan tu yen ngua";
}