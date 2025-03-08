#include <bits/stdc++.h>
#define int long long
using namespace std;
int T;
int ans[10000005];

inline int binpow(int base,int b,int mod) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = ret * base % mod;
		base = base * base % mod;
		b >>= 1;
	}
	return ret % mod;
}
inline int phi(int x) {
	int n = x;
	if (ans[x]) return ans[x];
	ans[n] = x;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			ans[n] = ans[n] / i * (i - 1);
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) ans[n] = ans[n] / x * (x - 1);
	return ans[n];
}
int solve(int m) {
	if (m == 1) {
		return 0;
	}
	return binpow(2,solve(phi(m))+phi(m),m);
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> T;
	ans[1] = 1,ans[2] = 1;
	while (T--) {
		int p;
		cin >> p;
		cout << binpow(2,solve(phi(p))+phi(p),p) << '\n';
	}
	return 0;
}