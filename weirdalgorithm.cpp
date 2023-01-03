#include <ios>
#include <iostream>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long N; cin >> N; while (N != 1) {
        cout << N << ' '; if (N&1) N = N*3+1; else N /= 2;
    }
    cout << 1;
}
