#include <bits/stdc++.h>
#include <cstdlib>
#include <ios>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    unsigned N, t=1, i, j; cin >> N;
    for (i = 2;; i++) for (j = 1; j <=i; j++) {
        if (t > N) { cout << i-1; return 0; }; t += j; 
    }
}
