#include <iostream>

using namespace std;

int main() 
{
    unsigned input;
    cin >> input;

    unsigned printer = 1, day = 0;
    while (printer < input)
    {
        printer += printer;
        day += 1;
    }
    
    cout << day + 1 << endl;    
}
