#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

signed main() {
    int n, k, i, t, q; scanf("%d %d", &n, &k);
    char s[2][50]; scanf("%s", s[0]);
    
    for (i = 0; i < k; i++) {
        t = i % 2, q = !t; memcpy(s[q], s[t], sizeof(char)*50);
        for (int j = 1; j < n; j++)
            if (s[t][j-1] != s[t][j] && s[t][j] == 'G') 
                swap(s[q][j-1], s[q][j]);
    }

    for (i = 0; i < n; i++)
        printf("%c", s[q][i]);
}
