#include <iostream>
#include <vector>

using namespace std;

void request(unsigned pos)

int main()
{
    unsigned short m, n;
    cin >> m >> n;

    unsigned x, y;
    vector<unsigned> ta(m * 2 + 1, 0);
    while (n--)
    {
        cin >> x >> y;
        ta[y] = x;
    }
}