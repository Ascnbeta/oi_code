#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+20;
int n,t,ans = 0;
int f[maxn][maxn];
int s[maxn],b[maxn];
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	memset(f,0xcf,sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = f[i-1][0]-s[i];
		for (int j = 1; j < t; j++) {
			f[i][j] = max(f[i-1][j-1]+s[i],f[i-1][j]-s[i]);
		}
		tmp = max(tmp,f[i-1][t-1]+s[i]+b[i]);
		f[i][0] = tmp;
	}
	for (int i = 0; i < t; i++) ans = max(f[n][i],ans);
	cout << ans << '\n';
	return 0;
}