#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define notTERMINAL true
#define FILENAME ""
#define intf "%u"
int n, a, b, c;
struct point{
    unsigned toan, tin, id;
};

bool toan(const point &a, const point &b) {
    if ((a.toan) == (b.toan))
        return a.id < b.id;
    return a.toan > b.toan;
}
bool tin(const point &a, const point &b) {
    if ((a.tin) == (b.tin))
        return a.id < b.id;
    return a.tin > b.tin;
}
bool all(const point &a, const point &b) { 
    int t, v;
    if ((t = a.toan+a.tin) == (v = b.toan+b.tin))
        return a.id < b.id;
    return t > v;
}

priority_queue<int, vector<int>, greater<int>> ou;
void solve(bool comp(const point &a, const point &b), vector<point> &arr, int &a) {
    sort(arr.begin(), arr.end(), comp);
    for (int i = 0; i < a; i++) {
        ou.push(arr.begin()->id +1);
        arr.erase(arr.begin());
    }
}

signed main() {
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    scanf(intf intf intf intf, &n, &a, &b, &c);
    vector<point> arr(n);
    for (int i = 0; i < n; i++)
        scanf(intf, &arr[i].toan), arr[i].id = i;
    for (int i = 0; i < n; i++)
        scanf(intf, &arr[i].tin);
    solve(toan, arr, a);
    solve(tin, arr, b);
    solve(all, arr, c);
    while (ou.size()) {
        printf(intf "\n", ou.top());
        ou.pop();
    }
}