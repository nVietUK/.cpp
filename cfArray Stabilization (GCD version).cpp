#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

unsigned long long ou;

bool find(vector<unsigned> &ta)
{
    for (auto i = &ta[ta.size() - 2]; i != &ta[0]; i--)
    {
        if (*i != *(i+1))
            return true;
        else if (*i == 1)
            ta.erase(ta.begin() + (i - &ta[0]));
    };
    return false;
}

unsigned gcd(unsigned a, unsigned b)
{
    if (a == b)
        return a;
 
    // GCD(0, b) == b; GCD(a, 0) == a,
    // GCD(0, 0) == 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    // look for factors of 2
    if (~a & 1) // a is even
    {
        if (b & 1) // b is odd
            return gcd(a >> 1, b);
        else // both a and b are even
            return gcd(a >> 1, b >> 1) << 1;
    }
 
    if (~b & 1) // a is odd, b is even
        return gcd(a, b >> 1);
 
    // reduce larger number
    if (a > b)
        return gcd((a - b) >> 1, b);
 
    return gcd((b - a) >> 1, a);
}

void gdc(vector<unsigned> &ta)
{
    for (auto i = &ta[0]; i < &ta[ta.size() -1]; i++)
        *i = gcd(*i, *(i+1));
    ta[ta.size() - 1] = ta[0];
}

int main()
{
    unsigned short t;
    cin >> t;
    while (t--)
    {
        unsigned n;
        ou = 0;
        cin >> n;
        vector<unsigned> ta(n + 1);
        while (n--) cin >> ta[n];
        ta[ta.size() - 1] = ta[0];

        while (find(ta))
        {
            gdc(ta);
            ou++;
        }
        cout << ou << endl;
    }
}