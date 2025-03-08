#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 666623333;
int l,r;
int ans[1000004],ans1;
int minp[1000003],prime[100003],tot;
inline void eular(int x) {
	for (int i = 2; i <= x; i++) {
		if (!minp[i]) {
			minp[i] = ++tot;
			prime[tot] = i;
		}
		for (int j = 1; j <= minp[i] && prime[j] * i <= x; j++) {
			minp[prime[j]*i] = j;
		}
	}
}
int lft[1000005];
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> l >> r;
	int n = sqrt(r);
	eular(n);
	for (int i = l; i <= r; i++) ans[i-l] = i,lft[i-l] = i;
	for (int i = 1; i <= tot; i++) {
		int j;
		if (l % prime[i] == 0) j = l;
		else j = (l / prime[i] + 1) * prime[i];
		for (; j <= r; j += prime[i]) {
			assert(j%prime[i]==0);
			ans[j-l] = (ans[j-l] / prime[i] * (prime[i] - 1));
			while (lft[j-l] % prime[i] == 0) lft[j-l] /= prime[i];
		}
	}
	for (int i = l; i <= r; ++i) {
		if (lft[i-l] != 1) ans[i-l] = ans[i-l] / lft[i-l] * (lft[i-l] - 1);
		ans[i-l] = i - ans[i-l];
		ans1 = (ans1 + ans[i-l] % mod) % mod;
	}
	cout << ans1 << '\n';
	return 0;
}