#include <bits/stdc++.h>

using namespace std;

unsigned short k, ou = 0;
vector<unsigned short> ch;
void dd(unsigned short& pos, vector<vector<unsigned short>>& ca)
{
    ch[pos]++;
    for (auto a : ca[pos]) dd(a, ca);
    if (ch[pos] == k) { ou++; ch[pos]++; }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("kehoach.inp", "r", stdin);
    freopen("kehoach.out", "w", stdout);
    
    unsigned short n, m, in;
    cin >> k >> n >> m;

    vector<unsigned short> ng;
    while ((ng.size() < k) && (cin >> in)) ng.push_back(in);

    vector<vector<unsigned short>> di(n+1);
    ch.resize(n+1, 0);

    while ((m--) && (cin >> n) && (cin >> in)) di[n].push_back(in);

    for (auto a : ng) dd(a, di);

    cout << ou;
}