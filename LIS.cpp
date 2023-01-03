#include <bits/stdc++.h>
#define limax 10 + 2

using namespace std;

struct pp;
struct myless;

struct pp
{
    long long first, second;
    inline bool operator>(pp& a)
    {
        return this->first > a.first && this->second > a.second;
    }
    inline bool operator>(set<pp, myless>& a)
    {
        for (auto& temp2 : a)
        if (this->first > temp2.first && this->second > temp2.second)
            return true;
        return false;
    }
};

struct myless : public binary_function<pp, pp, bool>
    {
      _GLIBCXX14_CONSTEXPR
      bool
      operator()(const pp& __x, const pp& __y) const
      { return __x.first < __y.first && __x.second < __y.second; }
    };

// communist variables
    pp ta[limax]; set<pp, myless> l[limax];
    unsigned lpos[limax], trace[limax];

unsigned diemb = 0, diemf = 1;
unsigned diem(int& in)
{
    auto b = diemb, f = diemf;
    while (b != f)
    {
        auto m = (b + f) / 2;
        if (ta[in] > l[m])
            b = m + 1;
        else 
            f = m;
    }
    return b;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    
    long long n; cin >> n; 
    ta[n+1].first = ta[n+1].second = INT64_MAX; 
    ta[0].first = ta[0].second = INT64_MAX + 1;
    for (unsigned i = 1; i <= n; i++)
        cin >> ta[i].first >> ta[i].second;

    l[0].insert(ta[0]); lpos[0] = n;
    for (int i = 1; i <= n; i++)
    {
        auto pos = diem(i);
        trace[i] = lpos[pos - 1];
        l[pos].insert(ta[i]);
        lpos[pos] = i;
        if (pos == diemf) diemf++;
    }
    cout << diemf - 2 << "\n"; 
}
