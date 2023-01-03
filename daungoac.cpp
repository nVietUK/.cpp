#include <stdio.h>
#include <algorithm>

using namespace std;
int t[1001] = {0};

int main() {
    int n, q, x, y; scanf("%d %d", &n, &q); char s[n+1]; scanf("%s", s+1);
    for (int i = 2; i <= n; i++)
        t[i] = t[i-1] + ((s[i] == ')') && (s[i-1] == '('));
    while (q-- && scanf("%d %d", &x, &y)) 
        printf("%d\n", t[y]-t[x-1]);
}
