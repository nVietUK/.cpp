#include <stdio.h>
#include <algorithm>

using namespace std;
#define notTERMINAL true
#define FILENAME "quanma"
#define intf "%d"

const int sz = 201;
int b[sz][sz],
    movex[4] = {-1, 1, -2, -2},
    movey[4] = {-2, -2, 1, -1};

signed main() {
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    int n, m, c; scanf(intf intf intf, &m, &n, &c);
    fill(b[0], b[0]+sz*sz, -1);
    for (int ch=2; ch<=m+n; ch++) 
        for (int i=1; i<=m; i++) {
            int j = ch-i;
            for (int k=0; k<=3; k++) {
                int ii=i+movex[k], jj=j+movey[k];
                if (ii>0 && ii<=m && jj>0 && jj<=n && b[ii][jj]==-1)
                    b[i][j]=1;
            }
        }
    for (int i=1,x,y; i<=c; i++) {
        scanf(intf intf, &x, &y); 
        printf(intf "\n", b[x][y]);
    }
#if nVietUK
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++)
            printf(intf " ", b[i][j]);
        printf("\n");
    }
#endif
}