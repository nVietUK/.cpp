#include <bits/stdc++.h>
#include <ctime>

using namespace std;

unsigned duong(seed_seq::result_type b, seed_seq::result_type c);
vector<unsigned> doc(unsigned short n);
vector<vector<unsigned>> ta;
ofstream input; 

int main()
{
    input.open("demtg.inp");
    freopen("demtg.out", "w", stdout);    
    srand(time(NULL));
	int n = 3;//rand();
    
    input << n << endl;    
    ta.push_back(doc(n));
    ta.push_back(doc(n));
    ta.push_back(doc(n));
    sort(ta[0].begin(), ta[0].end());

    unsigned an = 0;
    for (auto b : ta[1])
        for (auto c : ta[2])
            an += lower_bound(ta[0].begin(), ta[0].end(), b+c) - upper_bound(ta[0].begin(), ta[0].end(), duong(b,c));
    cout << an;
}

vector<unsigned> doc(unsigned short n)
{
    vector<unsigned> o(n);
    while (n--) input << (o[n] = rand() % 1000000000) << " ";
    input << endl;
    return o;
}

unsigned duong(seed_seq::result_type b, seed_seq::result_type c)
{
    int o = b-c;
    if (o < 0)
        return o * -1;
    return o;
}