#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> get(unsigned n) {
    vector<string> ans;
    if (n == 1) { ans.push_back("0"); ans.push_back("1"); return ans; }
    vector<string> pre = get(n-1);
    for (auto e : pre) 
        ans.push_back('0'+e);
    reverse(pre.begin(), pre.end());
    for (auto e : pre)
        ans.push_back('1'+e);
    return ans;
}

signed main() {
    unsigned n; scanf("%u", &n); 
    for (auto e : get(n)) printf("%s\n", e.c_str());
}
