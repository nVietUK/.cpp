#include <algorithm>
#include <stdio.h>
#include <cstring>

using namespace std;
const int sz = 25;
long long A, B, D, K, F[sz][sz][sz];

long long DP(long long x) {
    int digit[sz], d = 0; long long res = 0;
    while (x) digit[++d] = x%10, x/=10;
    reverse(digit+1, digit+d+1); 
    for (int i = 1; i < d; i++) for (int j = 0; j <= 9; j++)
        for (int k = 0; k <= K; k++) res += F[i][j][k];
    long long C[sz][sz][sz][2];
    memset(C, 0, sizeof C);
    for (int j = 1; j <= digit[1]; j++) C[1][j][0][j < digit[1] ? 0 : 1] = 1;
    for (int i = 1; i <= d; i++) for (int j = 0; j <= 9; j++)
        for (int k = 0; k <= K; k++) for (int t = 0; t < 2; t++) {
            if (t == 0) 
                for (int next = 0; next <= 9; next++)
                    C[i+1][next][abs(next-j) <= D ? k+1 : k][0] += C[i][j][k][0];
            else 
                for (int next = 0; next <= digit[i+1]; next++)
                    C[i+1][next][abs(next-j) <= D ? k+1 : k][next == digit[i+1] ? 1 : 0] += C[i][j][k][t];
        }
    for (int j = 0; j <= 9; j++) for (int k = 0; k <= K; k++) for (int t = 0; t <= 1; t++)
        res += C[d][j][k][t];
    return res;
}

signed main() {
    scanf("%lld %lld %lld %lld", &A, &B, &D, &K); K = min(K, 15ll);
    for (int j = 1; j <= 9; j++) F[1][j][0] = 1;
    for (int i = 0; i <= 15; i++) for (int j = 0; j <= 9; j++) 
        for (int k = 0; k <= K; k++)
            for (int next = 0; next <= 9; next++)
                if (abs(j-next) <= D) F[i+1][next][k+1] += F[i][j][k];
                else F[i+1][next][k] += F[i][j][k];
    printf("%lld", DP(B)-DP(A-1));
}
