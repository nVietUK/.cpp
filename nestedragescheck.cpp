#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cstring>

using namespace std;
const int N = 2e5+1;

struct obj {int x, y, i;
    obj(int x = 0, int y = 0, int i = 0) : x(x), y(y), i(i) {};
    bool operator<(const obj &x) {
        if (this->x == x.x)
            return this->y > x.y;
        return this->x < x.x;
    }
};
map<int, int> mp;
int T[N+1] = {0}, n;

void update(int n, int x, int val) {
    for (; x <= n; x += x&-x) T[x] += val;
}

int query(int x) {
    int s = 0; for (; x > 0; x -= x&-x) s += T[x];
    return s;
}

int main() {
    scanf("%d", &n);
    set<int> b; vector<obj> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &v[i].x, &v[i].y), v[i].i = i, b.insert(v[i].y);
    int cnt = 0; for (auto e : b)
        mp[e] = ++cnt;
    sort(v.begin(), v.end());
    update(cnt, mp[v[n-1].y], 1);
    int ans[n] = {0};
    for (int i = n-2; i >= 0; i--) {
        ans[v[i].i] += query(mp[v[i].y]);
        update(cnt, mp[v[i].y], 1);
    }

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    memset(ans, 0, sizeof ans);
    memset(T, 0, sizeof T);
    update(cnt, 1, 1);
    update(cnt, mp[v[0].y]+1, -1);
    for (int i = 1; i < n; i++) {
        ans[v[i].i] += query(mp[v[i].y]);
        update(cnt, 1, 1);
        update(cnt, mp[v[i].y]+1, -1);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
}
