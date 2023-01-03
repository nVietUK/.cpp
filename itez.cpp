#include <bits/stdc++.h>

using namespace std;
int N, *a, i, M, *st, op, x, y;

void update(int id, int l, int r, const int &pos, const int &val) {
    if (r < pos || pos < l) return;
    if (l == r) {
        st[id] = val;
        return;
    }

    int mid = l+r >> 1;
    update(2*id, l, mid, pos, val); update(2*id+1, mid+1, r, pos, val);
    st[id] = max(st[id*2], st[id*2+1]);
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }

    int mid = l+r >> 1;
    build(id*2, l, mid); build(id*2+1, mid+1, r);
    st[id] = max(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, const int &u, const int &v) {
    if (r < u || v < l) return -1e9-200;
    if (u <= l && r <= v) return st[id];

    int mid = l+r >> 1;
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N; a = new int[N+1]; st = new int[N*4+4];
    for (i = 1; i <= N && cin >> a[i]; i++); build(1, 1, N);

    cin >> M; while (M--) {
        cin >> op >> x >> y; if (op == 1)
            update(1, 1, N, x, y); 
        else
            cout << get(1, 1, N, x, y) << "\n";
    }
}
