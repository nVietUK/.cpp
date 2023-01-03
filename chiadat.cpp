#include <bits/stdc++.h>

using namespace std;

unsigned 
    arr[505][505], 
    X[505], Y[505];

unsigned mid(unsigned in[], unsigned N) {

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("chiadat.inp", "r", stdin);
    freopen("chiadat.out", "w", stdout);
    
    unsigned N, in;
    for (unsigned i = 0; i < N; i++) {
        for (unsigned j = 0; j < N; j++) {
            cin >> arr[i][j];
            arr[N][j] += arr[i][j];
            arr[i][N] += arr[i][j];
        }
    }

    x[0] = arr[0][N]; y[0] = arr[N][0];
    for (unsigned i = 1; i < N; i++) {
        x[i] = arr[i][N] + x[i-1];
        y[i] = arr[N][i] + y[i-1];
    }

    unsigned 
        x = mid(X, N), y = mid(Y, N);
    
}