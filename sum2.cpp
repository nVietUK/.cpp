#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("sum.inp", "r", stdin);
    freopen("sum.out", "w", stdout);
    
    string in1, in2;
    cin >> in1 >> in2;

    reverse(in1.begin(), in1.end());
    reverse(in2.begin(), in2.end());
    string ou(in1.size()+in2.size(), '0');
    for (unsigned i = 0; i < in1.size(); i++){
        for (unsigned j = 0; j < in2.size(); i++){
            unsigned so = (ou[i+j]-48) + (in1[i]-48) * (in2[j]-48);
            ou[i+j] = so % 10 + 48;
            ou[i+j+1] = so / 10 + 48;
        }   
    }
}