#include <bits/stdc++.h>

using namespace std;

int main()
{
	int L; while(scanf("%d", &L) && L)
    {
		int DP[52][52], m[52], n, i, j, k;

		scanf("%d",&n); m[0] = 0; m[n+1] = L;
		for (i = 1; i <= n; i++) scanf("%d",&m[i]);
		for (i = 0; i <= n; i++) DP[i][i+1]=0;

		for (j = 2; j <= n + 1; j++)
			for(i = j-2; i >= 0; i--){
				DP[i][j] = INT_MAX;
				for (k = i+1; k < j; k++)
					DP[i][j] = min(DP[i][j], DP[i][k]+DP[k][j]+m[j]-m[i]);
			}
		printf("%d.\n",DP[0][n+1]);
	}
	return 0;
}
