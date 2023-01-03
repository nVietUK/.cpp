#include <bits/stdc++.h>

using namespace std;

int main() 
{
    freopen("haidayso.inp", "r", stdin);
    freopen("haidayso.out", "w", stdout);
    unsigned m, n, k, input;
    cin >> m >> n >> k;

    vector<unsigned> tableA(m);
    while (m--) cin >> tableA[m];
    sort(tableA.begin(), tableA.end());

    priority_queue<unsigned, vector<unsigned>, less<unsigned>> tableK;
    while (n--)
    {
        cin >> input;
        for (auto a : tableA)
        {
            auto kq = a + input;
            if ((tableK.empty()) || (kq < tableK.top()) || (tableK.size() < k))
            {
                tableK.push(kq);
                if (tableK.size() > k) tableK.pop();
            }
            else 
                break;
        }
    }

    string output = "";
    for (;tableK.size();)
    {
        output = to_string(tableK.top()) + "\n" + output;
        tableK.pop();
    }
    cout << output;
}
