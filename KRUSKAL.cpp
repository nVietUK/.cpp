#include <bits/stdc++.h>
#define ONLINE false
#define DEBUG false
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<unsigned, unsigned> uu;

typedef pair<float, pair<int, int>> edge;

map<int, int> parent;

int findSet(int x) { return (parent[x] == x) ? x : (parent[x] = findSet(parent[x])); }
bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }
void unionSet(int x, int y)  { parent[findSet(x)] = findSet(y); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#if ((__linux__ || _WIN32) && !ONLINE && !ONLINE_JUDGE)
    freopen("Kruskal.inp", "r", stdin);
    if (!DEBUG) freopen("Kruskal.out", "w", stdout);
#endif

    int n, m; cin >> n >> m;
    vector<edge> edgeList(m);

    for (unsigned i = 0; i < m; i++)
        cin >> edgeList[i].se.fi >> edgeList[i].se.se >> edgeList[i].fi;
    sort(edgeList.begin(), edgeList.end());

    for (unsigned i = 0; i < n; i++) parent[i] = i;
    int u[m], v[m], dem = 0; float ans = 0;
    for (unsigned i = 0; i < m; i++) {
        edge curr = edgeList[i];
        if (!isSameSet(curr.se.fi, curr.se.se)) {
            ans+=curr.fi, dem++, u[dem]=curr.se.fi, v[dem]=curr.se.se;
            unionSet(curr.se.fi, curr.se.se);
        }
    }
    cout << ans << "\n";
    for (unsigned i = 1; i <= dem; i++) 
        cout << u[i] << ' ' << v[i] << "\n";
}