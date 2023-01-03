#include <bits/stdc++.h>

using namespace std;

const int N = 50000;  
int n, q;  
int t[2 * N], v[2 * N];

void build() {  
    copy(begin(t), end(t), begin(v));
    for (int i = n - 1; i > 0; --i) {
        t[i] = max(t[i<<1], t[i<<1|1]);
        v[i] = min(v[i<<1], v[i<<1|1]);
    }
}

int querymin(int l, int r) {  
    int res = INT_MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) 
            res = min(v[l++], res);
        if (r&1) 
            res = min(v[--r], res);
    }
    return res;
}

int querymax(int l, int r) {  
    int res = INT_MIN;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) 
            res = max(t[l++], res);
        if (r&1) 
            res = max(t[--r], res);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("stocks.inp", "r", stdin);
    freopen("stocks.out", "w", stdout);

    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) 
        scanf("%d", t + n + i);
    build();
    
    unsigned a, b; while (q--) {
        scanf("%d %d", &a, &b); a--;
        if (a != b)
            cout << querymax(a, b) - querymin(a, b) << "\n";
        else 
            cout << 0 << "\n";
    }

    return 0;
}