#include <bits/stdc++.h>

using namespace std;
const unsigned modular = 1e9+7;
unsigned **arr, N, t, i;

int main () {
    cin >> N; arr = new unsigned*[N+1]; arr[0] = new unsigned[4]; fill(arr[0], arr[0]+4, 0);
    for (i = 1; i <= N && cin >> t; i++) {
        arr[i] = new unsigned[4];
        arr[i][1] = (arr[i-1][1] + t) % modular;
        arr[i][2] = (arr[i-1][2] + arr[i-1][1] * t) % modular;
        arr[i][3] = (arr[i-1][3] + arr[i-1][2] * t) % modular;
    }
    cout << arr[N][3];
}
