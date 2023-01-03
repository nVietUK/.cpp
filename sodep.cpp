#include <bits/stdc++.h>

using namespace std;

int findb(unsigned in) {
    if (in < 2)
        return 0;
    if (in < 5)
        return 1;
    if (in < 7)
        return 2;
    if (in < 9)
        return 3;
    return 4;
}

int finda(unsigned in) {
    if (!in)
        return 0;
    if (in > 7)
        return 1;
    if (in > 5)
        return 2;
    if (in > 2)
        return 3;
    return 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("sodep.inp", "r", stdin);
    freopen("sodep.out", "w", stdout);

    unsigned t; cin >> t; while (t--) {
        int a, b; cin >> a >> b;
        cout << (int)((b / 10) - (a / 10 + 1)) * 4 + finda((a+1)%10) + findb(b%10) << "\n";
    }
}