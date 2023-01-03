#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
const int N = 2000005;
int tree[4*N], nn, n;

void update(int k, int x) {
    k += nn; tree[k]=x; k>>=1; while (k > 0)
        tree[k] = max(tree[k<<1], tree[k<<1|1]), k>>=1;
}

int query(int x) {
    if (tree[1] < x) return -1;
    int k = 1; while (k < nn) 
        if (tree[k<<1] >= x) k<<=1;
        else k = k<<1|1;
    return k-nn;
}

void solve() {
    int m, t; cin >> n >> m; nn = ceil(log2(n*1.0)); nn = 1<<nn;
    for (int i = 0; i < n && cin >> t; i++) update(i, t);
    while (m-- && cin >> t) {
        int i = query(t); cout << i+1 << ' ';
        if (i >= 0) update(i, tree[i+nn] - t);
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
//    freopen("test.txt", "r", stdin);

    solve();
}
