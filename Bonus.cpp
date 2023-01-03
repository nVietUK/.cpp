#include <bits/stdc++.h>

using namespace std;

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Bonus.inp", "r", stdin);
    freopen("Bonus.out", "w", stdout);
#endif
    
    unsigned n, p, in;
    cin >> n >> p;

    vector<unsigned> cot; cot.clear();
    for (unsigned i = 0; i < n && cin >> in; i++)
        cot.push_back(in);

    vector<unsigned> cottrai (cot.begin(), cot.begin() + p - 1);
    vector<unsigned> cotphai (cot.begin() + p, cot.end());
    reverse(cottrai.begin(), cottrai.end());

    long long chinh = cot[p-1];
    long long trai = 0; for (auto& pos : cottrai)
        trai += pos + 1;
    long long phai = 0; for (auto& pos : cotphai)
        phai += pos + 1;

    long long c = (trai) ? ((phai) ? cottrai.size() : 0) + chinh + phai : INT_MAX;
    phai += (phai) ? ((trai) ? cotphai.size() : 0) + chinh + trai : INT_MAX;
    trai += c;

    cout << min(trai, phai);
}