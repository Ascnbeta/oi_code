#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+10;
int t,q;
bool f[maxn];
vector<int> p;
inline void init() {
	for (int i = 2; i <= 1000000; i++) {
		if (!f[i]) p.push_back(i);
		for (int j = 0; j < p.size() && p[j] * i <= 1000000; j++) {
			f[i*p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
}
inline int solve(int x) {
	int cnt = 0;
	while (f[x]) {
		for (int i = 0; i < p.size() && p[i] * p[i] <= x; i++) {
			if (x % p[i] == 0) {
				++cnt;
				x /= p[i];
				break;
			}
		}
	}
	return cnt;
}
inline int binpow(int base,int b) {
	int ret = 1;
	while (b) {
		if (b&1) ret *= base;
		base *= base;
		b >>= 1;
	}
	return ret;
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> t;
	init();
	while (t--) {
		int opt,x;
		cin >> opt >> x;
		if (opt == 1) {
			cout << solve(x) << '\n';
		}else{
			if (x != 62) cout << binpow(2,x+1) << '\n';
			else cout << "9223372036854775808" << '\n';
		}
	}
	return 0;
}