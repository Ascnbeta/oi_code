#include <bits/stdc++.h>
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;
int n,c,t;
int p[54],w[54],sum[54];
int dp[54][54][3]; // 1 -> left 2 -> right
int main () {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> p[i] >> w[i],sum[i]=sum[i-1]+w[i];
	
	memset(dp,0x3f,sizeof(dp));
	dp[c][c][1] = dp[c][c][2] = 0;
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			t = sum[i] + sum[n] - sum[j];
			dp[i][j][0] = min(dp[i+1][j][1]+t*(p[j]-p[i]),dp[i+1][j][0]+t*(p[i+1]-p[i]));
			t = sum[i-1] + sum[n] - sum[j-1];
			dp[i][j][1] = min(dp[i][j-1][1]+t*(p[j]-p[j-1]),dp[i][j-1][0]+t*(p[j]-p[i]));
		}
	}
	cout << min(dp[1][n][0],dp[1][n][1]) << '\n';
	return 0;
}