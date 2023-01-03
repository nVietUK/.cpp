#include <bits/stdc++.h>

using namespace std;

unsigned numLength(unsigned in)
{
    unsigned ou = 0;
    while((in = in / 10) != 0) ou++;
    return ou + 1;
}

short numAt(unsigned in, int at)
{
    at -= numLength(in);
    while (at++) in /= 10;
    return in % 10;
}

unsigned mstoi(string in)
{
    unsigned ou = 0;
    for (auto i : in) ou = ou * 10 + (i - '0');
    return ou;
}

unsigned demchuso(unsigned in)
{
    unsigned output = 0;
    unsigned l = numLength(in);
    for (auto i = 1; i < l; i++)
    {
        string lmao(i, '0');
        string nlma(i-1, '0');
        if (in >= mstoi("1" + lmao)) 
            output += mstoi("9" + nlma)*i;
    }
    string lmao(l - 1, '9');
    output += l * (in - mstoi("0" + lmao));
    return output;
}

int main()
{
    freopen("dayso.inp", "r", stdin);
    freopen("dayso.out", "w", stdout);

    unsigned t, in, ou, ck = 0;
    cin >> t;
    while (t--)
    {
        cin >> in;
        ou = 0;
        while ((ck = demchuso(++ou)) < in) in -= ck;
        for(ou = 1; in > (ck = numLength(ou++));) in -= ck;
        cout << numAt(ou - 1, in) << endl;
    }
}