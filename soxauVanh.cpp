#include <bits/stdc++.h>

using namespace std;

bool ck(double in);

vector<unsigned long long> ta()
{
    double tinh = 0;
    vector<unsigned long long> ou (0);
    priority_queue<double> ta; ta.push(0);
    for (unsigned nam = 0; nam <= 12; nam++)
        for (unsigned ba = 0; ba <= 18; ba++)
            for (unsigned hai = 0; hai <= 29; hai++)
                if (
                    (
                        ((tinh = (pow(2, hai) * pow(3, ba) * pow(5, nam))) < ta.top()) ||
                        (ta.size() <= 1500) 
                    ) &&
                    (
                        (sqrt(pow(2, hai)) * sqrt(pow(3, ba)) * sqrt(pow(5, nam)) == sqrt(tinh)) ||
                        (((tinh / pow(5, nam)) / pow(3, ba)) == pow(2, hai))
                    )
                )
                {
                    ta.push(tinh);
                    if (ta.size() > 1501) ta.pop();
                }
    while (ta.size())
    {
        ou.insert(ou.begin(), (unsigned long long)ta.top());
        ta.pop();
    }
    return ou;
}
auto ou = ta();

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("soxau.inp", "r", stdin);
    freopen("soxau.out", "w", stdout);
    
    short n;
    while (cin >> n)
    {
        if (!n) break;    
        
        cout << ou[n] << endl;
    }
}