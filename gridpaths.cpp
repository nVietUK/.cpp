#include <stdio.h>
#include <algorithm>

using namespace std;

unsigned p[48];
bool onp[9][9];
int dr[4] = {-1, 0, 1, 0},
    dc[4] = {0, 1, 0, -1};

int tryP(int idx, int cR, int cC) {
    if (
            (
             (onp[cR][cC-1] && onp[cR][cC+1]) && 
             (!onp[cR-1][cC] && !onp[cR+1][cC])
             ) || 
            (
             (onp[cR-1][cC] && onp[cR+1][cC]) &&
             (!onp[cR][cC-1] && !onp[cR][cC+1])
            )
       ) {
        return 0;
    }

    if (cR == 7 && cC == 1) {
        if (idx == 48) return 1;
        return 0;
    }

    if (idx == 48) return 0;

    int res = 0; onp[cR][cC] = true;

    if (p[idx] < 4) {
        int nR = cR + dr[p[idx]],
            nC = cC + dc[p[idx]];
        if (!onp[nR][nC]) res += tryP(idx+1, nR, nC);
    }
    else {
        for (int i = 0; i < 4; i++) {
            int nR = cR + dr[i],
                nC = cC + dc[i];
            if (onp[nR][nC]) continue;
            res += tryP(idx+1, nR, nC);
        }
    }
    onp[cR][cC] = false;
    return res;
}

signed main() {
    char s[48]; scanf("%s", s);

    for (unsigned i = 0; i < 48; i++) {
        char c = s[i];
        if (c == 'U') p[i]=0;
        else if (c == 'R') p[i]=1;
        else if (c == 'D') p[i]=2;
        else if (c == 'L') p[i]=3;
        else p[i]=4;
    }

    fill(onp[0], onp[0]+81, true);
    for (unsigned i = 1; i <= 7; i++) for (unsigned j = 1; j <= 7; j++)
        onp[i][j] = false;

    printf("%d", tryP(0, 1, 1));
}
