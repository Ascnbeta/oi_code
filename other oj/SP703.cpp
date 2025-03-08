#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
const int maxl = 203;
int t;
int l,n,ans = 0x3f3f3f3f;
int c[maxl][maxl];
int p[maxn];
int f[2][maxl][maxl];
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> t;
	while (t--) {
		memset(f,0x3f,sizeof(f));
		memset(c,0,sizeof(c));
		ans = 0x3f3f3f3f;
		cin >> l >> n;
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= l; j++) {
				cin >> c[i][j];
			}
		}
		for (int i = 1; i <= n; i++) cin >> p[i];
		// cout << '\n';
		f[0][1][2] = 0;
		p[0] = 3;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= l; j++) {
				for (int k = 1; k <= l; k++) {
					if (p[i-1] == j || p[i-1] == k || j == k) continue;
					f[i&1][j][k] = min(f[i&1][j][k],f[(i-1)&1][j][k]+c[p[i-1]][p[i]]);
					f[i&1][p[i-1]][k] = min(f[i&1][p[i-1]][k],f[(i-1)&1][j][k]+c[j][p[i]]);
					f[i&1][j][p[i-1]] = min(f[i&1][j][p[i-1]],f[(i-1)&1][j][k]+c[k][p[i]]);
				}
			}
		}
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= l; j++) {
				// if (i == j || p[n] == i || p[n] == j) continue;
				ans = min(ans,f[n&1][i][j]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}