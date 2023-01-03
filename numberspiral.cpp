#include <ios>
#include <iostream>

using namespace std;

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

    long long t, x, y; cin >> t; while (t-- && cin >> x >> y) {
        if (x < y) {
            if (y%2) cout << y*y-x+1;
            else cout << (y-1)*(y-1)+x;
        }
        else {
            if (x%2) cout << (x-1)*(x-1)+y;
            else cout << x*x-y+1;
        }
        cout << '\n';
    }
}
