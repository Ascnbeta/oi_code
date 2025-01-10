#include <bits/stdc++.h>
using namespace std;
int n,m,C;
int v[100004],w[100004],c[100004],tot;
long long a1[8],b1[8],c1[8];
void pre(int w1,int v1,int c1) {
	int tmp = 1;
	while (c1 - tmp > 0) {
		v[++tot] = v1 * tmp;
		w[tot] = w1 * tmp;
		c1 -= tmp;
		tmp *= 2;
	}
	v[++tot] = v1 * c1;
	w[tot] = w1 * c1;   
}
long long dp[10004];
int main () {
	cin >> n >> m >> C;
	for (int i = 1; i <= n; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		pre(a,b,c);
	}
	for (int i = 1; i <= tot; i++) {
		for (int j = C; j >= w[i]; j--) {
			dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> a1[i] >> b1[i] >> c1[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = C; j >= 0; j--) {
			for (int k = 0; k <= j; k++) {
				dp[j] = max(dp[j],(long long)dp[j-k]+(long long)a1[i]*k*k+b1[i]*k+c1[i]);
			}
		}
	}
	long long ans = -1;
	for (int i = 0; i <= C; i++) {
		ans = max(ans,dp[i]);
	}
	cout << ans << '\n';
	return 0;
}