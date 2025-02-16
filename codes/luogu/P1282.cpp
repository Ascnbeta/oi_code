#include <bits/stdc++.h>
using namespace std;
int n;
int a[1003],b[1003],ans,minn = 0x3f3f3f3f;
int f[1003][12004];
int sum[1003],suma[1003];
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i],sum[i] = sum[i-1]+a[i]+b[i],suma[i] = suma[i-1]+a[i];
	memset(f,0x3f,sizeof(f));
	for (int i = 0; i <= n; i++) f[i][suma[i]] = 0;
	f[1][b[1]] = 1,f[1][a[1]] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 6*n; j++) {
			if (j-a[i] >= 0) f[i][j] = min(f[i][j],f[i-1][j-a[i]]);
			if (j-b[i] >= 0) f[i][j] = min(f[i][j],f[i-1][j-b[i]]+1);
		}
	}
	for (int i = 0; i <= sum[n]; i++) {
		if (f[n][i] < 0x3f3f3f3f) {
			if (abs(i-sum[n]+i)<minn) {
				minn = abs(i-sum[n]+i);
				ans = f[n][i];
			}else if (abs(i-sum[n]+i)==minn) {
				ans = min(ans,f[n][i]);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}