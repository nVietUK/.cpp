#include <bits/stdc++.h>
#define liMax 101

using namespace std;

struct Point 
{ int x, y; };

struct queueNode
{ Point pt; unsigned dist; };

// communist variables
    int x, y;
    bool ta[liMax][liMax];

int 
    ro[] = {-1, 0, 0, 1},
    co[] = {0, -1, 1, 0};
bool isValid(int row, int col)
{ return (row > 0) && (row < liMax) && (col > 0) && (col < liMax); }
bool visited[101][101]; 
unsigned BFS(int x, int y)
{
    unsigned ou = 0;
    visited[x][y] = true;
 
    for (int i = 0; i < 4; i++)
        {
            int row = x + ro[i], 
                col = y + co[i];
            if (isValid(row, col))
            {
                if (ta[row][col])
                    ou++;
                else if (!visited[row][col])
                    ou += BFS(row, col);
            }
        } 
    return ou;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("chuvi.inp", "r", stdin);
    freopen("chuvi.out", "w", stdout);
#endif
    
    unsigned n, ou = 0; cin >> n;
    memset(ta, false, sizeof(ta));
    memset(visited, false, sizeof(visited));
    while (n-- && cin >> x >> y)
        ta[x][y] = true;
    for (int i = 1; i < liMax; i++)
        for (int j = 1; j < liMax; j++)
            if (!visited[i][j] && !ta[i][j])
            {
                cout << BFS(i, j); return 0;
            }
}