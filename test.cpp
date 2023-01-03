#include <stdio.h>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
#define notTERMINAL true
#define FILENAME ""
#define intf "%d"
typedef long long ll;
const ll inf = INT_MAX/2-10;

signed main() {
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    int n, m; scanf(intf intf, &n, &m);
    int c[n+10]; for (int i=0; i<n; i++) scanf(intf, &c[i]);
    vector<int> e[n+10];
    for (int i=0, a, b; i<m; i++) {
        scanf(intf intf, &a, &b); a--, b--;
        e[a].push_back(b); e[b].push_back(a);
    }

    int x=-1, pre_x=-1;
    for (int i=0; i<n; i++) 
        if (e[i].size()==1) {
            pre_x=i, x=e[i][0];
            break;
        }

    ll dp[n+10][2][2];
    for (int i=0; i<=n; i++)
        dp[i][0][0]=dp[i][1][0]=inf;
    dp[0][0][0]=0;
    
    while (true) {
        for (int i=0; i<= n; i++) {
            dp[i][0][1]=min(dp[i][0][0], dp[i][1][0]);
            dp[i][1][1]=inf;
            if (i>=1) dp[i][1][1]=min(dp[i][1][1], dp[i-1][1][0]+c[x]);
            if (i>=2) dp[i][1][1]=min(dp[i][1][1], dp[i-2][0][0]+c[x]+c[pre_x]);
        }

        for (int i=0; i<=n; i++)
            dp[i][0][0]=dp[i][0][1],
            dp[i][1][0]=dp[i][1][1];
        
        if (e[x].size()==1) break;
        int tmp=e[x][0]+e[x][1]-pre_x;
        pre_x=x, x=tmp;
    }

    for (int i=n; i>=0; i--) {
        dp[i][0][0]=min(dp[i][0][0], dp[i][1][0]);
        if (i<n) dp[i][0][0]=min(dp[i][0][0], dp[i+1][0][0]);
    }

    int q; scanf(intf, &q); pair<int, int> query[q];
    for (int i=0; i<q; i++) {
        scanf(intf, &query[i].first);
        query[i].second=i;
    }
    sort(query, query+q); int answer=0, ans[q];
    for (int i=0; i<q; i++) {
        while (answer<n && dp[answer+1][0][0]<=query[i].first)
            answer++;
        ans[query[i].second]=answer;
    }
    for (int i=0; i<q; i++) printf(intf "\n", ans[i]);
}