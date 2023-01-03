#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int m,n,i=0,j=-1,pre[1000100]={-1};
    char a[1000100],b[1000100];
    scanf("%s%s",&a,&b);
    m=strlen(a); n=strlen(b);
    while (i<n) {
        while (j>=0 && b[i]!=b[j]) j=pre[j];
        i++; j++;
        pre[i]=(j>=n || b[i]!=b[j]?j:pre[j]);
    }
    i=j=0;
    while (i<m) {
        while (j>=0 && a[i]!=b[j]) j=pre[j];
        i++; j++;
        if (j>=n) j=pre[j], printf("%d ",i-n+1);
    }
    return 0;
}
