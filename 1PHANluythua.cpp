#include <stdio.h>
#include <algorithm>

using namespace std;
#define notTERMINAL false
#define FILENAME ""
#define intf "%d"

signed main() {
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    int n; double S=0, dem=1;
    scanf(intf, &n); 
    if !(0<n && n<10) {
        printf("So n khong hop le. Vui long nhap lai");
        return 0;
    }
    for (int i=1; i<=n; i++) {
        dem*=i; S+=1/dem;
    }
    printf("%f", S);
}