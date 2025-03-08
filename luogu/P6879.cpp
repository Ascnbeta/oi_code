#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 205;
int n,l,ans;
int s[maxn<<1],t[maxn<<1];
int f[maxn<<1][maxn<<1][maxn][2];
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i+n+1] = s[i]+l;
	}
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		t[i+n+1] = t[i];
	}
	s[n+1] = l;
	t[n+1] = -1;
	memset(f,0x3f,sizeof(f));
	// cout << f[1][1][1][1] << '\n';
	f[n+1][n+1][0][0] = 0,f[n+1][n+1][0][1] = 0;
	for(int j = n+1; j <= 2*n+1; j++) {
		for(int i = n+1; j && j-i <= n; i--) {
			f[i][j][0][0] = l-s[i];
			f[i][j][0][1] = s[j]-l;
		}
	}
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i <= n+1; i++) {
			int j = i + len;
			for (int k = 1; k <= len; k++) {
				if (f[i+1][j][k-1][0] + s[i+1]-s[i] <= t[i]) {
					f[i][j][k][0] = min(f[i][j][k][0],min(f[i+1][j][k-1][0]+s[i+1]-s[i],f[i+1][j][k][0]+s[i+1]-s[i]));
				}else{
					f[i][j][k][0] = min(f[i][j][k][0],f[i+1][j][k][0]+s[i+1]-s[i]);
				}
				if (f[i+1][j][k-1][1] + s[j]-s[i] <= t[i]) {
					f[i][j][k][0] = min(f[i][j][k][0],min(f[i+1][j][k-1][1]+s[j]-s[i],f[i+1][j][k][1]+s[j]-s[i]));
				}else{
					f[i][j][k][0] = min(f[i][j][k][0],f[i+1][j][k][1]+s[j]-s[i]);
				}
				if (f[i][j-1][k-1][1] + s[j]-s[j-1] <= t[j]) {
					f[i][j][k][1] = min(f[i][j][k][1],min(f[i][j-1][k-1][1]+s[j]-s[j-1],f[i][j-1][k][1]+s[j]-s[j-1]));
				}else{
					f[i][j][k][1] = min(f[i][j][k][1],f[i][j-1][k][1]+s[j]-s[j-1]);
				}
				if (f[i][j-1][k-1][0] + s[j]-s[i] <= t[j]) {
					f[i][j][k][1] = min(f[i][j][k][1],min(f[i][j-1][k-1][0]+s[j]-s[i],f[i][j-1][k][0]+s[j]-s[i]));
				}else{
					f[i][j][k][1] = min(f[i][j][k][1],f[i][j-1][k][0]+s[j]-s[i]);
				}
				if (f[i][j][k][0] < 1e15 || f[i][j][k][1] < 1e15) ans = max(ans,k);
			}
		}
	}
	// cout << 1 << '\n';
	cout << ans << '\n';
	return 0;
}