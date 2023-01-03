#include <bits/stdc++.h>
using namespace std;
 
struct Point 
{ int x, y; };

struct queueNode
{ Point pt; int dist, w; };

int 
    ro[] = {-1, 0, 0, 1},
    co[] = {0, -1, 1, 0};
unsigned n, m, p;
char ta[300][300];

bool isValid(int row, int col)
{ return (row >= 0) && (row < n) && (col >= 0) && (col < m);}

int o(int x, int y)
{ if (ta[x][y] == 'C') return p; return 0; }

int dtc(Point in)
{
    vector<vector<bool>> visited; 
    visited.clear(); visited.resize(n); for (auto& a : visited) a.resize(m, false);
    visited[in.x][in.y] = true;
 
    queue<queueNode> q; while (q.size()) q.pop(); q.push({in, 0});  
 
    while (!q.empty())
    {
        queueNode curr = q.front(); q.pop(); 
        if ((curr.pt.x == 0) || (curr.pt.x == n-1) ||
            (curr.pt.y == 0) || (curr.pt.y == m-1)
        ) return curr.dist; 
 
        if (curr.w)
        { q.push({curr.pt, curr.dist, curr.w-1}); continue; }
 
        for (int i = 0; i < 4; i++)
        {
            int row = curr.pt.x + ro[i], 
                col = curr.pt.y + co[i];             
            if (isValid(row, col) && (ta[row][col] != '#') && !visited[row][col])
            { visited[row][col] = true; q.push({{row, col}, curr.dist+o(row, col)+1, o(row, col) }); }
        }
    } 
    return -1;
}

Point source;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("mecung.inp", "r", stdin);
    freopen("mecung.out", "w", stdout);

    cin >> n >> m >> p;
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m; i++)
        {
            cin >> ta[j][i];
            if (ta[j][i] == 'A')
                source = {j, i};
        }

    cout << dtc(source) + 1;
    return 0;
}