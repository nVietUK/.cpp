#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>

using namespace std;
map<string, string> qa;

string input() {
    char c; while (scanf("%c", &c) && c != '"');
    string s = ""; while (scanf("%c", &c) && c != '"') s.push_back(c);
    return s;
}

int main() {
    int n, m; string t; scanf("%d %d", &n, &m);
    while (n--) t = input(), qa[t] = input();
    while (m--) printf("%s\n", qa[input()].c_str());
    return 0;
}
