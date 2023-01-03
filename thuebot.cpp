#include <bits/stdc++.h>
#define ham(a, c) find(a.begin(), a.end(), c) == a.end()
#define liMax 200000 + 1

using namespace std;

struct pp

{
    unsigned first;
    vector<unsigned> second;
};

// communist variables
    vector<unsigned> ta[liMax];
    unsigned n, giatri[liMax], gon; 
    map<pair<unsigned, unsigned>, unsigned> pass;

vector<unsigned> run(unsigned pos);
unsigned chay(unsigned pos, unsigned tranh);
void xuly(vector<vector<unsigned>> in);

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("thuebot.inp", "r", stdin);    
    freopen("thuebot.out", "w", stdout);
#endif
    
    unsigned u, v;
    cin >> n >> u; 
    memset(ta, {}, sizeof(ta));

    for (unsigned i = 0; i < n; i++)
    {
        cin >> u >> v;
        ta[u].push_back(v);
        ta[v].push_back(u);
    }
    for (unsigned i = 0; i < n; i++)
        cin >> giatri[i];
    sort(giatri, giatri + n);

    chay(2, 0); 

    ta[0].clear(); for (auto& temp : pass)
        ta[0].push_back(temp.second);
    sort(ta[0].begin(), ta[0].end());
    unsigned long long ou = 0; for (unsigned i = 0; i < n; i++)
        ou += ta[0][i] * giatri[i];
    cout << ou;
}

unsigned chay(unsigned pos, unsigned tranh)
{
    unsigned oum = 0, olu = 0;
    queue<pp> wa; wa.push({pos, vector<unsigned>{pos}});
    while (wa.size())
    {
        auto curr = wa.front(); wa.pop(); bool imp = true;

        if (ta[curr.first].size() > 2 && ham(ta[curr.first], tranh) && curr.first != pos)
        {
            olu = chay(curr.first, *(curr.second.end()-2)); 
            unsigned ou = olu;
            auto& day = curr.second;
            while (day.size() > 1)
            {
                auto diem = *(day.end()-1); day.erase(day.end()-1);
                pass[make_pair(diem, *(day.end()-1))] = (n-(ou)) * ++ou;
            }
            oum += ou;
            continue;
        }

        for (auto& temp : ta[curr.first])
            if (temp != tranh && ham(curr.second, temp))
            {
                auto next = curr;
                next.first = temp;
                next.second.push_back(temp);                
                wa.push(next); 
                imp = false;
            }
        if (imp) 
        {
            unsigned ou = 0;
            auto& day = curr.second;
            while (day.size() > 1)
            {
                auto diem = *(day.end()-1); day.erase(day.end()-1);
                pass[make_pair(diem, *(day.end()-1))] = (n-(ou)) * ++ou;
            }
            oum += ou;
        }
    }
    return oum;
}