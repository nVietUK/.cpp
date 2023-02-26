#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;
#define notTERMINAL true
#define FILENAME "hamburgers"
#define intf "%d"

typedef long long int lli;

struct bread {
    int b, s, c;
    bread(int b=0, int s=0, int c=0) : b(b), s(s), c(c) {};
    void initF() {
        b=0, s=0, c=0;
        char f[200]; fill(f, f+200, '-'); scanf("%s", f);
        for (int i=0; f[i]!='-'; i++)
            if (f[i]=='B') b++; else if (f[i]=='S') s++; else if (f[i]=='C') c++;
    }
    void initR() {
        b=0, s=0, c=0;
        scanf(intf intf intf, &b, &s, &c);
    }
};

#define cost(x, i) max(x*bFormular.i-bRemain.i, (lli)0)*bCost.i
lli price(lli x, bread bFormular, bread bRemain, bread bCost) {
    return cost(x, b)+cost(x, s)+cost(x, c);
}

lli solve(bread bFormular, bread bRemain, bread bCost, lli money) {
    lli b=0, f=1e13, m, pr, ou;
    while (b<=f) {
        m=(b+f)/2, pr=price(m, bFormular, bRemain, bCost);
        if (pr==money) { return m; }
        if (pr>money) { f=m-1; } else { b=m+1; ou=m; }
    }
    return ou;
}

signed main() {
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    bread bFormula, bRemain, bCost; bFormula.initF(); bRemain.initR(); bCost.initR();
    lli money; scanf("%lld", &money);
    printf("%lld", solve(bFormula, bRemain, bCost, money));
}