#include <bits/stdc++.h>

using namespace std;

int main() 
{
    unsigned in, ou = 0;
    cin >> in;

    vector<unsigned> ta(in);
    while (in--) 
    { cin >> ta[in]; ou += ta[in]; }
    sort(ta.begin(), ta.end()); reverse(ta.begin(), ta.end());

    in = ta.size() / 3; while (in--) ou -= ta[(in + 1) * 3 - 1];

    cout << ou;
}