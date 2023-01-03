#include <algorithm>
#include <bits/stdc++.h> 
#define next [0]
#define jump [1]
#define toll(x, y) abs(x-y)

using namespace std;
const unsigned inf = 1e9;
unsigned N, i;
int **st, *a;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N; st = new int*[N+1]; 
    if (N+1 > 4) 
        a = new int[N+1]; 
    else { 
        a = new int[4];
        for (i = N+1; i <= 4; i++ )
            st[i] = new int[2];
    }
    for (i = 1; i <= N && cin >> a[i]; i++)
        st[i] = new int[2];

    st[1]next = inf; st[1]jump = inf; 
    st[2]next = toll(a[1], a[2]); st[2]jump = inf;
    st[3]next = min(st[2]next, st[2]jump) + toll(a[2], a[3]); st[3]jump = toll(a[1], a[3]);

    for (i = 4; i <= N; i++) 
        st[i]next = min(st[i-1]next, st[i-1]jump) + toll(a[i], a[i-1]), st[i]jump = min(st[i-2]next, st[i-2]jump) + toll(a[i], a[i-2]);

    cout << min(st[N]next, st[N]jump);
}
