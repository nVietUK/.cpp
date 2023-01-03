#include <bits/stdc++.h>

using namespace std;

struct Data 
{
    long long index = 0;
    short Day = 0;
    long long Money = 0;
};

bool comparer(Data& a, Data& b)
{
    double aMoney = a.Money / (double)a.Day;
    double bMoney = b.Money / (double)b.Day;

    if (aMoney > bMoney)
        return true;
    else 
    if (aMoney == bMoney)
        return a.index < b.index;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("donggiay.inp", "r", stdin);
    freopen("donggiay.out", "w", stdout);

    long long n;
    cin >> n;
    vector<Data> Arr;
    Arr.resize(n);
    for (long long i = 0; i < n; ++i) {
        cin >> Arr[i].Day >> Arr[i].Money;
        Arr[i].index = i + 1;
    }

    sort(Arr.begin(), Arr.end(), comparer);
    for (long long i = 0; i < n; ++i) {
        cout << Arr[i].index << ' ';
    }

    return 0;
}