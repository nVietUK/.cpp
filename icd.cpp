#include <bits/stdc++.h> 

using namespace std;
unsigned N, i, j, *A, x;

signed main() {
    cin >> N; A = new unsigned[N];
    for (i = 0; i < N && cin >> A[i]; i++) {
        x = A[i] / (N-i-1);
        A[i] -= x * (N-i-1);
        for (j = i+1; j < N; j++)
            A[i] += x;
        cout << A[i] << " ";
    }
}
