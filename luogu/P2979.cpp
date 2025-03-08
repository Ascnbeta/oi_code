#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,t,k,ans;
int f[2004],f1[1003];
struct cheese{
	int h,v;
}c[103];
signed main () {
	cin >> n >> t >> k;
	int t1 = t * 5 / 4;
	memset(f,0xcf,sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= n; i++) cin >> c[i].v >> c[i].h;
	for (int i = 1; i <= n; i++) {
		for (int j = c[i].h; j <= t1; j++) {
			f[j] = max(f[j],f[j-c[i].h]+c[i].v);
		}
	}
	// cout << f[35] << '\n';
	for (int i = 0; i <= t; i++) f1[i] = f[i];
	for (int i = 1; i <= n; i++) {
		if (c[i].h >= k) {
			for (int j = 0; j <= t; j++) {
				if (j >= c[i].h) f1[j] = max(f1[j],f[(j-c[i].h)*5/4]+c[i].v);
			}
		}
	}
	for (int i = 0; i <= t; i++) {
		ans = max(ans,f1[i]);
	}
	cout << ans << '\n';
	return 0;
}