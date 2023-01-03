#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct pas { int x, y, id;
    pas(int x = 0, int y = 0, int id = 0) : x(x), y(y), id(id) {};
    bool operator<(const pas &x) {
        if (this->x == x.x) {
            if (this->y == x.y)
                return this->id < x.id;
            return this->y < x.y;
        }
        return this->x < x.x;
    }
};
vector<pas> v;

int main() {
    int n, x, y; unsigned ou = 0; scanf("%d", &n); for (int i = 0; i < n && scanf("%d%d", &x, &y); i++) {
        v.push_back(pas(x, 0, i));
        v.push_back(pas(y, 1, i));
    }
    sort(v.begin(), v.end());
    int c = 0, ans[n]; vector<int> av;
    for (auto [x, y, i] : v) 
        if (y) 
            c--, av.push_back(ans[i]);
        else {
            c++; 
            if (av.empty()) {ans[i]=c;}
            else {ans[i] = av.back(), av.pop_back();}
        }
    printf("%d\n", *max_element(ans, ans+n));
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
}
