#include <bits/stdc++.h>

using namespace std;

vector<unsigned> dparr(805);

unsigned giaithua(unsigned in) {
    return 1;
}

unsigned func(unsigned in) {
    if (dparr[in])
        return dparr[in];
    return dparr[in] = ((in-2) * (func(in-1)+1) + func(in-1));
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("Demcach.inp", "r", stdin);
    freopen("Demcach.out", "w", stdout);
    fill(dparr.begin(), dparr.end(), 0);
    dparr[2] = 1;
    
    unsigned N = 800, i, ou = 0; vector<unsigned> arr;
    for (i = 1; i <= N; i++)
        arr.push_back(i);
    do{
        for (i = 0; i < N; i++)
            if (arr[i] == i+1)
                break;
        if (i == N) {
            ou++;
        };
    }while (next_permutation(arr.begin(), arr.end()));
    cout << ou << " ";
}