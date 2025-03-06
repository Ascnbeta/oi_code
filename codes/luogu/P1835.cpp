#include <bits/stdc++.h>
#define int long long
using namespace std;
int l,r;
int p[60000],tot;
int minp[70000];
inline void eular(int x) {
	for (int i = 2; i <= x; i++) {
		if (!minp[i]) {
			p[++tot] = i;
			minp[i] = tot;
		}
		for (int j = 1; j <= minp[i] && p[j] * i <= x; j++) {
			minp[p[j]*i] = j;
		}
	}
}
bool prime[1000005];
int ans;
signed main () {
#ifdef LOCAL 
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> l >> r;
	ans = r - l + 1;
	if (l == 1) --ans;
	int n = sqrt(r);
	eular(n);
	for (int i = 1; i <= tot; i++) {
		int j;
		if (l % p[i] == 0) j = l;
		else j = (l / p[i] + 1) * p[i];
		for (; j <= r; j += p[i]) {
			if (j < l) continue;
			if (!prime[j-l] && j != p[i]) --ans,prime[j-l] = true;
		}
	}
	// for (int i = l; i <= r; i++) if (!prime[i-l]) cout << i << ' ';
	// cout << '\n';
	cout << ans << '\n';
	return 0;
}