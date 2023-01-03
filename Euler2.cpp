#include <iostream> //Van
//#include <cstdio>
#include <vector>
#include <stack>
#include <queue>

#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;

const int N = 1e5+5, M = 1e6+5; // So dinh, so canh toi da
int n, m, vis[M], idx[N];
vector  < pair<int, int> > ke[N]; // Danh sach canh  ke

int connect()
{
    int cnt = 0; queue<int> Q;
    Q.push(1); vis[1] = 1;
    while (!Q.empty()) {
        cnt += 1; // so dinh duoc tham
        int u = Q.front(); Q.pop();
        for (int i= 0;i<ke[u].size();i++) {
            int v = ke[u][i].x;
            if (vis[v]) continue;
            vis[v] = 1; Q.push(v);
        }
    }
    return cnt == n;
}
int euler(int &start)
{
    int cnt = 0;
    for(int i= 1;i<=n ;i++) if (ke[i].size() & 1) {
        if (++cnt > 2) return -1;
        else start = i;
    }
    if (!connect()) return -1;

    return cnt == 0 ? 2 : 1; // 2: co chu trinh; 1: chi co duong di
}
void tour(int start)
{
    stack<int> S; vector<int> CE;
    for (int j=1;j<= m;j++) vis[j] = 0;

    S.push(start);
    while (!S.empty()) {
        int u = S.top();
        while (idx[u] < (int)ke[u].size() && vis[ ke[u][idx[u]].y    ] ) ++ idx[u];
        if (idx[u] < (int)ke[u].size()) {
            S.push(ke[u][idx[u]].x);
            vis[ke[u][idx[u]].y] = 1;
        } else {
            CE.push_back(S.top()); S.pop();

        }
    }

    for (int i= 0; i< CE.size();i++) printf("%d ",CE[i]);
}
int main()
{
    ios::sync_with_stdio(); cin.tie(0);

    freopen("Euler2.inp","r",stdin);
    freopen("Euler2.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<= m;i++) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(mp(v, i));
        ke[v].pb(mp(u, i));
    }

    int start=1 , val = euler(start);
    printf("%d\n",val);
    if (val != -1) tour(start);
}
