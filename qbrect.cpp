#include <stdio.h>
#include <algorithm>
#include <stack>

using namespace std;

signed main() {
    int n, m, in, f[1010], l[1010], r[1010], ou=0; scanf("%d %d", &m, &n);
    fill(f, f+1010, 0);
    while (m--) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &in);
            f[i] = (in) ? f[i]+1 : 0;
        }

        struct pack { int f, id; }; stack<pack> q;

        for (int i = 1; i <= n; i++) {
            while (q.size() && q.top().f >= f[i]) q.pop();
            if (q.empty()) l[i] = 0;
            else l[i] = q.top().id;
            q.push({f[i], i});
        }

        while (q.size()) q.pop();
        for (int i = n; i; i--) {
            while (q.size() && q.top().f >= f[i]) q.pop();
            if (q.empty()) r[i] = 0;
            else r[i] = q.top().id;
            q.push({f[i], i});
        }

        for (int j = 1; j <= n; j++) 
            ou = max(ou, f[j]*(r[j]-l[j]-1));
    }
    printf("%d", ou);
}