#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef vector<pair<int, int>> vii;

int main() {
    int x, n, in; scanf("%d%d", &n, &x);
    vii v; for (int i = 0; i < n && scanf("%d", &in); i++)
        v.push_back({in,i+1});
    sort(v.begin(), v.end()); map<int, vii> mp;
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++)
        mp[v[i].first+v[j].first].push_back({v[i].second, v[j].second});
    for (auto i : mp) {
        int y = x-i.first;
        auto z = mp.find(y);
        if (z != mp.end()) 
            for (auto j : z->second)
                for (auto k : i.second)
                    if (j.first != k.first && j.first != k.second && j.second != k.first && j.second != k.second) {
                        printf("%d %d %d %d", j.first, j.second, k.first, k.second);
                        return 0;
                    }
    }
    printf("IMPOSSIBLE");
}
