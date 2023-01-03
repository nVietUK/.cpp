#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;

signed main() {
    char s[100]; scanf("%s", s);
    int l=0, u=0; for (int i = strlen(s)-1; i >= 0; i--)
        if ((s[i] >= 'a') && (s[i] <= 'z')) l++; else u++;
    if (l >= u)
        for (int i = strlen(s)-1; i>=0; i--)
            s[i] = tolower(s[i]);
    else 
        for (int i = strlen(s)-1; i>=0; i--)
            s[i] = toupper(s[i]);
    printf("%s", s);
}