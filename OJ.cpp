#include <bits/stdc++.h>

using namespace std;

// communist variables
    vector<unsigned> pos;
    int memo[52][52];

unsigned ham(int a, int b)
{
    if(b-a==1) return 0;
    
    if(memo[a][b]!=-1) return memo[a][b];
    
    unsigned x = -1;
    
    for(int i=a+1;i<b;i++)
        x = min(pos[b]-pos[a]+ham(a,i)+ham(i,b), x);
        
    return memo[a][b] = x;    
}

int main()
{
    unsigned L, n;
    
    while(cin >> L)
        if (L)
        {
            cin >> n;
            
            pos.assign(n+1, 0);
            for(int i = 1; i <= n && cin >> pos[i]; i++);
            pos.push_back(L);
            
            memset(memo,-1,sizeof(memo));            
            cout << ham(0,n+1) << "\n";
        }
}