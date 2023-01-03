#include <bits/stdc++.h> 

using namespace std;
typedef long long ll;
unsigned N, Q, op, x, y;
ll *st;

void update(unsigned id, unsigned l, unsigned r, unsigned u, unsigned val) {
    if (l > u || r < u) return;
    if (l == r) { st[id] = val; return; }
    unsigned op = l + r >> 1;
    update(2*id, l, op, u, val);
    update(2*id+1, op+1, r, u, val);
    st[id] = st[2*id] + st[2*id+1];
}

long long get(unsigned id, unsigned l, unsigned r, unsigned u, unsigned v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[id];

    unsigned op = l + r >> 1;
    return get(2*id, l, op, u, v) + get(2*id+1, op+1, r, u, v);
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N >> Q; st = new ll[4*N];
    while (Q--) {
        cin >> op >> x >> y;
        if (op == 1) update(1, 1, N, x, y);
        else cout << get(1, 1, N, x, y) << "\n";
    }
}
