#include <bits/stdc++.h>

using namespace std;

bool ck(double in);

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("soxau.inp", "r", stdin);
    freopen("soxau.out", "w", stdout);
    
    short n;
    while (cin >> n)
    {
        if (!n) break;
        double tinh = 0;
        priority_queue<double> ta; ta.push(0);
        for (unsigned nam = 0; nam <= 12; nam++)
            for (unsigned ba = 0; ba <= 18; ba++)
                for (unsigned hai = 0; hai <= 29; hai++)
                    if (
                        (
                            ((tinh = (pow(2, hai) * pow(3, ba) * pow(5, nam))) < ta.top()) ||
                            (ta.size() <= n) 
                        ) &&
                        (
                            (sqrt(pow(2, hai)) * sqrt(pow(3, ba)) * sqrt(pow(5, nam)) == sqrt(tinh)) ||
                            (((tinh / pow(5, nam)) / pow(3, ba)) == pow(2, hai))
                        )
                    )
                    {
                        ta.push(tinh);
                        if (ta.size() > n+1) ta.pop();
                    }
        cout << (long long)ta.top() << endl;
    }
}