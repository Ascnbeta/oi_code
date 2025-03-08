#include <bits/stdc++.h>
using namespace std;
int n,a[204],sum[204],ans1 = 0x3f3f3f3f,ans2;
int dp1[203][203],dp2[203][203];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n + 1; i <= 2 * n - 1; i++) a[i] = a[i-n];
	for (int i = 1; i <= 2 * n - 1; i++) sum[i] = sum[i-1]+a[i];
	memset(dp1,0x3f,sizeof(dp1));
	for (int i = 1; i <= 2 * n - 1; i++) dp1[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j + i - 1 <= 2 * n - 1; j++) {
			for (int k = j; k < j + i - 1; k++) {
				dp1[j][j+i-1] = min(dp1[j][j+i-1],dp1[j][k]+dp1[k+1][j+i-1]+sum[j+i-1]-sum[j-1]);
				dp2[j][j+i-1] = max(dp2[j][j+i-1],dp2[j][k]+dp2[k+1][j+i-1]+sum[j+i-1]-sum[j-1]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans1 = min(ans1,dp1[i][i+n-1]);
		ans2 = max(ans2,dp2[i][i+n-1]);
	}
	cout << ans1 << '\n' << ans2 << '\n';
	return 0;
}