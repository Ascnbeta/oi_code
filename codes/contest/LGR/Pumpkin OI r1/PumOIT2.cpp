#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int mod = 998244353;
inline int binpow(int x,int b) {
	int base = x % mod,ans = 1;
	while (b) {
		if (b&1) ans = ans * base % mod;
		base *= base % mod;
		b >>= 1;
		ans %= mod;
		base %= mod;
	}
	return ans % mod;
}
int n;
int a[5004],r[5004];
signed main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n + 1; i++) cin >> r[i];
	if (n == 1) {
		//int gcd = __gcd(a[1],binpow(r[2]+1,mod-2));
		cout << (a[1] % mod * binpow((r[2]+1)%mod,mod-2) % mod) % mod << '\n';
	}
	return 0;
}