#include <bits/stdc++.h>

using namespace std;

struct myStruct
{
    char value;
    bool out;
};

bool fi(char& in);
unsigned short i, m, n;
stack<char> wa;
vector<myStruct> ck, me;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("scxh.inp", "r", stdin);
    freopen("scxh.out", "w", stdout);
    
    char in;
    cin >> n >> m;
    while ((ck.size() < n) && (cin >> in)) ck.push_back(myStruct{in, true});
    while (m--)
    {
        me = ck;
        vector<char> ta(0); 
        while (!(wa.empty())) wa.pop();
        unsigned short st = 0;
        while ((ta.size() < n) && (cin >> in)) ta.push_back(in);

        i = 0;
        for (auto a : ta)
        {
            fi(a);
            if (wa.top() != a)
            {                
                cout << "N" << endl;
                break;
            }
            else 
            {
                wa.pop();
                i = (i - 1 >= 0) ? (i-1) : i;
            }
        }
        if (!(wa.size())) cout << "Y" << endl;
    }
}

bool fi(char& in)
{
    for (; i < n; i++)
    {
        if (me[i].out)
        {
            wa.push(me[i].value);
            me[i].out = false;
        }
        if (me[i].value == in)
            return true;
    }
    return false;
}