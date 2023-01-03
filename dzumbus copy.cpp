#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
#define notTERMINAL true
#define FILENAME "dzmbus"
#define intf "%d"
#define llf "%lld"
typedef long long ll;
const ll inf = INT_MAX/2-10;
const int MAXN = 1010, MAXQ = 2e5 + 10;

ll c[MAXN], dp_in[MAXN][MAXN], dp_out[MAXN][MAXN], subtree_size[MAXN];

ll pre_dp_in[MAXN], pre_dp_out[MAXN];
void calc(int i, const int &n, const vector<int> *e, int parent=-1) {
    subtree_size[i]=1; if (i!=n) {
        for (int j : e[i])
            if (j != parent) {
                calc(j, n, e, i);
                subtree_size[i]+=subtree_size[j];
            }
    }

    for (int k=0; k<=n; k++) 
        dp_in[i][k]=dp_out[i][k]=inf;
    dp_out[i][0]=0;

    int total=0; 
    pre_dp_in[0]=inf;
    pre_dp_out[0]=0;

    for (int j : e[i]) {
        if (j==parent) continue;

        for (int k=0; k<=total+subtree_size[j];k++)
            dp_in[i][k]=dp_out[i][k]=inf;

        for (int a=0; a<=total; a++) 
            for (int b=0; b<=subtree_size[j]; b++) {
                dp_out[i][a+b]=min(dp_out[i][a+b], pre_dp_out[a]+min(dp_in[j][b], dp_out[j][b]));
                dp_in[i][a+b]=min(dp_in[i][a+b], min(pre_dp_out[a]+dp_in[j][b], pre_dp_in[a]+min(dp_in[j][b], dp_out[j][b])));
                if (b>0)
                    dp_in[i][a+b]=min(dp_in[i][a+b], min(pre_dp_out[a], pre_dp_in[a])+dp_out[j][b-1]+c[j]);
            }
        
        total+=subtree_size[j];
        for (int k=0; k<=total; k++)
            pre_dp_in[k]=dp_in[i][k],
            pre_dp_out[k]=dp_out[i][k];
    }
    
    for (int k=total; k>=0; k--) 
        dp_in[i][k+1]=min(inf, dp_in[i][k]+c[i]);
    dp_in[i][0]=inf;
}

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
    vector<int> e[n+1];
    for (int i=0; i<n; i++) 
        scanf(llf, &c[i]), dp_in[i][0]=-1;
    for (int i=0, a, b; i<m; i++) {
        scanf(intf intf, &a, &b);
        e[--a].push_back(--b);
        e[b].push_back(a);
    }

    for (int i=0; i<n; i++) 
        if (dp_in[i][0]==-1) {
            calc(i, n, e);
            e[n].push_back(i);
        }
    
    c[n]=inf; calc(n, n, e);
    for (int i=n-1; i>=0; i--)
        dp_out[n][i]=min(dp_out[n][i], dp_out[n][i+1]);

    int q; scanf(intf, &q);
    pair<int, int> query[q];
    for (int i=0; i<q; i++)
        scanf(intf, &query[i].first), query[i].second=i;
    sort(query, query+q); int ans=0, arrans[q];
    for (int i=0; i<q; i++) {
        while (ans < n && dp_out[n][ans+1]<=query[i].first)
            ans++;
        arrans[query[i].second]=ans;
    }
    for (int i=0; i<q; i++) printf(intf "\n", arrans[i]);
}