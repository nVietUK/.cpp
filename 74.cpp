#include <iostream>

using namespace std;

unsigned c = 0;

bool de(string& in, short pos)
{
    if (pos < 0) return false;
    else if (!pos) c = 0;

    switch (in[pos])
    {
        case '2':
            in[pos] = '1';
            break;
        case '1':
            in[pos] = '0';
            c++;
            if (pos == in.size() - 1) in.erase(in.end() - 1);
            break;
        case '0':
            de(in, pos + 1);
            in[pos] = '2';
            c--;
            break;
    }

    if (!pos) return !c;
    return false;
}

int main()
{
    long long n = 2;
    //cin >> n;
    
    string max(n, '2');

    unsigned out = 0;
    while (max.size())
    {
        if (de(max, 0)) out++;
    }

    cout << out;
}