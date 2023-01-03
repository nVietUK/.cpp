#include <bits/stdc++.h> 
#define fi first
#define se second 

using namespace std;
typedef pair<unsigned, unsigned> uu;
typedef long long ll;
const unsigned modular = 1e9 + 7;
unsigned N, M, op, x, y, a, b;
uu *lazy;
ll *st;

void fix(const unsigned &id, const unsigned &l, const unsigned &r) {
    st[id] += (1ll * lazy[id].fi * (l+r) * (r-l+1) / 2) % modular; st[id] %= modular; 
    st[id] += (1ll * lazy[id].se * (r-l+1)) % modular; st[id] %= modular;

    if (l != r) {
        lazy[id*2].fi += lazy[id].fi; lazy[id*2].fi %= modular;
        lazy[id*2].se += lazy[id].se; lazy[id*2].se %= modular;
        lazy[id*2+1].fi += lazy[id].fi; lazy[id*2+1].fi %= modular;
        lazy[id*2+1].se += lazy[id].se; lazy[id*2+1].se %= modular;
    }

    lazy[id] = {0,0};
}

void update(unsigned id, unsigned l, unsigned r, const unsigned& u, const unsigned& v, const unsigned& a, const unsigned& b) {
    fix(id, l, r); if (r < u || v < l) return;
    if (u <= l && r <= v) {
        lazy[id] = {a,(1ll * b - 1ll * u * a + 1ll * modular * modular) % modular};
        fix(id, l, r); return; 
    }

    unsigned mid = l+r >> 1;
    update(id*2, l, mid, u, v, a, b); update(id*2+1, mid+1, r, u, v, a, b);
    st[id] += st[id*2]+st[id*2+1]; st[id] %= modular;
}

unsigned get(unsigned id, unsigned l, unsigned r, const unsigned &u, const unsigned &v) {
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return st[id];

    unsigned mid = l+r >> 1;
    return (get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v)) % modular;
}

signed main() {
    cin >> N >> M; st = new ll[N*4+4]; lazy = new uu[N*4+4];
    while (M--) {
        cin >> op >> x >> y;
        if (op == 1) {
            cin >> a >> b;
            update(1, 1, N, x, y, a, b);
        }
        else cout << get(1, 1, N, x, y) << "\n";
    }
}
