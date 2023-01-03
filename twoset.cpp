#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    long long n; cin >> n; 
    long long nn = n*(n+1)/2;
    if (nn%2) cout << "NO";
    else {
        cout << "YES" << '\n';
        set<long long> s1, s2;
        long long t = n, target = nn/2;
        for (unsigned i = 1; i <= n; i++) s1.insert(i);
        while (s1.count(target)==0) {
            target-=t;
            s2.insert(t);
            s1.erase(t);
            t--;
        }
        s1.erase(target);
        s2.insert(target);
        cout << s1.size() << '\n';
        for (long long i : s1) cout << i << ' ';
        cout << '\n' << s2.size() << '\n';
        for (long long i : s2) cout << i << ' ';
    }
}
