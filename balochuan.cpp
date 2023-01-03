 #include <bits/stdc++.h>

using namespace std;

// genaral variable
    unsigned n, m, w, v;
    vector<pair<unsigned, unsigned>> ta;

vector<vector<unsigned long long>> luu;
unsigned long long chay()
{
    luu.resize(n+1); for (auto& a : luu) a.resize(m+1, 0);
    for (unsigned i = 1; i <= n; i++)
        for (unsigned j = 1; j <= m; j++)
            if (j >= ta[i].first)
                luu[i][j] = max(luu[i-1][j-ta[i].first] + ta[i].second, luu[i-1][j]);
            else 
                luu[i][j] = luu[i-1][j];
    return luu[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m; ta.clear(); ta.push_back(make_pair(0, 0));
    for (unsigned i = 1; (i <= n) && (cin >> w >> v); i++)
        ta.push_back(make_pair(w, v));   
    cout << chay();
}