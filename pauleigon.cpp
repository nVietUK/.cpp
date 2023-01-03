#include <iostream>

using namespace std;

int main() 
{
    unsigned n, p, q;
    cin >> n >> p >> q;

    p += q + 1;
    q = p % n;
    p = p / n;
    if ((p + (q > 0)) % 2)
        cout << "paul" << endl;
    else
        cout << "opponent" << endl;
}