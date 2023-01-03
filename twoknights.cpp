#include <ios>
#include <iostream>

using namespace std;

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    unsigned n; cin >> n; for (long long i = 1; i <= n; i++) cout << (i*i*(i*i-1))/2 - 4*(i-1)*(i-2) << '\n';
}
