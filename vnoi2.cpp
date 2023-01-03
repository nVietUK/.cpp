#include <stdio.h>
#include <cmath>
#include <ios>
#include <iostream>
#define check(x) (x <= n) && (x > 0)
#define cou(x, y, i, j) { printf("2\n%d %d\n%d %d\n", x, y, i, j); break; }

using namespace std;

signed main() {
    cin.tie(0); cout.tie(0);
    int n, q, i, j, x, y; bool jm, jp, im, ip;
    scanf("%d%d", &n, &q);
    while (q--) {
        scanf("%d%d%d%d", &i, &j, &x, &y);
        if ((x==i) && (y==j))
            printf("0\n");
        else
        if ((x%2==y%2) != (i%2==j%2)) 
            printf("-1\n");
        else {
            if (abs(i-x) == abs(j-y)) 
                printf("1\n%d %d\n", x, y);
            else {
                for (int m = 1;; m++) { jm = check(j-m), jp = check(j+m), im = check(i-m), ip = check(i+m); 
                    if (!ip && !im && !jp && !jm) break;
                    if (im && jm && abs(i-x-m)==abs(j-y-m)) cou(i-m, j-m, x, y)
                    if (ip && jp && abs(i-x+m)==abs(j-y+m)) cou(i+m, j+m, x, y) 
                }
            }
        }
    }
}
