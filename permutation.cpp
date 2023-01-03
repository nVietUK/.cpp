#include <ios>
#include <iostream>

using namespace std;

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

    unsigned i, n; cin >> n; 
    if (n == 1) cout << 1;
    else if (n < 4) cout << "NO SOLUTION";
    else {
        for (i = 2; i <= n; i+=2) cout << i << " ";
        for (i = 1; i <= n; i+=2) cout << i << " ";
    }
}
