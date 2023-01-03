#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
#define notTERMINAL true
#define FILENAME "subnet"
#define intf "%d"
unsigned int subnet=0;

unsigned sub() {
    unsigned tc = 0, inp; char dot;
    for (int i=0; i<3; i++) { 
        scanf(intf "%c", &inp, &dot); tc = tc | inp;
        tc = tc << 8;
    }
    scanf(intf, &inp); tc |= inp;
    return tc;
}

bool ischild(unsigned &ip, unsigned &sip, unsigned &subnet) {
    return ((ip&subnet) == (sip&subnet)); // neu ip va sip cung subnet tra ve true 
}

void out(unsigned a) {
    stack<unsigned char> s;
    unsigned char num = -1;
    for (int i = 0; i < 3; i++) {
        s.push(a & num);
        a >>= 8;
    }
    printf(intf, a&num);
    while (s.size()) {
        printf("." intf, s.top()); s.pop();
    }
    printf("\n");
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

    int n, m; scanf(intf intf, &m, &n);
    // tao subnet tu m
    for (int i = 31; i > (31-m); i--)
        subnet = subnet | (1<<i);

    vector<unsigned> q; // mang chua cac ip con hop le
    unsigned ip = sub(); // doc dia chi ip
    for (int i = 0; i < n; i++) {
        unsigned sip = sub(); // doc dia chi ip con
        if (ischild(ip, sip, subnet)) // kiem tra 
            q.push_back(sip); // cho vao mang
    }
    sort(q.begin(), q.end(), greater<unsigned>()); // sap xep lai mang 
    if (q.size())
        while (q.size()) {
            out(q.back()); q.pop_back(); // in cac ip con
        }
    else printf("0");
}