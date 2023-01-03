#include <bits/stdc++.h>

using namespace std;

struct node { node *next['z']; char c=0; } tree;
string q[1000009], s; map<string

void build(unsigned id, string &s, node *tree) {
    if (id == s.size()) return;
    if (tree->next[s[id]] == NULL) {
        tree->next[s[id]] = new node;
        tree->next[s[id]]->c = s[id];
    }
    build(id+1, s, tree->next[s[id]]);
}

unsigned solve(unsigned id, unsigned deep, bool isCheck, string &s, node *tree) {
    if (tree == NULL || tree->c == '\000') return (isCheck) ? 0 : 1e9; 
    unsigned a = solve(id, deep+1, true, s, tree->next[s[id]]) + 1,
             b = solve(id+1, deep+1, false, s, tree->next[s[id+1]]);
    return min(a, b);
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    unsigned N; cin >> N; for (unsigned i = 1; i <= N && cin >> s; i++) 
        q[i] = s, s+='\000', build(0, s, &tree);

    for (unsigned i = 1; i <= N; i++) 
        cout << solve(0, 0, true, q[i], tree.next[q[i][0]]) << '\n';
}

