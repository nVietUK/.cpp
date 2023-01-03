#include <bits/stdc++.h>
#define MAX_N 1000 + 1
#define pp pair<int, int>

using namespace std;

unsigned N, M, Y, P, Q, K, A[MAX_N], B[MAX_N], C[MAX_N];
int i;

vector<vector<pp>> diem;

void readStore(unsigned* in, unsigned li){
    unsigned a, b; 
    for (i = 0; i < li; i++){
        cin >> a >> b;
        in[a] = b;
    }
}

unsigned d[MAX_N]; 
void minG(){
    priority_queue<pp, vector<pp>, greater<pp>> thisqueue; 
    bool passed[MAX_N];
    memset(d, INT_MAX, sizeof(d)); 
    memset(passed, false, sizeof(passed));
    d[Y] = 0;
    thisqueue.push(pp(0, Y));
    while (thisqueue.size()){
        auto curr = thisqueue.top();
        thisqueue.pop();

        if (passed[curr.second])
            continue;
        passed[curr.second] = true;

        for (i = 0; i < diem[curr.second].size(); i++){
            auto next = diem[curr.second][i];
            if (d[next.second] > d[curr.second] + next.first){
                d[next.second] = d[curr.second] + next.first;
                thisqueue.push(pp(d[next.second], next.second));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("DVGH.INP", "r", stdin);
    freopen("DVGH.OUT", "w", stdout);

    cin >> N >> M >> Y >> P >> Q >> K;
    unsigned a, b, c; diem.resize(N+1);
    for (i = 0; i < M; i++){
        cin >> a >> b >> c;
        diem[a].push_back(pp(c, b));
        diem[b].push_back(pp(c, a));
    }
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    readStore(A, P);
    readStore(B, Q);
    readStore(C, K);

    minG();

    P = Q = K = 0;
    unsigned AB = INT_MAX, AC = INT_MAX, BC = INT_MAX, ABC = INT_MAX;
    a = b = c = INT_MAX;
    for (i = 1; i <= N; i++)
    {
        if (A[i]){
            a = min(a, A[i] + d[i]);
            if (B[i] && C[i])
                ABC = min(ABC, A[i] + B[i] + C[i] + d[i]);
            if (B[i])
                AB = min(AB, A[i] + B[i] + d[i]);
            if (C[i])
                AC = min(AC, A[i] + C[i] + d[i]);
        }
        if (B[i]){
            b = min(b, B[i] + d[i]);
            if (C[i])
                BC = min(BC, B[i] + C[i] + d[i]);
        }
        if (C[i])
            c = min(c, C[i] + d[i]);
    }
    cout << a << "\n" << min(ABC, min(AB + c, min(AC + b, BC + a)));
}
