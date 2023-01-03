#include <bits/stdc++.h>

using namespace std;

int mo(int inp);
int el(int inp);

int main()
{
    freopen("dovui.inp", "r", stdin);
    freopen("dovui.out", "w", stdout);

    unsigned w, m;
    cin >> w >> m;

    w = el(w);
    int lec = 0, e = w / 4, sai = w / 4; 
    for (; (lec = (mo(w-e) - mo(e)) - m) != 0;)
    {
        sai /= 2;
        if (lec < 0)            
            e -= sai;
        else
            e += sai;
    }

    cout << mo(e);
};

int mo(int inp)
{
    if (inp <= 100)
        return inp * 2;
    if (inp <= 10000)
        return (200 + (inp - 100) * 3);
    if (inp <= 1000000)
        return (29900 + (inp - 10000) * 5);
    return (4979900 + (inp - 1000000) * 7);
};

int el(int inp)
{
    if (inp > 4979900)
        return (inp - 4979900) / 7 + 1000000;
    if (inp > 29900)
        return (inp - 29900) / 5 + 10000;
    if (inp > 200)
        return (inp - 200) / 3 + 100;
    return inp / 2;
}