#include <bits/stdc++.h>
#define pp pair<int, int>
#define limax 1010
#define Queue priority_queue<pp, vector<pp>, greater<pp>>

using namespace std;

// communist variables
    set<pp> Node[limax];
    pp bill[3][limax];
    bool vi[limax];

void dj(pp (&in)[limax], Queue& wait)
{
    memset(vi, false, sizeof(vi));
    while (wait.size()) {
        auto curr = wait.top(); wait.pop();
        if (vi[curr.second])
            continue;
        vi[curr.second] = true;
        for (auto& nhanh : Node[curr.second])
            if (in[nhanh.second].first > (curr.first + nhanh.first))
            {
                in[nhanh.second].first = curr.first + nhanh.first;
                in[nhanh.second].second = in[curr.second].second;
                wait.push(pp(in[nhanh.second].first, nhanh.second));
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("muaqua.inp", "r", stdin);
    freopen("muaqua.out", "w", stdout);
#endif
    
    int n, m, x, y, z, s, q, a, b, c;
    cin >> n >> m >> x >> y >> z >> s >> q;

    while (m-- && cin >> a >> b >> c) 
    {
        Node[a].insert(pp(c, b));
        Node[b].insert(pp(a, c));
    }

    Queue wait; 
    for (auto& bill : bill)
        fill(bill, bill + limax, pp(INT_MAX, 0));

    while (x-- && cin >> a >> b) {
        wait.push(pp(b, a));
        bill[0][a] = pp(b, a);
    }
    dj(bill[0], wait);

    while (y-- && cin >> a >> b) {
        wait.push(pp(b, a));
        bill[1][a] = pp(b, a);
    }
    dj(bill[1], wait);

    while (z-- && cin >> a >> b) {
        wait.push(pp(b, a));
        bill[2][a] = pp(b, a);
    }
    dj(bill[2], wait);

    long long ou = 0; memset(vi, false, sizeof(vi));
    if (q == 1 || q == 4 || q == 5 || q == 7) {
        if (!vi[bill[0][s].second]) {
            ou += bill[0][s].first;
            vi[bill[0][s].second] = true;
        }
        else
            ou += bill[0][bill[0][s].second].first;
    }
    if (q == 2 || q == 4 || q == 6 || q == 7) {
        if (!vi[bill[1][s].second]) {
            ou += bill[1][s].first;
            vi[bill[1][s].second] = true;
        }
        else 
            ou += bill[1][bill[1][s].second].first;
    }
    if (q == 3 || q == 5 || q == 6 || q == 7) {
        if (!vi[bill[2][s].second]) {
            ou += bill[2][s].first;
            vi[bill[2][s].second] = true;
        }
        else 
            ou += bill[2][bill[2][s].second].first;
    }
    
    cout << ou;
}