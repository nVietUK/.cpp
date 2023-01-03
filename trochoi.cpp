#include <bits/stdc++.h>
using namespace std;
 
struct Point 
{ int x, y; };

struct queueNode
{ Point pt; int dist; };

int 
    ro[] = {-1, 0, 0, 1},
    co[] = {0, -1, 1, 0};
int n, m, p, q, t;
char ta [100][100];
vector<Point> dib;

bool isValid(int row, int col)
{ return (row >= 0) && (row < n) && (col >= 0) && (col < m);}

unsigned BFS(Point& src, Point& dest)
{
    bool visited[n][m]; memset(visited, false, sizeof(visited));
    visited[src.x][src.y] = true;
 
    queue<queueNode> q; while (q.size()) q.pop(); q.push({src, 0});  
 
    while (!q.empty())
    {
        queueNode curr = q.front(); q.pop(); 
        if ((curr.pt.x == dest.x) && 
            (curr.pt.y == dest.y))
            return curr.dist;

        for (int i = 0; i < 4; i++)
        {
            int row = curr.pt.x + ro[i], 
                      col = curr.pt.y + co[i];             
            if (isValid(row, col) && (ta[row][col] != '#') && !visited[row][col])
            { visited[row][col] = true; q.push({{row, col}, curr.dist+1});}
        }
    } 
    return -1;
}

Point source, finni;
unsigned chay(Point& in)
{ return BFS(source, in); }

long long chay2(long long i, long long o)
{ return BFS(source, dib[i]) + BFS(dib[i], dib[o]) + BFS(dib[o], finni); }


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("trochoi.inp", "r", stdin);
    freopen("trochoi.out", "w", stdout);

    unsigned g;
    memset(ta, '#', sizeof(ta));
    cin >> n >> m >> g;
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m; i++)
        {
            cin >> ta[j][i];
            if (ta[j][i] == 'B')
                source = {j, i};
            if (ta[j][i] == 'K')
                dib.push_back({j, i});
            if (ta[j][i] == 'C')
                finni = {j, i};
        }

    if (g == 1)
    {
        unsigned ou = -1;
        for (auto& tpD : dib)
            ou = min(ou, chay(tpD));
        cout << ou;
    }
    else 
    {
        cout << min(chay2(0, 1), chay2(1, 0));
    }
    return 0;
}