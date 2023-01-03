#include <bits/stdc++.h>

using namespace std;

void solve()
{
    unsigned n, s, in;
    cin >> n;

    vector<vector<unsigned>> ta (n+1);
    for (unsigned i = 1; i <= n; i++)
    {
        auto& day = ta[i];
        cin >> s; while (s-- && (cin >> in)) day.push_back(in);
    }

    for (auto& a : ta)
    {
        auto b = 0;
        while (b <= (a.size()-1))
        {
            if (!a[b]) { a.erase(a.begin() + b); break; }
            if (ta[a[b]-1].size() == 0)
                a[b] = 0;
            b++;
        }
    }
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
