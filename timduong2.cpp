#include <bits/stdc++.h>

using namespace std;

map<unsigned, vector<unsigned>> ta;
vector<long long> vo;

unsigned n, m, x; long long y;
queue<pair<pair<unsigned, long long>, unsigned>> wa;
map<unsigned, bool> vi;
int duyet(unsigned x, long long y)
{
    while (wa.size()) wa.pop();
    wa.push(make_pair(make_pair(x, 1), vo[x])); vi.clear();
    while (wa.size())
    {
        x = wa.front().first.first; n = wa.front().second;
        long long u = wa.front().first.second;
        if (n > y) return u;
        vi[x] = true; 
        wa.pop();
        for (auto& a : ta[x])
            if (vi.find(a) == vi.end())
            {
                wa.push(make_pair(make_pair(a, u+1), n+vo[a]));
                vi[a] = true;
            }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("timduong.inp", "r", stdin);
    freopen("timduong.out", "w", stdout);
    
    cin >> n >> m; vo.resize(n+1);
    for (unsigned i = 0; i < n; i++)
        cin >> vo[i+1];
    for (unsigned i = 1; (i < n) && (cin >> x) && (cin >> y); i++)
    {
        ta[x].push_back(y);
        ta[y].push_back(x);
    }
    while (m-- && (cin >> x) && (cin >> y))
        cout << duyet(x, y) << "\n";
}