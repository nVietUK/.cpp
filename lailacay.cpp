#include <algorithm>
#include <stdio.h>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
const unsigned sz = 710;

int n,
    l[sz][sz],
    k[sz][sz],
    dy[] = {-1, 0},
    dx[] = {0, -1};
struct event { int x1, y1, x2, y2, k, l; };
struct change {
    pii B, old_parent, A;
    int old_size;
};
struct union_find {
    pii parent[sz][sz];
    int size[sz][sz];
    vector<change> changes;

    union_find() {
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++) 
                parent[i][j] = {-1, -1}, size[i][j] = 1;
    }

    pii findparent(int x, int y, bool allow=true) {
        if (parent[x][y].first == -1) return {x, y};
        pii new_parent = findparent(parent[x][y].first, parent[x][y].second);
        if (allow == false)
            changes.push_back({pii(x, y), parent[x][y], {-1, -1}, -1});
        return parent[x][y] = new_parent;
    }

    int merge_sets(int x1, int y1, int x2, int y2, bool permanent) {
        pii A = findparent(x1, y1, permanent);
        pii B = findparent(x2, y2, permanent);
        if (A == B) return size[A.first][A.second];
        if (size[A.first][A.second] < size[B.first][B.second]) 
            swap(A, B);
        if (permanent == false)
            changes.push_back({B, parent[B.first][B.second], A, size[A.first][A.second]});
        size[A.first][A.second] += size[B.first][B.second];
        parent[B.first][B.second] = A;
        return size[A.first][A.second];
    }

    void restore() {
        reverse(changes.begin(), changes.end());
        for (const change &c : changes) {
            parent[c.B.first][c.B.second] = c.old_parent;
            if (c.A.first != -1)
                size[c.A.first][c.A.second] = c.old_size;
        }
        changes.clear();
    }
} U;
vector<event> events;

void process_neighbours(int x1, int y1, int x2, int y2) {
    if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) return;
    int k_diff = k[x2][y2] - k[x1][y1],
        l_diff = l[x1][y1] - l[x2][y2];
    if (k_diff == 0) {
        if (l_diff == 0) U.merge_sets(x1, y1, x2, y2, true);
        return;
    }
    if (k_diff < 0) 
        l_diff = -l_diff,
        k_diff = -k_diff;
    else 
    if (l_diff < 0) return;
    events.push_back({x1, y1, x2, y2, k_diff, l_diff});
}

bool cmp(const event &A, const event &B) {
    return (long long)A.l * B.k < (long long)B.l * A.k;
}

signed main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) for (int j = 0; j < n && scanf("%d", l[i]+j); j++);
    for (int i = 0; i < n; i++) for (int j = 0; j < n && scanf("%d", k[i]+j); j++) {
        for (int z = 0; z < 2; z++)
            process_neighbours(i, j, i+dx[z], j+dy[z]); 
    };
    
    int ans = 0; for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
        U.findparent(i, j), ans = max(ans, U.size[i][j]);

    sort(events.begin(), events.end(), cmp);
    for (int i = 0; i < events.size(); i++) {
        const event &e = events[i];
        ans = max(ans, U.merge_sets(e.x1, e.y1, e.x2, e.y2, false));
        if (i + 1 == events.size() || cmp(e, events[i+1]))
            U.restore();
    }
    printf("%d", ans);
}
