#include <bits/stdc++.h>
#define pytago(x, y) sqrt(pow(x, 2) - pow(y, 2))

using namespace std;

// communist variables
    vector<double> ta, bi(0);

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("xepvong.inp", "r", stdin);
    freopen("xepvong.out", "w", stdout);
    
    unsigned n; cin >> n; ta.resize(n);
    double ou = INT_MAX, tp;
    while (n--) cin >> ta[n];
    sort(ta.begin(),ta.end()); n = ta.size();
    do
    {
        tp = 0; bi.clear(); bi.resize(ta.size(), 0);
        bi[0] = ta[0];
        for (unsigned i = 0; i < n; i++)
            for (unsigned j = 0; j < i; j++)
                bi[i] = max(ta[i], bi[j] + pytago(ta[i]+ta[j], ta[i]-ta[j]));
        for (unsigned i = 0; i < n; i++)
            tp = max(tp, ta[i] + bi[i]);
        ou = min(tp, ou);
    } while (next_permutation(ta.begin(), ta.end()));
    cout << fixed << setprecision(3) << ou;
}