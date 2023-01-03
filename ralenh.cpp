#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("ralenh.inp", "r", stdin);
    freopen("ralenh.out", "w", stdout);
    
    unsigned short m, n;
    double in;
    cin >> n >> m;
    while (m--)
    {
        vector<bool> ck(n, true);
        vector<double> ta(0);
        stack<double> wa;
        unsigned short st = 1;
        while ((ta.size() < n) && (cin >> in)) ta.push_back(in);

        for (double& a : ta)
        {
            if (ck[a])
            {
                ck[a] = false;
                for (; st < a; st++)
                    if (ck[st])
                    {
                        ck[st] = false; 
                        wa.push(st);
                    }
                st++;
            }
            else 
            {
                if (wa.top() != a)
                {
                    cout << "No" << endl;
                    break;
                }
                else wa.pop();
            }
        }
        if (!(wa.size())) cout << "Yes" << endl;
    }
}