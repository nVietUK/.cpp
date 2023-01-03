#include <bits/stdc++.h>
#define pytago(x, y) sqrt(pow(x, 2) + pow(y, 2))

using namespace std;

int w, h;
vector<vector<pair<char, int>>> ta;
priority_queue<int, vector<int>, greater<int>> ha;
vector<int> co = {-1, 1, 0, 0}; vector<int> ro = { 0, 0,-1, 1};

int duong(pair<int, int> fs)
{
    int x, y; 
    queue<pair<pair<int, int>, int>> ra; ra.push(make_pair(fs, 0)); while (ha.size()) ha.pop();
    vector<vector<bool>> vi(ta.size()); for (auto& a : vi) a.resize(ta[0].size(), false);
    vi[fs.first][fs.second] = true;
    while (ra.size())
    {
        for (unsigned i = 0; i < 4; i++)
            if (
                ((x = ra.front().first.first+ro[i]) < h) &&
                ((y = ra.front().first.second+co[i]) < w) &&
                (x >= 0) && (y >= 0) && (!vi[x][y])
            )
            {
                if (ta[x][y].first != '1') 
                {
                    ra.push(make_pair(make_pair(x, y), ra.front().second+1));
                    ta[x][y].second += ra.front().second+1;
                    vi[x][y] = true;
                }
                if (ta[x][y].first == '4')
                    ha.push(ta[x][y].second);
            }
        ra.pop();
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("rbgh.inp", "r", stdin);
    freopen("rbgh.out", "w", stdout);
    
    int fx, fy, sx, sy, ou = 0; char in;
    cin >> w >> h;
    while (ta.size() < h)
    {
        ta.push_back({});
        while ((ta[ta.size()-1].size() < w) && (cin >> in))
        {
            ta[ta.size()-1].push_back(make_pair(in, 0));
            if (in == '2') { sx = ta.size()-1; sy = ta[ta.size()-1].size()-1; }
            if (in == '3') { fx = ta.size()-1; fy = ta[ta.size()-1].size()-1; }
        }
    }
    duong(make_pair(sx, sy)); cout << ha.top() << "\n";
    duong(make_pair(fx, fy)); cout << ha.top() + ta[sx][sy].second;
}