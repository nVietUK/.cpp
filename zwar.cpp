#include <bits/stdc++.h>

using namespace std;

vector<string> ta;
vector<int> ro = {-1, 0 , 1, 0, 1, 1,-1,-1};
vector<int> co = {0 , -1, 0, 1, 1,-1, 1,-1};
int n, m;
int quet(int x, int y)
{
    int l = 0;
    ta[x][y] = '0';
    queue<pair<int, int>> wa; wa.push(make_pair(x, y));
    while (wa.size())
    {
        l++; int i = 8; while (i--)
            if (
                (
                    ((x = wa.front().first+ro[i]) < n) &&
                    ((y = wa.front().second+co[i]) < m) &&
                    ((x) >= 0) &&
                    ((y) >= 0)
                ) &&
                (ta[x][y] == '1')
            )
            {
                wa.push(make_pair(x, y));
                ta[x][y] = '0';
            }
        wa.pop();
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("zwar.inp", "r", stdin);
    freopen("zwar.out", "w", stdout);

    long long test=1;
    cin>>test;
    while(test--)
    {
        int o = 0, b = 0;
        cin >> n >> m; char in;
        ta.clear(); 
        ta.resize(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; (j < m) && (cin >> in); j++)
                ta[i].push_back(in);
        for (int i = 0; i < n; i++)
            for (int j = 0; (j < m); j++)
                if (ta[i][j]=='1')
                    { b = max(b, quet(i, j)); o++; };
        cout << o << " " << b << endl;
    }
    return 0;
}
