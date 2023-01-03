#include <bits/stdc++.h>

using namespace std;

map<int, vector<pair<int, int>>> ta;

pair<vector<int>, int> duong(int fs, int ls)
{
    queue<pair<vector<int>, int>> ba; pair<vector<int>, int> ou; ou.second = 0;
    ba.push({}); ba.front().first.push_back(fs); ba.front().second = 0;
    while (ba.size())
    {
        if (
            (ba.front().first[ba.front().first.size()-1] == ls) &&
            (
                (ba.front().second < ou.second) ||
                (!ou.second)
            )
        ) ou = ba.front();
        for (auto& i : ta[ba.front().first[ba.front().first.size()-1]])
            if (find(ba.front().first.begin(), ba.front().first.end(), i.first) == ba.front().first.end())
            {
                ba.push({}); ba.back().first = ba.front().first; ba.back().first.push_back(i.first); ba.back().second = ba.front().second + i.second;
            }
        ba.pop();
    }
    return ou;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
#endif    
    int n, m, k, u, v, t;
    cin >> n >> m >> k;
    while (m-- && (cin >> u) && (cin >> v) && (cin >> t))
    {
        ta[u].push_back(make_pair(v, t));
        ta[v].push_back(make_pair(u, t));
    }
    while (n-- && (cin >> u) && (cin >> v) && (cin >> t))
    {
        auto ou = duong(v, t);
        if (u)
        {
            cout << ou.first.size() << " ";
            for (auto& a : ou.first)
                cout << a << ' ';
        }
        else 
            cout << ou.second << " ";
        cout << "\n";
    }
}