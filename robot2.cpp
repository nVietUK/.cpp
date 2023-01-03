#include <bits/stdc++.h>
using namespace std;
 
struct Point 
{ long long x, y; };

struct queueNode
{ Point pt; long long dist, w; };

vector<long long> 
    ro = {-1, 0, 0, 1},
    co = {0, -1, 1, 0};
long long n, m, p, q, t;
map<long long, map<long long, char>> ta;
vector<Point> dib;

bool isValid(long long row, long long col)
{ return (row >= 0) && (row < n) && (col >= 0) && (col < m);}

long long o(long long x, long long y)
{ if (ta[x][y] == 'V') return q; if (ta[x][y] == 'K') return p;  return 0; }

long long BFS(Point src, Point dest)
{
    vector<vector<bool>> visited; 
    visited.clear(); visited.resize(n); for (auto& a : visited) a.resize(m, false);
    visited[src.x][src.y] = true;
 
    queue<queueNode> q; while (q.size()) q.pop(); q.push({src, 0, 0});  
 
    while (!q.empty())
    {
        queueNode curr = q.front(); q.pop(); 
        if ((curr.pt.x == dest.x) && 
            (curr.pt.y == dest.y))
            return curr.dist;

        if (curr.w)
        { q.push({curr.pt, curr.dist, curr.w-1}); continue; }
 
        for (long long i = 0; i < 4; i++)
        {
            long long row = curr.pt.x + ro[i], 
                      col = curr.pt.y + co[i];             
            if (isValid(row, col) && (ta[row][col] != '#') && !visited[row][col])
            { visited[row][col] = true; q.push({{row, col}, curr.dist+o(row, col)+1, o(row, col) });}
        }
    } 
    return -1;
}

long long dtc(Point in)
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
 
        for (long long i = 0; i < 4; i++)
        {
            long long row = curr.pt.x + ro[i], 
                      col = curr.pt.y + co[i];             
            if (isValid(row, col) && (ta[row][col] != '#') && !visited[row][col])
            { visited[row][col] = true; q.push({ {row, col}, curr.dist+o(row, col)+1, o(row, col) }); }
        }
    } 
    return -1;
}

long long mchay (long long i, long long o, long long u)
{ return BFS(dib[i], dib[o]) + BFS(dib[o], dib[u]) + dtc(dib[u]); }

Point source;
long long chay(long long i, long long o, long long p)
{ return BFS(source, dib[i]) + min(mchay(i, p, o), mchay(i, o, p)); }

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("robot2.inp", "r", stdin);
    freopen("robot2.out", "w", stdout);

    cin >> n >> m >> p >> q >> t;
    for (long long j = 0; j < n; j++)
        for (long long i = 0; i < m; i++)
        {
            cin >> ta[j][i];
            if (ta[j][i] == 'X')
                source = {j, i};
            if (ta[j][i] == 'K')
                dib.push_back({j, i});
        }

    cout << min(chay(0, 1, 2), min(chay(1, 0, 2), chay(2, 0, 1))) + t << "\n";
    return 0;
}