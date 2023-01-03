#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

unsigned cnt['Z'+10]; 

signed main() {
    char s[1000000]; scanf("%s", s); 
    for (int i = strlen(s)-1; i >= 0; i--) cnt[s[i]]++;
    unsigned odd = 0;
    for (unsigned i = 'A'; i <= 'Z'; i++) { 
        if (cnt[i]%2) { 
            if (odd) { 
                printf("NO SOLUTION"); return 0; 
            } 
            else 
                odd = i; 
        } 
    }
    if ((bool)(odd>0) != (bool)(strlen(s)%2==1)) { printf("NO SOLUTION"); return 0; }; string sa;
    for (unsigned i = 'A'; i <= 'Z'; i++) 
        for (unsigned j = 0; j < cnt[i]/2; j++) 
            sa += (char)i;
    printf("%s", sa.c_str()); if (odd>0) printf("%c", odd); reverse(sa.begin(), sa.end()); printf("%s", sa.c_str());
}
