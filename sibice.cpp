#include <iostream>
#include <math.h>

using namespace std;

int main() 
{
    unsigned n, w, h;
    cin >> n >> w >> h;

    w = sqrt(w * w + h * h);
    for (;n--;)
    {
        cin >> h;

        if (h <= w)
            cout << "DA" << endl;
        else
            cout << "NE" << endl;
    }
}