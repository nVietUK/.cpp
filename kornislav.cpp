#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    vector<short> rectangle(4);
    cin >> rectangle[0] >> rectangle[1] >> rectangle[2] >> rectangle[3];

    sort(rectangle.begin(), rectangle.end());

    cout << rectangle[0] * rectangle[2] << endl;
}