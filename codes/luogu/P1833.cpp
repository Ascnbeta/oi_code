#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,V;
int w[10004],v[10004],t[10004];
int dp[1004];
signed main () {
	int sh,sm,eh,em;
	scanf("%d:%d %d:%d %d",&sh,&sm,&eh,&em,&n);
	if (em < sm) {
		V += em + 60 - sm;
		eh--;
		V += (eh - sh) * 60;
	}else{
		V += em - sm;
		V += (eh - sh) * 60;
	}
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i] >> t[i];
	}
	for (int i = 1; i <= n; i++) {
		if (t[i] == 0) {
			for (int j = w[i]; j <= V; j++) {
				dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
			}
		}else{
			for (int j = V; j >= 0; j--) {
				for (int k = 0; k <= min(t[i],j / w[i]); k++) {
					dp[j] = max(dp[j],dp[j-k*w[i]]+k*v[i]);
				}
			}
		}
	}
	long long ans = LONG_LONG_MIN;
	for (int i = 0; i <= V; i++) ans = max(ans,(long long)dp[i]);
	cout << ans << '\n';
	return 0;
}