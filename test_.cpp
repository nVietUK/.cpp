#include <bits/stdc++.h>
#define ONLINE false
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<unsigned, unsigned> uu;

// My Functions
#define convert(in, function) transform(in.begin(), in.end(), in.begin(), [](unsigned char c) { return function(c); });
bool *value;
void init(unsigned stop) {
    value = new bool[stop+1]; memset(value, false, sizeof(value));
    value[2] = value[3] = true;

    for (ull x = 1; x*x <= stop; x++)
        for (ull y = 1; y*y <= stop; y++) {
            ull n = (4*x*x) + (y*y);
            if ((n <= stop) && (n % 12 == 1 || n % 12 == 5))
                value[n] ^= true;
            n = (3*x*x) + (y*y);
            if ((n <= stop) && (n % 12 == 7))
                value[n] ^= true;
            n = (3*x*x) - (y*y);
            if ((x > y) && (n <= stop) && (n % 12 == 11))
                value[n] ^= true;
        }
    for (ull r = 5; r*r <= stop; r++) 
        if (value[r]) 
            for (ull i = r*r; i <= stop; i += r*r)
                value[i] = false;
}

void init1(unsigned stop) {
    value = new bool[stop+1]; memset(value, true, sizeof(value));
    
    for (unsigned i = 2; i*2 <= stop; i++)
        value[i*2] = false;
    for (unsigned i = 3; i*i <= stop; i+=2)
        if (value[i]) 
            for (unsigned j = i; i*j <= stop; j+=2)
                value[i*j] = false;
}

unsigned isPrime(const unsigned& inp) {
    for (unsigned i = 2; i*i <= inp; i+=1+(i%2))
        if (!(inp % i) && value[i])
            return 0;
    return (inp > 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

#if (!ONLINE && !ONLINE_JUDGE)
    #if (nVietUKComputer)
        cout.tie(NULL);
        freopen("primecount.out", "w", stdout);
    #endif
#endif

    init1(200000);
    unsigned x, y; cin >> x >> y; 
    for (; x <= y; x++) 
        if (value[x])
            cout << x << "\n";
}