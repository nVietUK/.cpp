#include <bits/stdc++.h>
#define ONLINE false
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<unsigned, unsigned> uu;

// My Functions
#define convert(in, function) transform(in.begin(), in.end(), in.begin(), [](unsigned char c) { return function(c); });
template <typename T> struct wrapped_array {
	wrapped_array(T* first, T* last)
		: begin_ {first}, end_ {last} {}
	wrapped_array(T* first, std::ptrdiff_t size)
		: wrapped_array {first, first + size} {}
	T* begin() const noexcept { return begin_; }
	T* end() const noexcept { return end_; }
	T* begin_;
	T* end_;
};
int main() {
#if (!ONLINE && !ONLINE_JUDGE)
	#if (!nVietUKComputer)
		ios_base::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);
		freopen("11955.out", "w", stdout);
	#endif
	freopen("11955.inp", "r", stdin);
#endif

	int T, t; cin >> T;

	for (t = 1; t <= T; t++){
		string str, A, B, K = "";
		cin >> str;
		for (int i = 0; i < str.length(); i++)
			if ((str[i] == '(') || (str[i] == ' ') || (str[i] == '^'))
				continue;
			else if (str[i] == '+')
				A = K, K = "";
			else if (str[i] == ')')
				B = K, K = "";
			else K += str[i];
		int k = atoi(K.c_str());
		unsigned long long cof[k+1]; cof[0] = 1;
		for (int i = 1; i <= k; i++)
			cof[i] = (cof[i-1] * (k - i + 1)) / i;
		cout << "Case " << t << ": ";
		for (int i = 0; i <= k; i++) {
			if (cof[i] > 1) cout << cof[i] << "*";
			if (k - i > 0) 	cout << A.c_str();
			if (k - i > 1) 	cout << "^" << k-i;
			if ((cof[i] > 1 || k - i > 0) && i > 0)
							cout << "*";
			if (i > 0)		cout << B.c_str();
			if (i > 1)		cout << "^" << i;
			if (i < k) 		cout << "+";
		}
		cout << "\n";
	}
}