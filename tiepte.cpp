#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("TIEPTE.INP", "r", stdin);
    freopen("TIEPTE.OUT", "w", stdout);

    unsigned N, M, A, B, C;
    cin >> N >> M >> A >> B >> C;
    A--; B--; C--;

    unsigned arr[N][N][2]; 
    for (auto& ele0 : arr)
        for (auto& ele1 : ele0)
            for (auto& ele2 : ele1)
                ele2 = INT_MAX/2;

    for (unsigned i = 0; i < M; i++){
        unsigned x, y, l, p;
        cin >> x >> y >> l >> p;
        x--; y--;
        arr[x][y][0] = l;
        arr[x][y][1] = p;
    }

    for (unsigned i = 0; i < N; i++)
        for (unsigned j = 0; j < N; j++)
            for (unsigned z = 0; z < N; z++){
                arr[j][z][0] = min(arr[j][z][0], arr[j][i][0] + arr[i][z][0]);
                arr[j][z][1] = min(arr[j][z][1], max(arr[j][i][1], arr[i][z][1]));
            }

    cout << arr[A][B][0] + arr[B][C][0] << "\n" << max(arr[A][B][1], arr[B][C][1]);
    return 0;
}