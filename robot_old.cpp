#include <bits/stdc++.h>
#define s 's'

using namespace std;

struct robot
{ int x, y; char duong; };

// communist variables
    char ta[101][101], di; 
    bool pa[101][101];
    unsigned de[62]; 
    string lenh;
    stack<robot> wa;
    unsigned n, m, k, ou = 0, robo = 0;

unsigned short con(char& in)
{
    if (in == 'F')
        return 1;
    if (in == 'L')
        return 0;
    if (in == 'R')
        return 2;
    return 3;
}

void chay()
{
    robot tp = wa.top(); wa.pop(); unsigned lenhX = 0;
    unsigned ha[n][m][4]; memset(ha, false, sizeof(ha));
    while (true)
    {
        di = lenh[(lenhX++) % lenh.size()];
        if (di == 'F')
        {   if (tp.duong == 'F')
            {   if (tp.x - 1 >= 0 && ta[tp.x-1][tp.y] != '#')
                    tp.x--; else continue; }
            else
            if (tp.duong == 'L')
            {   if (tp.y - 1 >= 0 && ta[tp.x][tp.y-1] != '#')
                    tp.y--; else continue; }   
            else 
            if (tp.duong == s)
            {   if (tp.x + 1 < n && ta[tp.x+1][tp.y] != '#')
                    tp.x++; else continue; }
            else 
            if (tp.duong == 'R')
            {   if (tp.y + 1 < m && ta[tp.x][tp.y+1] != '#')
                    tp.y++; else continue; }
            if (
                ta[tp.x][tp.y] == 'E' || 
                (
                    tp.duong == 'F' &&
                    pa[tp.x][tp.y]
                )
            )
            { ou++; return;}
        }
        else 
        {
            switch (tp.duong)
            {
            case 'F':
                tp.duong = di;
                break;
            case 'L':
                {   switch (di)
                    {   case 'L': tp.duong = s; break;
                        case 'R': tp.duong = 'F'; break; }}
                break;        
            case s:
                {   switch (di)
                    {   case 'L': tp.duong = 'R'; break;
                        case 'R': tp.duong = 'L'; break; }}
                break;        
            case 'R':
                {   switch (di)
                    {   case 'L': tp.duong = 'F'; break;
                        case 'R': tp.duong = s; break; }}
                break;     
            }
        }  
        if (ha[tp.x][tp.y][con(tp.duong)] == (lenhX-1) % lenh.size()+1) 
            return;
        ha[tp.x][tp.y][con(tp.duong)] = (lenhX-1) % lenh.size()+1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);
#endif
    memset(de, 0, sizeof(de));
    memset(pa, false, sizeof(pa));

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> ta[i][j];
            if (ta[i][j] == '.')
            {   wa.push({i, j, 'F'});
                robo++;}
        }
    cin >> lenh;

    while (wa.size()) chay();
    if (ou == robo)
        cout << "YES";
    else 
        cout << ou+1;
}