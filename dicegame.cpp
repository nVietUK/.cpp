#include <iostream>

using namespace std;

int main()
{
    unsigned a1, b1, a2, b2;
    auto kq = -1;
    for (auto i = 0; i < 2; i++)
    {
        cin >> a1 >> b1 >> a2 >> b2;
        if (kq == -1)
            kq = (a1 + b1) * 2 + (a2 + b2) * 2;
        else 
        {
            kq -= (a1 + b1) * 2 + (a2 + b2) * 2;
            if (0 < kq)
                cout << "Gunnar" << endl;
            else if (0 == kq)
                cout << "Tie" << endl;
            else 
                cout << "Emma" << endl;
        }
    }
}