#include <bits/stdc++.h>

using namespace std;
char S[300005], T[105];
struct TrieNode {
    int next[26], nfinish;
} trie[4005*105];
const unsigned modular = 1337377;
unsigned nnode=1, u, j, t, l, f[300005], i, N;

void insert(char * s) {
    u=0; for (int i = strlen(s)-1; i>=0; i--) {
        t = s[i] - 0x61;
        if (trie[u].next[t]==0) trie[u].next[t] = nnode++;
        u = trie[u].next[t];
    }
    trie[u].nfinish=1;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> (S+1) >> N;
    for (i = 0; i < N && cin >> T; i++) 
        insert(T);

    f[0]=1; l = strlen(S+1);
    for (i=1; i <= l; i++) {
        u=0; for (j = i; j && trie[u].next[S[j] - 0x61]; j--) 
            if (trie[u = trie[u].next[S[j] - 0x61]].nfinish)
                f[i] = (f[j-1]+f[i]) % modular;
    }
    cout << f[l];
}
