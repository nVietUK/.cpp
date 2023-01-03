#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;

signed main() {
    char s[1000]; scanf("%s", s);
    s[0] = toupper(s[0]);
    printf("%s", s);
}