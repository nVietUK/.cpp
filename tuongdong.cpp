#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("tuongdong.inp", "r", stdin);
    freopen("tuongdong.out", "w", stdout);
    
    unsigned in, sn;
    while (cin >> in) if (in) 
    {
        set<set<unsigned>> ma;
        while (in--)
        {
            unsigned l = 5; set<unsigned> ou;
            while (l-- && (cin >> sn)) ou.insert(sn);
            ma.insert(ou);
        }
        cout << ma.size() << "\n";
    }
}