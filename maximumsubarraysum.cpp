#include <stdio.h>
#include <vector>
#include <climits>

using namespace std;

signed main() {
    unsigned n; scanf("%u", &n); long long maxV = INT_MIN, minV = INT_MAX, y; for (unsigned i = 0; i < n && scanf("%lld", &y); i++) { 
        if (!i) minV = y, maxV = y; 
        else 
            minV = max(minV+y, y), maxV = max(maxV, minV);
    }
    printf("%lld", maxV);
}
