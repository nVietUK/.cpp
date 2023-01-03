#include <bits/stdc++.h>

using namespace std;

int n, m;
int minarr(int _arr[], bool _set[]) {
     int min = INT_MAX, min_index;
     for (int v = 0; v < n; v++)
          if (_set[v] == false && _arr[v] < min)
               min = _arr[v], min_index = v;
     return min_index;
}

int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL); cout.tie(NULL);

	freopen("MST.inp","r",stdin);
	freopen("MST.out","w",stdout);

	cin >> n >> m;
     int a[n][n], Trace[n], arr[n], u, v, e;
     bool set[n];
     memset(a, INT_MAX, sizeof(a));
     memset(arr, INT_MAX, sizeof(arr));
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> e;
		a[u][v] = a[v][u] = e;
	}
     arr[0] = 0;
     Trace[0] = -1;
     memset(set, false, sizeof(set));
     e = n; int W = 0;
     while (e > 0) {
          v = minarr(arr, set) ;
          set[v] =true;
          W += arr[v]; 
          e--;
	     for (u = 0; u < n; u++)
	          if (!set[u]){ 
                    int w = a[u][v] ;
                    if (w < arr[u] ){
		               arr[u] = w ;
                         Trace[u] =v;
                    }    
               }	 
     }
     cout << W << "\n";
     for (int v = 1; v < n; v++)
          cout << Trace[v] << " "<< v << "\n"; 
}
