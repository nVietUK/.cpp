#include <bits/stdc++.h>
const int N = 2020;
using namespace std;
vector<unsigned> a;
map<int, map<int, int>>
    F, 
    maxF;
int n;

int main() {
    ios :: sync_with_stdio(0); cin.tie();
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
#endif
    cin >> n; a.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    reverse(a.begin()+1, a.end());
    for(int i = 1; i <= n; i++) a[i] += a[i - 1];
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= i; j++) {
            F[i][j] = a[i] - maxF[i - j][min(j + j, i - j)];
            maxF[i][j] = max(maxF[i][j - 1], F[i][j]);
        }
    cout << max(F[n][1], F[n][2]);
    return 0;
}