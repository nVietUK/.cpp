#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

unsigned input;

bool findMe(unsigned findMeInput)
{
    return (findMeInput == input);
}

int main() 
{
    auto i = 10;
    vector<unsigned> modulo;
    for (;i--;)
    {
        cin >> input;
        input = input % 42;
        if (find_if(modulo.begin(), modulo.end(), findMe) == modulo.end())
            modulo.push_back(input);
    }

    cout << modulo.size() << endl;
}