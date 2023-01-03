#include <stdio.h>
#include <algorithm>

using namespace std;

pair<int, int> ar[5000]; bool val = false;
bool sol(int i, int j, int x) {
    if (val) return false;
    int l = i+1, r = j-1, m;
    while (l <= r) {
        m = (l+r) >> 1;
        if (ar[m].first == x) {
            printf("%d %d %d", ar[i].second, ar[m].second, ar[j].second); 
            val = true; return false;
        }
        if (ar[m].first > x)
            r = m-1;
        else 
            l = m+1;
    }

    return true;
}

int main() {
    int n, k, i; scanf("%d%d", &n, &k); 
    for (i = 0; i < n && scanf("%d", &ar[i].first); i++) ar[i].second=i+1; sort(ar, ar+n);
    for (i = 0; i < n; i++) for (int j = i+2; j < n && sol(i, j, k-ar[i].first-ar[j].first); j++);
    if (!val) printf("IMPOSSIBLE");
}
