#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool mySort(string& a, string& b)
{
    if (a[a.size() - 4] == b[b.size() - 4])
    {
        auto aH = a.substr(0, a.find(":"));
        if (aH == "12") aH = "0";
        auto bH = b.substr(0, b.find(":"));
        if (bH == "12") bH = "0";

        if (aH.size() == bH.size())
        {
            if (aH == bH)
            {
                auto aH = a.substr(a.find(":") + 1, 2);
                auto bH = b.substr(b.find(":") + 1, 2);
            } 
            return aH.compare(bH) < 0;
        }
        else 
            return aH.size() < bH.size();
    }
    else 
        return a[a.size() - 4] < b[b.size() - 4];
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

        sort(table.begin(), table.end(), mySort);
        for (;table.size();)
        {
            cout << table[0] << endl;
            table.erase(table.begin());
        }

        cout << endl;
    }
}