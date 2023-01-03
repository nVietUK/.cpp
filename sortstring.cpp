#include <cctype>
#include <ios>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>

using namespace std;

bool comp(char a, char b) {
    if (isupper(a) == isupper(b))
        return a > b;
    return isupper(a) > isupper(b);
}

signed main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    string s; cin >> s;
    sort(s.begin(), s.end(), comp);
    cout << s;
}
