#include <stdio.h>
#include <algorithm>
#include <cstring>

#define file "test"

using namespace std;

signed main() {
#if nVietUK
    freopen(file".INP", "r", stdin);
    #if not LOCAL
        freopen(file".OUT", "w", stdout);
    #endif
#endif
    
    char s[200]; scanf("%s", s);

    int i = 0, j = strlen(s);
    while (i < j) {
        if (s[i++] == '.') { printf("0"); continue; }
        else if (s[i] == '.') printf("1");
        else printf("2"); i++;
    }
}
