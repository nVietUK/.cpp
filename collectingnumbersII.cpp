#include <stdio.h>
#include <algorithm>

using namespace std;

signed main() {
    int n, m, in, ni; scanf("%d%d", &n, &m);
    int ind[n+2] = {0}, a[n+1] = {0}, l = 1, c = 1;
    ind[n+1] = n+1;
    for (int i = 1; i <= n && scanf("%d", &in); i++) 
        ind[in] = i, a[i] = in;
    for (int i = 1; i <= n; i++) 
        c += (l > ind[i]), l = ind[i];
    while (m-- && scanf("%d%d", &in, &ni)) {
        int r = a[in], s = a[ni];
        swap(a[in], a[ni]);
        c += (ind[s-1] <= ind[s] && ind[s-1] > in)
            -(ind[s-1] > ind[s] && ind[s-1] <= in) 
            +(ind[s] <= ind[s+1] && in > ind[s+1])
            -(ind[s] > ind[s+1] && in <= ind[s+1]);
        ind[s] = in;
        c += 
            (ind[r-1] <= ind[r] && ind[r-1] > ni) 
            - (ind[r-1] > ind[r] && ind[r-1] <= ni)
            + (ind[r] <= ind[r+1] && ni > ind[r+1]) 
            - (ind[r] > ind[r+1] && ni <= ind[r+1]);
        ind[r] = ni;
        printf("%d\n", c);
    }
}
