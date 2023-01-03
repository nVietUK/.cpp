#include <bits/stdc++.h> 

using namespace std;
typedef pair<unsigned, unsigned> uu;
const unsigned modular = 1e9 + 7;
uu *la; unsigned *a, *st, N, M, op, x, y, z, i;

void fixmul(const unsigned &id, const unsigned &l, const unsigned &r);
void fixinc(const unsigned &id, const unsigned &l, const unsigned &r) {
    if (!la[id].first) return; if (la[id].second) fixmul(id, l, r);
    st[id] += la[id].first; st[id] %= modular;

    if (l != r) 
        la[id*2].first += la[id].first, la[id*2+1].first += la[id].first;

    la[id].first = 0;
}

void inc(unsigned id, unsigned l, unsigned r, const unsigned &u, const unsigned &v, const unsigned &value) {
    fixinc(id, l, r); fixmul(id, l, r);
    if (r < u || v < l) return;
    if (u <= l && r <= v) {
        la[id].first = value;
        fixinc(id, l, r);
        return;
    }

    unsigned mid = l+r >> 1;
    inc(id*2, l, mid, u, v, value); inc(id*2+1, mid+1, r, u, v, value);
    st[id] = st[id*2] + st[id*2+1];
}

void fixmul(const unsigned &id, const unsigned &l, const unsigned &r) {
    if (la[id].second == 0) return; if (la[id].first) fixinc(id, l, r);
    st[id] = (st[id] * la[id].second) % modular;

    if (l != r) 
        la[id*2].second += la[id].second, la[id*2+1].second += la[id].second;

    la[id].second = 0;
}

void mul(unsigned id, unsigned l, unsigned r, const unsigned &u, const unsigned &v, const unsigned &value) {
    fixmul(id, l, r); fixinc(id, l, r);
    if (r < u || v < l) return;
    if (u <= l && r <= v) {
        la[id].second = value;
        fixmul(id, l, r);
        return;
    }

    unsigned mid = l+r >> 1;
    mul(id*2, l, mid, u, v, value); mul(id*2+1, mid+1, r, u, v, value);
    st[id] = st[id*2] + st[id*2+1];
}

void dat(unsigned id, unsigned l, unsigned r, const unsigned &u, const unsigned &v, const unsigned &value) {
    if (r < u || v < l) return;
    if (l == r) {
        st[id] = value;
        la[id] = {0,0};
        return;
    }

    unsigned mid = l+r >> 1;
    dat(id*2, l, mid, u, v, value); dat(id*2+1, mid+1, r, u, v, value);
    st[id] = st[id*2] + st[id*2+1];
}

void build(unsigned id, unsigned l, unsigned r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }

    unsigned mid = l+r >> 1;
    build(id*2, l, mid); build(id*2+1, mid+1, r);
    st[id] = st[id*2] + st[id*2+1];
}

unsigned get(unsigned id, unsigned l, unsigned r, const unsigned &u, const unsigned &v) {
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return st[id] % modular;

    unsigned mid = l+r >> 1;
    return (get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v)) % modular;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N >> M; a = new unsigned[N+1]; st = new unsigned [N*4+4]; la = new uu[N*4+4];
    for (i = 1; i <= N && cin >> a[i]; i++); build(1, 1, N);

    while (M--) {
        cin >> op >> x >> y;
        if (op == 4) {
            cout << get(1, 1, N, x, y) << "\n";
            continue;
        }
        cin >> z;
        if (op == 1) 
            inc(1, 1, N, x, y, z);
        else if (op == 2) 
            mul(1, 1, N, x, y, z);
        else if (op == 3)
            dat(1, 1, N, x, y, z);
        else 
            cout << get(1, 1, N, x, y) << "\n";
    }
}
