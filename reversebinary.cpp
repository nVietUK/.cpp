#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

string coso(unsigned input);
unsigned coso(string input);

int main() 
{
    unsigned input;
    cin >> input;

    auto s = coso(input);
    reverse(s.begin(), s.end());

    cout << coso(s) << endl;
}

string coso(unsigned input)
{
    string output = "";

    while (input)
    {
        output = to_string(input % 2) + output;
        input = input / 2;
    }

    return output;
}

unsigned coso(string input)
{
    unsigned output = 0;

    while (input.size() != 0)
    {
        output += int(input[0] - 48) * pow(2, input.size() - 1);
        input.erase(input.begin());
    }

    return output;
}