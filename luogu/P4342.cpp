#include <bits/stdc++.h>
using namespace std;
int n,a[103],op[103];//0 -> plus 1 -> time
int dp[103][103][3];//0 -> max 1 -> min
int main () {
	// freopen("polygon2.in","r",stdin);
	// freopen("data.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char ch;
		int b;
		cin >> ch >> b;
		a[i] = a[i+n] = b;
		op[i-1] = op[i+n-1] = ((ch == 't')?0:1);
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1<=  2*n; i++) {
			int j = i + len - 1;
			dp[i][j][0] = -1*(0x3f3f3f3f);
			dp[i][j][1] = 0x3f3f3f3f;
		}
	}
	for (int i = 1;i <= 2*n; i++) {
		dp[i][i][0] = dp[i][i][1] = a[i];
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= 2*n; i++) {
			int j = i + len - 1;
			for (int k = i; k < j; k++) {
				if (op[k] == 0) {
					dp[i][j][0] = max(dp[i][j][0],dp[i][k][0]+dp[k+1][j][0]);
					dp[i][j][1] = min(dp[i][j][1],dp[i][k][1]+dp[k+1][j][1]);
				}else{
					dp[i][j][0] = max(dp[i][j][0],max(dp[i][k][0]*dp[k+1][j][0],dp[i][k][1]*dp[k+1][j][1]));
					dp[i][j][1] = min(dp[i][j][1],min(dp[i][k][0]*dp[k+1][j][1],dp[i][k][1]*dp[k+1][j][0]));
				}
			}
		}
	}
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		ans = max(ans,dp[i][i+n-1][0]);
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		if (dp[i][i+n-1][0] == ans) cout << i << ' ';
	}
	cout << '\n';
	return 0;
}