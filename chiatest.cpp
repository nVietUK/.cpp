#include <bits/stdc++.h>
#define MAX_N 1000 + 1
#define ii pair<int, int>
#define INF 99999

using namespace std;

unsigned n,m,y,p,q,k,A[MAX_N], B[MAX_N], C[MAX_N];
bool mark[MAX_N];
int d[MAX_N],parent[MAX_N];
vector<vector<ii>> Ar;

void readStore(unsigned* in, unsigned li){
    unsigned a, b;
    for (unsigned i = 0; i < li; i++){
        cin >> a >> b;
        in[a] = b;
    }
}

int dijkstra(int s){
    for(int i=1; i<=n; i++){
        d[i]=INF; mark[i]=false;
    }
    priority_queue<ii, vector<ii>, greater<ii>> Wait;
    d[s]=0;
    Wait.push(ii(0,s));
    while(!Wait.empty()){
        int u=Wait.top().second;
        Wait.pop();
        if (mark[u]) continue;
		mark[u]=true;
        for(int i=0; i<(int)Ar[u].size(); i++){
            int v=Ar[u][i].second;
			int w=Ar[u][i].first;
            if (d[v]>d[u]+w){
                d[v]=d[u]+w;
                parent[v]=u;
                Wait.push(ii(d[v],v));
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("DVGH.INP", "r", stdin);
    freopen("DVGH.OUT", "w", stdout);
    cin >> n >> m >> y >> p >> q >>k;
    unsigned a, b, c; Ar.resize(n+1);
    for (unsigned i = 0; i < m; i++){
        cin >> a >> b >> c;
        Ar[a].push_back(ii(c, b));
        Ar[b].push_back(ii(c, a));
    }
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    readStore(A, p);
    readStore(B, q);
    readStore(C, k);
    dijkstra(y);

    unsigned AB = INF, AC = INF, BC = INF, ABC = INF;
    a = b = c = INF;
    for (unsigned i = 1; i <= n; i++)
    {
        if (A[i]){
            a = min(a, A[i] + d[i]);
            if (B[i] && C[i])
                ABC = min(ABC, A[i] + B[i] + C[i] + d[i]);
            if (B[i])
                AB = min(AB, A[i] + B[i] + d[i]);
            if (C[i])
                AC = min(AC, A[i] + C[i] + d[i]);
        }
        if (B[i]){
            b = min(b, B[i] + d[i]);
            if (C[i])
                BC = min(BC, B[i] + C[i] + d[i]);
        }
        if (C[i])
            c = min(c, C[i] + d[i]);
    }
    cout << a << "\n" << min(ABC, min(AB + c, min(AC + b, BC + a)));
}
