#include <bits/stdc++.h>
#define ppp pair<unsigned, float>

using namespace std;

struct pp
{
    float dau, cuoi;
};

bool myless(pp& __x, pp& __y) 
{ 
    if (__x.dau == __y.dau)
        return __x.cuoi < __y.cuoi;
    return __x.dau < __y.dau;
};

float r, p; float hpy(float& w2, float& r)
{ 
    return sqrt(pow(r, 2) - pow(w2, 2)); 
}
float hdau(float& w2, float& r)
{
    float temp = p - hpy(w2, r);
    if (temp < 0)
        return 0;
    return temp;
}
float hcuoi(float& w2, float& r)
{
    return p + hpy(w2, r);
}

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("tuoicay.inp", "r", stdin);
    freopen("tuoicay.out", "w", stdout);
#endif
    
    float l, w; unsigned n;
    while (cin >> n >> l >> w)
    {
        w /= 2; vector<pp> voi;

        for (unsigned i = 0; i < n; i++)
        {
            cin >> p >> r;
            voi.push_back({hdau(w, r), hcuoi(w, r)});
        } voi.push_back({l, l}); voi.push_back({0, 0});
        sort(voi.begin(), voi.end(), myless);

        int trace[n+2];
        for (int i = voi.size()-1; i >= 0; i--)
        {
            auto j = 0; while (voi[j].cuoi < voi[i].dau) j++;
            trace[i] = (i != j) ? j : 0;
        }

        unsigned j = 0; n++; 
        if (trace[n])
        {
            do { n = trace[n]; j++; } while (n);
            cout << j-1 << "\n";
        }
        else cout << -1;
    }
}