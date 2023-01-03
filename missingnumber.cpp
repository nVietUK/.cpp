#include <ios>
#include <iostream>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    unsigned N, inp; cin >> N; long long t = (long long)N*(N+1)/2;
    for (unsigned i = 1; i < N && cin >> inp; i++) t -= inp;
    cout << t;
}
