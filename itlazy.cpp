#include <bits/stdc++.h> 

using namespace std;
unsigned N, i, Q, op, x, y, val;
int *A;
typedef long long ll;
ll *la, *st;

ll build(unsigned id, unsigned l, unsigned r) {
    if (l == r)
        return st[id] = A[l];

    unsigned mid = l+r >> 1;
    return st[id] = max(build(2*id, l, mid), build(2*id+1, mid+1, r));
}

void fix(const unsigned &id, const unsigned &l, const unsigned &r) {
    if (!la[id]) return; 
    st[id] += la[id];

    if (l != r)
        la[id*2] += la[id], la[id*2+1] += la[id];

    la[id] = 0;
}

ll update(unsigned id, unsigned l, unsigned r, const unsigned& u, const unsigned& v, const unsigned& val) {
    fix(id, l, r);
    if (v < l || r < u) return st[id]; if (u <= l && r <= v) {
        la[id] += val; fix(id, l, r); return st[id];
    }

    unsigned mid = l+r >> 1;
    return st[id] = max(update(2*id, l, mid, u, v, val), update(2*id+1, mid+1, r, u, v, val));
}

ll get(unsigned id, unsigned l, unsigned r, const unsigned &u, const unsigned &v) {
    fix(id, l, r); if (v < l || r < u) return -1e9;
    if (u <= l && r <= v) return st[id];

    unsigned mid = l+r >> 1;
    return max(get(2*id, l, mid, u, v), get(2*id+1, mid+1, r, u, v));
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N; A = new int[N+1]; st = new ll[N*4+4]; la = new ll[N*4+4];
    for (i = 1; i <= N && cin >> A[i]; i++); build(1, 1, N);
    cin >> Q; while (Q--) {
        cin >> op >> x >> y; if (op == 1) {
            cin >> val; update(1, 1, N, x, y, val);
        }
        else cout << get(1, 1, N, x, y) << "\n";
    }
}
