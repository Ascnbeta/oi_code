#include <bits/stdc++.h>
using namespace std;
int t,m,d[203],c[203],n[203],tot,totm;
int dp[203][203][10003];
int main () {
	cin >> t;
	int t1 = t;
	while (t--) {
		cin >> m;
		tot = totm = 0;
		for (int i = 1; i <= m; i++) cin >> d[i];
		int tmp = 0;
		int o = 1,p = 1;
		for (; o <= m;) {
			if (d[o] == d[p]) {
				++tmp;
				++o;
			}else{
				n[++totm] = tmp;
				c[totm] = d[p];
				p = o;
				++o;
				tmp = 1;
			}
		}
		if (o != p) {
			n[++totm] = tmp;
			c[totm] = d[p];
			p = o;
			++o;
			tmp = 1;
		}
		m = totm;
		for (int i = 1; i <= m; i++) tot += n[i];
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = 0; k <= tot; k++) {
					if (i == j) dp[i][j][k] = (n[i]+k) * (n[i]+k);
					else dp[i][j][k] = 0;
				}
			}
		}
		for (int len = 2; len <= m; len++) {
			for (int i = 1; i + len - 1 <= m; i++) {
				int j = i + len - 1;
				for (int k = 0; k <= tot; k++) {
					dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][0]+(n[j]+k)*(n[j]+k));
				}
				for (int l = i; l < j - 1; l++){
					if (c[l] == c[j]) {
						for (int k = 0; k <= tot; k++) {
							dp[i][j][k] = max(dp[i][j][k],dp[i][l][n[j]+k]+dp[l+1][j-1][0]);
						}
					}
				}
			}
		}
		printf("Case %d: %d\n",t1 - t,dp[1][m][0]);
	}
	
	return 0;
}