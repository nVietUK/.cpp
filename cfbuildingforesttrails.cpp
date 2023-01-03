#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct village { vector<village*> passed; };
village* temp;
bool findit(village* in) { return in == temp; };
void pushin(village* in, village* in2)
{
    temp = in;
    if (find_if(in2->passed.begin(), in2->passed.end(), findit) == in2->passed.end()) { in2->passed.push_back(in); }
    for (auto t : in->passed)
    {
        temp = t;
        if (find_if(in2->passed.begin(), in2->passed.end(), findit) == in2->passed.end()) { in2->passed.push_back(t); }
    }

    temp = in2;
    if (find_if(in->passed.begin(), in->passed.end(), findit) == in->passed.end()) { in2->passed.push_back(in2); }
    for (auto t : in2->passed)
    {
        temp = t;
        if (find_if(in->passed.begin(), in->passed.end(), findit) == in->passed.end()) { in->passed.push_back(t); }
    }
}

int main()
{
    unsigned n, m, v, u;
    short e;
    cin >> n >> m;
    vector<village> cir (n+1);
    //for (auto i = 1; i <= n; i++) cir[i].value = i;
    for (;m--;)
    {   
        cin >> e >> v >> u;

        if (e-1)
        {
            temp = &cir[u];
            auto t = unsigned(find_if(cir[v].passed.begin(), cir[v].passed.end(), findit) != cir[v].passed.end());
            temp = &cir[v];
            t += unsigned(find_if(cir[u].passed.begin(), cir[u].passed.end(), findit) != cir[u].passed.end());
            cout << unsigned(t > 0);
        }
        else 
        {
            for (auto i = &cir[min(u, v)]; i < &cir[max(u, v)]; i++)
            {
                if (i == &cir[min(u, v)])
                    pushin(&cir[u], &cir[v]);
                else 
                {
                    for (auto t : i->passed)
                    {
                        if ((t < &cir[min(u, v)]) || (&cir[max(u, v)] < t))
                        {
                            pushin(i, &cir[v]);
                            pushin(i, &cir[u]);
                            pushin(t, &cir[v]);
                            pushin(t, &cir[u]);
                        }
                    }
                }
            }
        }
    }
}