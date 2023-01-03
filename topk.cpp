#include <bits/stdc++.h>

using namespace std;

struct myStruct
{
    unsigned value, pos;
};

template<typename _Tp>
    struct myLess : public binary_function<_Tp, _Tp, bool>
    {
        _GLIBCXX14_CONSTEXPR
        bool
        operator()(const _Tp& __x, const _Tp& __y) const
        { 
            if (__x.value == __y.value)
                return __x.pos < __y.pos;
            else 
                return (__x.value >= __y.value);
        }
    };

int main() 
{
    freopen("topk.inp", "r", stdin);
    freopen("topk.out", "w", stdout);

    unsigned n, k;
    cin >> n >> k;

    unsigned input;
    priority_queue<myStruct, vector<myStruct>, myLess<myStruct>> table;
    unsigned pos = 1;
    for (;--n;)
    {
        cin >> input;
        if (table.size() == k)
        {
            if (table.top().value < input)
            {
                table.pop();
                table.push(myStruct{input, pos});
            }
        }
        else
            table.push(myStruct{input, pos});
        
        pos++;
    }

    string ou = "";
    while (table.size())
    {
        ou = to_string(table.top().pos) + " " + to_string(table.top().value) + "\n" + ou;
        table.pop();
    }
    cout << ou;
}