#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int p[2000000],tot;
int minp[2000000];
inline void eular(int x) {
	for (int i = 2; i <= x; i++) {
		if (!minp[i]) {
			p[++tot] = i;
			minp[i] = tot;
		}
		for (int j = 1; j <= minp[i] && p[j] * i <= x; j++) {
			minp[i*p[j]] = j;
		}
	}
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> m;
	eular(m);
	while (n--) {
		int l,r;
		cin >> l >> r;
		if (l < 1 || r > m) {
			puts("Crossing the line");
			continue;
		}
		int lp = lower_bound(p+1,p+tot+1,l)-p;
		int rp = upper_bound(p+1,p+tot+1,r)-p-1;
		cout << rp - lp + 1 << '\n';
	}
	return 0;
}