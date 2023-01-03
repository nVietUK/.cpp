#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("DEMBUOC.INP", "r", stdin);
    freopen("DEMBUOC.OUT", "w", stdout);

    unsigned T; cin >> T; while (T--) {
        long long X, Y; cin >> X >> Y;
        long long 
                i = Y-X, 
                n = floor(sqrt(i)),
                d = i - pow(n, 2);
        
        if (!d)
            cout << 2*n-1;
        else 
        if ((1 <= d) && (d <= n))
            cout << 2*n;
        else 
            cout << 2*n+1;
        cout << "\n";
    }
}