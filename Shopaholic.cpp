#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    unsigned n, input;
    cin >> n;

    vector<unsigned> table;
    for (;n--;)
    {
        cin >> input;
        table.push_back(input);
    }

    sort(table.begin(), table.end());
    reverse(table.begin(), table.end());

    unsigned long long output = 0;
    for (n = 0 ;n < table.size(); n += 3)
        output += table[n+ 2];

    cout << output;
}