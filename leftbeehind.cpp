#include <iostream>

using namespace std;

int main() 
{
    int x, y;
    while (cin >> x >> y)
    {
        if ((x == y) && (y == 0))
            return 0;
        else if (x + y == 13)
        {
            cout << "Never speak again." << endl;
            continue;
        }
        x -= y;
        if (0 < x)
            cout << "To the convention." << endl;
        else if (x < 0)
            cout << "Left beehind." << endl;
        else if (x == 0)
            cout << "Undecided." << endl;
    }
}