#include <bits/stdc++.h>

using namespace std;

vector<vector<unsigned>> ta;
void cong(unsigned last, unsigned now)
{
    if ((now) && (ta[0][last] == ta[0][now]))
    {
        ta[0][now]++;
        cong(now, ta[ta.size()-1][now]);
    }
}

void solve()
{
    unsigned n, k, in, im, tl = 0;
    cin >> n >> k;

    vector<unsigned> ut(0), ou(0);
    ta.resize(0); ta.resize(n+2, {}); n--; 
    while ((n--) && (cin >> in) && (cin >> im))
    {
        ta[in].insert(upper_bound(ta[in].begin(), ta[in].end(), im), im);
        ta[im].insert(upper_bound(ta[im].begin(), ta[im].end(), in), in);
        ut.push_back(in);
        ut.push_back(im);
    }

    while (ut.size())
    {
        ta[0].resize(0); ta[ta.size()-1].resize(0);
        ta[0].resize(ta.size()-1, 0); ta[ta.size()-1].resize(ta.size()-1, 0);
        vector<unsigned> wa; wa.resize(0); wa.push_back(ut[0]);
        im = 1; in = 0;
        while (wa.size())
        {
            tl = 0;
            for (auto a : ta[wa[0]])
            {
                if ((in & (1 << a)) == 0)
                {
                    wa.push_back(a);
                    ta[ta.size()-1][a] = wa[0];
                    tl++;
                }
            }
            if ((in & (1 << wa[0])) == 0) cong(0, wa[0]);
            in = in | (1 << wa[0]);
            wa.erase(wa.begin());
        }
        sort(ta[0].begin(), ta[0].end());
        ou.push_back(ta[0].end() - upper_bound(ta[0].begin(), ta[0].end(), k));
        ut.erase(ut.begin());
    }
    sort(ou.begin(), ou.end());
    if (!ou.size()) ou.push_back(0);
    cout << ou[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
#endif

    long long test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}