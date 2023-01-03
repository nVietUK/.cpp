#include <bits/stdc++.h>

using namespace std;
const unsigned maxnt = sqrt(3000) + 10;
bool *pri; unsigned cnt=0, N, i, j;
set<unsigned> p;

void init() {
    pri = new bool[maxnt];
    fill(pri, pri+maxnt, true); 
    pri[0] = pri[1] = false; p.insert(2);
    for (i = 3; i <= sqrt(maxnt); i+=2) {
        for (j = i; i*j <= maxnt; j+=2) {
            pri[i*j] = false;
        }
        p.insert(i);
    }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    init();
    cin >> N; j=0; for (; N > 0; N--) {
        i = 0; for (unsigned e : p) {
            if (N % e == 0)
                i++;
            else if (e > N)
                break;
        }
        if (i==2) j++;
    }
    cout << j;
}
