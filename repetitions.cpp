#include <ios>
#include <iostream>
#include <string.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    char s[1000000]; unsigned ou = 0;
    cin >> s; for (unsigned i = 0; i < strlen(s); i++) {
        unsigned j = i; while (s[j] == s[j+1]) j++;
        ou = max(ou, j-i+1);
        i = j;
    }
    cout << ou;
}
