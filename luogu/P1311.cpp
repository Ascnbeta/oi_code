#include <bits/stdc++.h>
using namespace std;
int n,k,p;
long long c[200005],b[200005],dp[200005];
bool f[200005];
long long ans;
int main () {
	cin >> n >> k >> p;
	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> b[i];
		if (b[i] <= p) f[i] = true;
	} 
//	for (int i = 1; i <= n; i++) cout << f[i] << ' ';
//	cout << '\n'; 
	for (int i = 0; i <= k - 1; i++) {
		dp[0] = 0;
		int cnt = 0,lst_1 = 0;
		for (int j = 1; j <= n; j++) {
			if (c[j] == i) {
				++cnt;
				if (f[j]) {
					dp[cnt] = dp[cnt-1] + cnt - 1;
					lst_1 = cnt;
				}else{
					dp[cnt] = dp[cnt-1] + lst_1;
				}
			}else{
				if (f[j]) lst_1 = cnt; 
			}
		}
		ans += dp[cnt];
	}
	cout << ans << '\n';
	return 0;
} 