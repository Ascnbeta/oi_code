#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+30;
int n,ans;
int t[maxn],w[maxn];
int st[maxn][22],sum[maxn];
int f[maxn];
inline void init() {
	for (int i = 2; i <= n; i++) f[i] = f[i>>1]+1;
	for (int i = 1; (1<<i) <= n; i++) {
		for (int j = 1; (j+(1<<i)-1) <= n; j++) {
			st[j][i] = min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
}
inline int query(int l,int r) {
	int j = f[r-l+1];
	return min(st[l][j],st[r-(1<<j)+1][j]);
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> t[i],st[i][0] = t[i];
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) sum[i] = sum[i-1]+w[i];
	// cout << '\n';
	init();
	int r = n,lst = 1e9+10;
	for (int l = n; l >= 1; l--) {
		if (sum[r]-sum[l-1] >= 0) {
			lst = min(lst,query(l,r));
			ans += (sum[r]-sum[l-1])*lst;
			r = l - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}