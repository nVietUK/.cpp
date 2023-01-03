#include <bits/stdc++.h>

using namespace std;

signed main() {
    unsigned long long res; unsigned Q, N, M, i; cin >> Q; while (Q--) {
        cin >> N >> M;
        for (i = 2; i < M; i++) 
            res += i*2*N % (1000000007);
        cout << (res + N+1 + N*M) % (1000000007);
    }
}
