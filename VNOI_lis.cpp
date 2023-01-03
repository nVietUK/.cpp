#include <climits>
#include <iostream>

using namespace std;
unsigned arr[200009], val[200009], trace[200009], i, l=0, m, e, b, nl;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    unsigned N; cin >> N;
    for (i = 1; i <= N; i++) 
        cin >> arr[i];
    val[N+1] = INT_MAX; val[0] = 0;
    trace[N+1] = 0;

    for (i = N; i > 0; i--) {
        unsigned b = 1; e = l+1;
        while (b < e) {
            m = l + (e-b)/2;
            if (arr[trace[m]] > arr[i])
                e = m;
            else 
                b = m+1;
        }
        nl=b;
        val[i] = trace[nl-1];
        trace[m]=i;

        if (nl > l)
            l = nl;
    }
}
