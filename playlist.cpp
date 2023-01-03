#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

signed main() {
    int n; scanf("%u", &n);
    int arr[n], i, j, ou = 0; for (i = 0; i < n && scanf("%d", &arr[i]); i++); i = j = 0;
    set<unsigned> heard;
    while (i < n && j < n) {
        while (j < n && !heard.count(arr[j])) {
            heard.insert(arr[j]);
            ou = max(ou, j-i+1);
            j++;
        }
        while (j < n && heard.count(arr[j])) 
            heard.erase(arr[i]), i++;
    }
    printf("%d", ou);
}
