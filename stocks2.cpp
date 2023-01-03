#include <bits/stdc++.h>
#define maxn 50005

using namespace std;

unsigned trace[maxn];

unsigned traceLength = 1;
int findPos(const unsigned &in, const unsigned arr[]) {
    unsigned b = 0, f = traceLength;
    while (b+1 != f) {
        unsigned m = (b + f) / 2;
        if (!(arr[trace[m]] > arr[in]))
            f = m;
        else 
            b = m;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("stocks2.inp", "r", stdin);
    freopen("stocks2.out", "w", stdout);

    unsigned n; cin >> n;
    unsigned arr[n+1]; arr[n] = INT_MAX, trace[0] = n;

    for (auto& ele : arr) cin >> ele;
    
    for (int i = n-1; i >= 0; i--) {
        int p = findPos(i, arr);
        if (arr[trace[p]] > arr[i]) {
            trace[p+1] = i;
            if (p == traceLength-1)
                traceLength++;
        }
    }
    cout << traceLength-1;
}