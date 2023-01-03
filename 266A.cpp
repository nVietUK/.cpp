#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;

signed main() {
    int c=0, b=0; char s[50]; scanf("%d\n%s", &c, s); 
    for (int i = 0; i<c; i++) 
        b += (s[i] == s[i+1]);
    printf("%d", b);
}