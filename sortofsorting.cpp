#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool mySort(string a, string b)
{
    auto output = a.substr(0, 2).compare(b.substr(0, 2));
    return (output < 0);
}

int main()
{
    unsigned input;
    string inputString;
    while (scanf("%d", &input))
    {
        if (!(input))
            return 0;
        
        vector<string> table;
        getline(cin, inputString);
        for (;input--;)
        {
            getline(cin, inputString);
            table.push_back(inputString);
        }

        stable_sort(table.begin(), table.end(), mySort);
        for (;table.size();)
        {
            cout << table[0] << endl;
            table.erase(table.begin());
        }

        cout << endl;
    }
}