#include <bits/stdc++.h>
#define ONLINE false
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<unsigned, unsigned>uu;

#define convert(in, function) transform(in.begin(), in.end(), in.begin(), [](unsigned char c) { return function(c); });
template <typename T> struct dyArray {
    dyArray(T* first, T* last)
        : begin_ {first}, end_ {last} {}
    dyArray(T* first, std::ptrdiff_t size)
        : dyArray {first, first + size} {}
    T* begin() const noexcept { return begin_; } T* begin_;
    T* end() const noexcept { return end_; } T* end_;
};

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen("10140.out", "w", stdout);
    #endif
    freopen("10140.inp", "r", stdin);
#endif

    ull l, u, A1, A2, A3, A4; while (cin >> l >> u) {
        A1=A2=A3=A4=0;
        vector<bool> isPrime(u-l+1, true);
        ll s1=0,s2=0,kq2=INT_MIN,kq1=INT_MAX;
        for (ull i = 2; i*i<=u; i++)
            for (ull j = max(i*i, (l+i-1)/i*i); j <= u; j+=i)
                isPrime[j-l] = false;
        if (1 >= l) isPrime[1-l] = false;
        for (ull x = l; x <= u; x++)
            if (isPrime[x-l]) {
                s2=s1,s1=x;
                if (s2!=0) {
                    if (abs(s1-s2)<kq1) 
                        kq1=abs(s1-s2),A3=s2,A4=s1;
                    if (abs(s1-s2)>kq2)
                        kq2=abs(s1-s2),A1=s2,A2=s1;
                }
            }
        if ((A1==0) || (A2==0) || (A3==0)|| (A4==0)) cout<<"There are no adjacent primes.\n";
        else cout<<A3<<","<<A4<<" are closest, "<<A1<<","<<A2<<" are most distant.\n";
    }
}