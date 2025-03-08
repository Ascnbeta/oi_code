#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int t,n,s,ans,ni;
int num[2000003];
inline int binpow(int base,int b) {
	int ret = 1;
	while (b) {
		if (b&1) ret =  ret * (base % mod) % mod;
		base = base * base % mod;
		b >>= 1;
	}
	return ret % mod;
}
inline int solve(int x) {
	int x1 = (1+x)*x/2%mod;
	x1 = x1*((x+1)%mod)%mod;
	int x2 = (((x%mod*(x+1)%mod)%mod*(2*x+1)%mod)%mod*(ni%mod))%mod;
	return (x1-x2)%mod;
}
inline void init(){
	num[0] = 1;
	for (int i = 1; i <= 2000000; i++) {
		num[i] = num[i-1] * (i % mod) % mod;
	}
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> t;
	ni = binpow(6,mod-2);
	//cout << ni << '\n';
	init();
	while (t--) {
		cin >> n >> s;
		if (s == 2 && n == 2) {
			cout << 5 << '\n';continue;
		}
		int base = solve(n);
		int ans = ((base+(s-2)/2%mod*2)%mod+1)%mod;
		if (s == 1) {cout << base << '\n';continue;}
		else if (s%mod == num[n]) {cout << (((n%mod*(n+1)%mod)%mod*(2*n+1)%mod)%mod*(ni%mod))%mod << '\n';continue;}
		cout << ans << '\n';
	}
	return 0;
}