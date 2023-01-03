#include <bits/stdc++.h>

using namespace std;

struct di
{
    unsigned diem;
    vector<unsigned> last;
};
vector<di> vi;
vector<vector<unsigned>> ta;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("mangluoi.inp", "r", stdin);
    freopen("mangluoi.out", "w", stdout);
    
    unsigned n, m, k, in, im;
    cin >> n >> m >> k;

    ta.resize(n+1);
    
    while ((m--) && (cin >> in) && (cin >> im)) 
    {
        ta[in].insert(upper_bound(ta[in].begin(), ta[in].end(), im), im);
        ta[im].insert(upper_bound(ta[im].begin(), ta[im].end(), in), in);
    }

    while ((n--) && (cin >> in) && (cin >> im))
    {
        vi.resize(0);
        vi.push_back(di{in, {}});
        while (vi.size())
        {
            for (auto a : ta[vi[0].diem])
            {
                if (find(vi[0].last.begin(), vi[0].last.end(), a) != vi[0].last.end()) continue;
                if (a == im)
                {
                    cout << "Yes" << endl;
                    im = 0;
                    vi.resize(1);
                    break;
                }
                vi.push_back(di{a, vi[0].last});
                vi[vi.size()-1].last.push_back(vi[0].diem);
            }
            vi.erase(vi.begin());
        }
        if (im) cout << "No" << endl;
    }
}