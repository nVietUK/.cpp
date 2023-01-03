#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;

signed main() {
    char s[20]; scanf("%s", s); int c=0;
    for (int i = strlen(s)-1; i>=0; i--) 
        c += (s[i] == '4' || s[i] == '7');
    printf("%s", (c==4 || c==7) ? "YES" : "NO");
}