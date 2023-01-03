#include <stdio.h>
#include <vector>
 
using namespace std;
 
signed main() {
    unsigned n, p, ou = 0; scanf("%u", &n); vector<unsigned> arr(n+1); while (n-- && scanf("%u", &p)) arr[p] = n; p = 0;
    for (int i = arr.size()-1, p = i+2; i > 0; i--) {
        if (p > arr[i]) 
            ou++;
        p = arr[i];
    }
    printf("%u", ou);
}
