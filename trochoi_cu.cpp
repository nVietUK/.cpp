#include <iostream>
#include <vector>

using namespace std;

vector<unsigned> genTable(unsigned input)
{
    vector<unsigned> output;
    input++;
    for (;input--;)
    {
        output.insert(output.begin(), input);
    };
    output.erase(output.begin());
    return output;
}

int main() 
{
    freopen("trochoi.inp", "r", stdin);
    freopen("trochoi.out", "w", stdout);

    unsigned n, s, k;
    cin >> n >> s >> k;

    vector<unsigned> table = genTable(s);
    for (unsigned i = 1; table.size(); i++)
    {
        if (!(i % 3)) cout << *table.begin() << endl;
        table.erase(table.begin());
        auto j = k;
        do
        {
            table.push_back(*table.begin());
            table.erase(table.begin());
            j--;
        } while (j);
    }
}
