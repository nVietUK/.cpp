#include <bits/stdc++.h>

using namespace std;

unsigned bay(unsigned cao, vector<unsigned>& day);

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("domdom.inp", "r", stdin);
    freopen("domdom.out", "w", stdout);
    
    unsigned n, h, in;
    cin >> n >> h;

    vector<unsigned> ca(0), la(0);
    while (((ca.size() + la.size()) < n) && (cin >> in)) 
        if ((ca.size() + la.size()) % 2)
            ca.push_back(in);
        else 
            la.push_back(in);
    sort(ca.begin(), ca.end()); sort(la.begin(), la.end());

    auto q = h; 
    vector<unsigned> ou((n/2)+1, 0);
    while (h--) ou[bay(q - h, ca) + bay(h+1, la)]++;
    for (q = 0; q < ou.size(); q++)
        if (ou[q])
        {
            cout << q << " " << ou[q];
            break;
        }
}

unsigned bay(unsigned cao, vector<unsigned>& day)
{
    return day.size() - (lower_bound(day.begin(), day.end(), cao) - day.begin());
}