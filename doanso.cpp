#include <iostream>
#include <stack>

using namespace std;

int main()
{
    //system("pwd");
    freopen("doanso.inp", "r", stdin);
    freopen("doanso.out", "w", stdout);

    unsigned input;
    stack<unsigned> table;
    while (!feof(stdin))
    {
        cin >> input;
        table.push(input);
    }

    auto output = 0;
    do
    {   
        auto number = table.top();
        table.pop();
        switch (table.top())
        {
        case '=':
            output = table.top();
            break;
        case '+':
            output -= table.top();
            break;
        case '-':
            output += table.top();
            break;
        case '*':
            output /= table.top();
            break;
        }
        table.pop();
    }
    while (tableChar.size());
    cout << output;
}