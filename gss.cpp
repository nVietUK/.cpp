#include <bits/stdc++.h> 

using namespace std;
typedef long long ll;
const int inf = 1e9+7;
unsigned N, i, Q, x, y, op;
ll *arr;
struct node; node *st;

struct node {
    ll pre, suf, sum, maxsum;

    static node base() { return {-inf, -inf, 0, -inf}; }

    static node merge(const node& a, const node& b) {
        node res; 
        res.pre = max(a.pre, a.sum + b.pre);
        res.suf = max(b.suf, a.suf + b.sum);
        res.sum = a.sum + b.sum;
        res.maxsum = max(a.maxsum, b.maxsum);
        res.maxsum = max(res.maxsum, a.suf + b.pre);
        return res;
    }
    
};

node get(unsigned id, unsigned l, unsigned r, unsigned u, unsigned v) {
    if (r < u || v < l) return node::base();
    if (u <= l && r <= v) return st[id];

    unsigned mid = l+r >> 1;
    return node::merge(get(2*id, l, mid, u, v), get(2*id+1, mid+1, r, u, v));
};

node build(unsigned id, unsigned l, unsigned r) {
    if (l == r) return st[id] = { arr[l], arr[l], arr[l], arr[l] };

    unsigned mid = l+r >> 1;
    return st[id] = node::merge(build(id*2, l, mid), build(id*2+1, mid+1, r));
}

node update(unsigned id, unsigned l, unsigned r, unsigned pos, unsigned val) {
    if (l == r && l == pos) return st[id] = { val, val, val, val };
    if (pos < l || r > pos) return st[id];

    unsigned mid = l+r >> 1;
    return st[id] = node::merge(update(id*2, l, mid, pos, val), update(id*2+1, mid+1, r, pos, val));
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N >> Q; arr = new ll[N+1]; st = new node[(N+1)*4]; 
    for (i = 1; i <= N && cin >> arr[i]; i++); build(1, 1, N);
    while (Q--) {
        cin >> op >> x >> y;
        if (op == 2) 
            cout << get(1, 1, N, x, y).maxsum << "\n";
        else 
            update(1, 1, N, x, y);
    }
}
