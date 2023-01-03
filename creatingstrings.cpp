#include <ios>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s; sort(s.begin(), s.end()); vector<string> a;
    do {
        a.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    printf("%lu\n", a.size());
    for (auto e : a) 
        printf("%s\n", e.c_str());
}
