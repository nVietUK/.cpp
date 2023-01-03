#include <bits/stdc++.h>

using namespace std;

unsigned p, q, r, s, n, x, y, u, v;
double kq;

void giam() {
    if (kq <= 1e8) return;

    while ((y <= r) || (v <= q)) {
        if (kq < 1e8) break;
        if (y <= r) kq/=y, y++;
        if (kq < 1e8) break;
        if (v <= q) kq/=v, v++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("tohop.inp", "r", stdin);
    freopen("tohop.out", "w", stdout);

    cin >> p >> q >> r >> s;

    x = p-q+1, y = r-s+1, u = 2, v = 2, kq = 1;
    while ((x <= p) || (u <= s)) {
        if (x <= p) kq*=x, x++; giam();
        if (u <= s) kq*=u, u++; giam();
    };
    while (y <= r) kq/=y, y++;
    while (v <= q) kq/=v, v++;
    cout << fixed << setprecision(5) << kq;
}