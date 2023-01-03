#include <bits/stdc++.h>
#define limax 10000 + 1
#define pp pair<unsigned, unsigned>

using namespace std;

// communist variables
    set<pp> from[limax];    
    unsigned n, ve[3], k, Sum;

bool vicho[limax];
int bfs(int x , int f){
        bool vi[limax]; memset(vi, false, sizeof(vi));
        unsigned ta[limax]; memset(ta, -1, sizeof(ta));
        priority_queue<pp, vector<pp>, greater<pp>> Wait;
        ta[x] = 0;
        Wait.push(pp(0,x));
        while(!Wait.empty()){
            int u = Wait.top().second;
            Wait.pop();
            if (vi[u]) continue;
            if (u == f)
                break;
		    vi[u] = true;
            for(auto& temp3 : from[u]){
                int w = temp3.first;
			    int v = temp3.second;
                if (ta[v] > ta[u]+w){
                    ta[v] = ta[u]+w;
                    Wait.push(pp(ta[v],v));
                }
            }
        }
    return ta[f];
}

unsigned run()
{
    sort(ve, ve+k);
    unsigned ou = -1;
    do 
    {
        unsigned and_another_temp = bfs(1,ve[0]);
        for (int i = 0; i < k-1; i++){
            and_another_temp += bfs(ve[i],ve[i+1]);
        }
        and_another_temp += bfs(ve[k-1],n) + Sum;
        ou = min(and_another_temp, ou);
    } while (next_permutation(ve, ve+k));
    return ou;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("khobau.inp", "r", stdin);
    freopen("khobau.out", "w", stdout);
#endif
    
    unsigned m, x, u, v, l;
    cin >> n >> m >> x;
    while (m-- && cin >> u >> v >> l)
    {
        from[u].insert(pp(l, v));
        from[v].insert(pp(l, u));
    }
    memset(vicho, false, sizeof(vicho));
    k = x; unsigned i = 0;
    while (x-- && cin >> u >> v)
    {
        ve[i++] = u;
        Sum += v;
    }
    
    cout << run();
}