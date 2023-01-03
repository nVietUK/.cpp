#include <bits/stdc++.h>

using namespace std;
int i;
unsigned n, m; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("CC.INP", "r", stdin);
    freopen("CC.OUT", "w", stdout);

    cin >> n >> m;
    unsigned arr[n+1], bang[m+1], trac[m+1], ou[n+1];
    memset(bang, INT_MAX-3, sizeof(bang));
    memset(ou, 0, sizeof(ou));
    memset(trac, 0, sizeof(trac));
    for (i = 0; i < n; i++)
        cin >> arr[i+1];

    bang[0] = 0;
    for (unsigned j = 1; j <= m; j++)
        for (i = 1; i <= n; i++)
            if ((arr[i] <= j) && (bang[j-arr[i]]+1 < bang[j])){
                bang[j] = bang[j-arr[i]]+1;
                trac[j] = i;
            }
    if (!trac[m])
        cout << -1;
    else{
        cout << bang[m] << "\n"; 
        while (m){
            ou[trac[m]]++;
            m -= arr[trac[m]];
        }
        for (i = 1; i <= n; i++)
            cout << ou[i] << " ";
    }
}