#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdint>

using namespace std;
char t[30];
struct bignum {
    char val[30]; bool am = false;

    void doc() {
        cin >> val;
        if (val[0]=='-') {
            copy(val+1, val+strlen(val), t);
            am = true; reverse(t, t+strlen(t));
            fill(val, val+30, NULL);
            copy(t, t+strlen(t), val);
        }
        else {
            am = false;
            reverse(val, val+strlen(val));
        }
    }

    void xuat() {
        if (am) cout << '-';
        for (int i = strlen(val); i >= 0; i--)
            cout << val[i];
    }

    bignum(char *t=NULL, bool am=false) : am(am) { if (t!=NULL) copy(t, t+30, val); }
} i, ou;
unsigned z, N; int tinh;
bool du; 

bool so(bignum a, bignum b) {
    if (strlen(a.val) == strlen(b.val)) {
        for (int i = strlen(a.val); i >= 0; i--) {
            if (a.val[i] != b.val[i])
                return a.val[i] < b.val[i];
        }
    }
    else return strlen(a.val) < strlen(b.val);
    return false;
}

void procong(bignum a, bignum b) {
    for (unsigned i = 0; i < strlen(b.val); i++) {
        tinh = a.val[i] + b.val[i] - 2*48 + du; du = false;
        if (tinh > 9) {
            du = true; a.val[i] = tinh + 48; continue;
        }
        a.val[i] = tinh + 48;
    }
    if (du) a.val[strlen(a.val)] = 1;
    copy(a.val, a.val+30, t);
}

void protru(bignum a, bignum b) {
    for (unsigned i = 0; i < strlen(b.val); i++) {
        tinh = a.val[i] - b.val[i]; du = false;
        if (tinh < 0) {
            du = true; a.val[i] = abs(tinh) + 48; continue;
        }
        a.val[i] = tinh + 48;
    }
    if (du) a.val[strlen(a.val)] = 1;
    copy(a.val, a.val+30, t);
}

bignum cong(const bignum &a, const bignum &b) {
    if (a.am == b.am) {
        bool ouam = a.am;
        procong(a, b);
    }
    else if (so(a, b) == true) {
        protru(b, a);
        return bignum(t, b.am);
    }
    else {
        protru(a, b);
        return bignum(t, a.am);
    }
    return bignum();
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N; while (N--) {
        i.doc();
        ou = cong(i, ou);    
    }
    ou.xuat();
}
