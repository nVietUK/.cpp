#include <bits/stdc++.h>

using namespace std;

bool ck(double in);

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("soxau.inp", "r", stdin);
    freopen("soxau.out", "w", stdout);
    
    short n;
    while (cin >> n)
    {
        if (!n) break;
        unsigned long long s = 1;
        while (n--) 
        {
            while (!ck(s++));
            cout << endl;
        }
    }
}

bool ck(double in)
{
    if ((unsigned)in != in) return false;
    if (in == 1) return true;
    if (ck(in/2))
    {
        cout << 2 << " ";
        return true;
    }
    if (ck(in/3))
    {
        cout << 3 << " ";
        return true;
    }
    if (ck(in/5))
    {
        cout << 5 << " ";
        return true;
    }
    return false;
}