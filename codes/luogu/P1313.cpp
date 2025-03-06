#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e4+7;
int a,b,k,n,m;
int ans = 1;
inline int binpow(int base,int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = ret * base % mod;
		base = base * base % mod;
		b >>= 1;
	}
	return ret % mod;
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> a >> b >> k >> n >> m;
	ans = ans * binpow(a,n) % mod;
	ans = ans * binpow(b,m) % mod;
	int tmp = 1;
	for (int i = 1; i <= n; i++) {
		tmp = tmp * i % mod;
	}
	tmp = binpow(tmp,mod-2);
	for (int i = k; k - i < n; i--) {
		tmp = tmp * i % mod;
	}
	cout << ans * tmp % mod;
	return 0;
}