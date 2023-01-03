#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

signed main() {
	int x, n, p; scanf("%d%d", &x, &n);

	set<int> l{0, x};
	multiset<int> d{x};
	while (n-- && scanf("%d", &p)) {
		auto it1 = l.upper_bound(p), it2 = it1; it2--;
		d.erase(d.find(*it1-*it2));
		d.insert(p-*it2), d.insert(*it1-p);
		l.insert(p);

		printf("%d ", *prev(d.end()));
	}
}
