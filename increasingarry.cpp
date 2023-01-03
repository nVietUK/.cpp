#include <ios>
#include <iostream>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    unsigned long long N, pre, inp, ou = 0; cin >> N >> pre; while (--N>0) {
        cin >> inp; if (pre > inp) ou += pre-inp; else pre = inp;
    }
    cout << ou;
}
