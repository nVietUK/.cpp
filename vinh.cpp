#include <bits/stdc++.h>
#define limax 300 + 1
#define mpp pair<int, int>
#define pp pair<int long long, mpp>

using namespace std;

// communist variables
    unsigned long long ou[limax][limax];

bool vi[limax][limax]; 
priority_queue<pp, vector<pp>, greater<pp>> wa; 
int col[] = {0, 0, 1, -1},
    row[] = {1, -1, 0, 0};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("vinh.inp", "r", stdin);
    freopen("vinh.out", "w", stdout);
#endif
    memset(ou, -1, sizeof(ou));


    // read input
    unsigned n, m, x, y, b, d;
    cin >> n >> m >> x >> y >> b >> d;
    unsigned diem[m][n];
    for (auto& hang : diem)
        for (auto& cot : hang)
            cin >> cot;

    wa.push(pp(0, mpp(x, y)));

    memset(vi, false, sizeof(vi));
    memset(ou, -1, sizeof(ou));
    while (wa.size())
    {
        auto length = wa.top().first; auto pos = wa.top().second; wa.pop(); 
        if (vi[pos.first][pos.second])
            continue;
        if (pos.first == b && pos.second == d)
            break;
        vi[pos.first][pos.second] = true;
        for (unsigned i = 0; i < 4; i++)
        {
            auto gox = pos.first + row[i];
            auto goy = pos.second + col[i];
            if (gox < 0 || goy < 0 || gox >= n || goy >= m)
                continue;
            if (ou[gox][goy] > diem[gox][goy] + length)
            {
                ou[gox][goy] = diem[gox][goy] + length;
                wa.push(pp(ou[gox][goy], mpp(gox, goy)));
            }
        }
    }
    cout << ou[b][d];
}