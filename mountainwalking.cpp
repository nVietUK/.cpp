#include <bits/stdc++.h>

using namespace std;
struct uuuu {unsigned a, b, c, d;};
unsigned N, i, j, **arr, x, y;

unsigned sizen(uuuu &p) { return p.b - p.a; }

template <class T> struct comp {
  bool operator() (const T& x, const T& y) const {return x.b - x.a > y.b - y.a;}
  typedef T first_argument_type;
  typedef T second_argument_type;
  typedef bool result_type;
};

int ha[4] = {0, 0, 1, -1},
    co[4] = {-1, 1, 0, 0};

bool **pass;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N; arr = new unsigned*[N+1]; pass = new bool*[N+1];
    for (i = 1; i <= N; i++) {
        arr[i] = new unsigned[N+1]; pass[i] = new bool[N+1];
        for (j = 1; j <= N; j++) 
            cin >> arr[i][j], pass[i][j] = false;
    }

    priority_queue<uuuu, vector<uuuu>, comp<uuuu>> q;
    q.push({arr[1][1], arr[1][1], 1, 1});

    while (q.size()) {
        uuuu curr = q.top(); q.pop();

        if (curr.c == N && curr.d == N) { cout << sizen(curr); return 0; }

        if (pass[curr.c][curr.d])
            continue;
        pass[curr.c][curr.d] = true;

        for (i = 0; i < 4; i++) {
            x = curr.c + ha[i], y = curr.d + co[i];
            if (x > 0 && x <= N && y > 0 && y <= N)
                q.push({min(curr.a, arr[x][y]), max(curr.b, arr[x][y]), x, y});
        }
    }
}
