#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans = LONG_LONG_MAX,cnt;
int a[5004],c[5004];
bool x[5004];
int st[5004][20],lg[5004];
inline void init() {
	for (int i = 1; (1 << i) <= n; i++) {
		for (int j = 1; j+(1<<i)-1 <= n; j++) {
			st[j][i] = min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
	for (int i = 2; i <= n; i++) lg[i] = lg[i/2]+1;
}
inline int query(int l,int r) {
	int j = lg[r-l+1];
	return min(st[l][j],st[r-(1<<j)+1][j]);
}
int f[5004][5004];
signed main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> c[i],st[i][0] = c[i];
	for (int i = 1; i <= m; i++) {
		int t;
		cin >> t;
		x[t] = true;
	}
	init();
	memset(f,0x3f3f3f3f3f3f3f3f,sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = min(f[i][j],f[i-1][j-1]+a[i]+query(i-j+1,i));
		}
		if (x[i]) continue;
		for (int j = 0; j <= i; j++) {
			f[i][j] = min(f[i][j],f[i-1][j]);
		}
	}
	for (int i = m; i <= n; i++) ans = min(ans,f[n][i]);
	cout << ans << '\n';	
	return 0;
}
