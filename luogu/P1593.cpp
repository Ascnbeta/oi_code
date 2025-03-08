#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 503;
const int mod = 9901;
int a,b,ans = 1;
int p[maxn],k[maxn];
int tot;
inline int binpow(int base,int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = ret * base % mod;
		base = base * base % mod;
		b >>= 1;
	}
	return ret % mod;
}
inline void solve(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			p[++tot] = i;
			int cnt = 0;
			while (x % i == 0) x /= i,++cnt;
			k[tot] = cnt;
		}
	}
	if (x != 1) p[++tot] = x,k[tot] = 1;
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> a >> b;
	solve(a);
	for (int i = 1; i <= tot; i++) {
		k[i] = k[i] * b;
		if ((p[i]-1) % mod == 0) {
			ans = ans * ((1 + k[i]) % mod) % mod;
		}else{
			int ni = binpow(p[i]-1,mod-2);
			ans = ans * ni % mod * ((binpow(p[i],k[i]+1) - 1) % mod) % mod;
		}
	}
	if (ans < 0) ans += mod;
	cout << ans << '\n';
	return 0;
}