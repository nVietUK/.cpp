#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

unsigned output = 0;

string sp, sq;

bool findit(char& in)
{
    bool run = true;
    auto t = sp;
    if (t.find(in) != -1)
    {
        t.erase(t.begin() + t.find(in));
        for (auto i = &in+1; (i< &in+sp.size()) && run; i++)
        {
            if (t.find(*i) == -1)
            {
                run = false;
                break;
            }
            if (t.size())
                t.erase(t.begin() + t.find(*i));
        }
    }
    else run = false;
    if (run) output++;
    return false;
}

int main()
{
    freopen("HVC.inp", "r", stdin);
    freopen("HVC.out", "w", stdout);

    unsigned p, q;
    cin >> p >> q;

    cin >> sp >> sq;

    find_if(sq.begin(), sq.end(), findit);

    cout << output;
}