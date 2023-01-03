#include <bits/stdc++.h>

using namespace std;

struct sinhnhat
{ unsigned x, y, bn, pn, bl, pl; };

// communist variables
    vector<sinhnhat> ta;
    unsigned n, m;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("sinhnhat.inp", "r", stdin);
    freopen("sinhnhat.out", "w", stdout);

    cin >> n >> m; ta.resize(n);

    while (n--)
    { cin >> ta[n].x >> ta[n].y >> ta[n].bn >> ta[n].pn >> ta[n].bl >> ta[n].pl; }
    unsigned Low = 0,  High = m;

    while (Low < High){
        unsigned mid = Low + (High - Low + 1) / 2, to = 0;

        for (auto& a : ta){
            unsigned LuongBotCan = a.x * mid - a.y, Best = INT_MAX;
            int SoBichCan = int(ceil(LuongBotCan / double(a.bn)));

            for (int j = 0; j <= SoBichCan; j++)
            {
                int Item = j * a.bn, Sum = (LuongBotCan >= Item) ? int(ceil((LuongBotCan - Item)/ double(a.bl))) : 0;
                Best = min(Best, j*a.pn + Sum * a.pl);
            }
            if (Best > m || to + Best > m){
                to = m+1;
                break;
            }
            else to += Best;
        }
        if (to <= m)
            Low = mid;
        else 
            High = mid - 1;
    }
    cout << Low;
    return 0;
}