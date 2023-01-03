#include <iostream>
#include <stack>

using namespace std;

int main()
{
    freopen("dayngoac.inp", "r", stdin);
    freopen("dayngoac.out", "w", stdout);

    unsigned n;
    string s;
    cin >> n;
    getline(cin, s);
    for (;n--;)
    {
        stack<char> table;
        getline(cin, s);
        auto run = true;
        for (;(s.size()) && run;)
        {
            switch (*s.begin())
            {
            case '{':
            case '[':
            case '(':
                table.push(s[0]);
                break;
            case '}':
                if (table.top() == '{')
                    table.pop();
                else 
                {
                    cout << "FALSE" <<  endl;
                    run = false;
                }
                break;
            case ']':
                if (table.top() == '[')
                    table.pop();
                else 
                {
                    cout << "FALSE" <<  endl;
                    run = false;
                }
                break;
            case ')':
                if (table.top() == '(')
                    table.pop();
                else 
                {
                    cout << "FALSE" <<  endl;
                    run = false;
                }
                break;
            }
            s.erase(s.begin());
        }
        if (run && (table.size() == 0)) 
            cout << "TRUE" << endl;
        else if (run)
            cout << "FALSE" <<  endl;
    }
}