#include <algorithm>
#include <climits>
#include <cstddef>
#include <ios>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

unsigned N, L, inp, o, t, ou;
std::set<unsigned> b;

void findM(std::set<unsigned> a[21][2], unsigned d, std::set<unsigned> s, unsigned c) {
    if (s.size() == N) ou = std::min(ou, c);
    for (unsigned i = d+1; i < L; i++) {
        std::set_union(s.begin(), s.end(), a[d][0].begin(), a[d][0].end(), std::inserter(b, b.begin())); findM(a, i, b, c+1);
        std::set_union(s.begin(), s.end(), a[d][1].begin(), a[d][1].end(), std::inserter(b, b.begin())); findM(a, i, b, c+1);
    }
}

bool solve() {
    std::cin >> N >> L; std::set<unsigned> a[21][2];

    for (unsigned i = 1; i <= N && std::cin >> inp; i++) {
        t = inp, o = 0; while (inp) 
            a[o++][inp&1].insert(i), inp>>=1;
    }

    ou = INT_MAX; for (unsigned i = 0; i < L; i++) findM(a, i, {}, 1); std::cout << ou << '\n';

    return true;
}

signed main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    unsigned t; std::cin >> t; while (t-- && solve());
}
