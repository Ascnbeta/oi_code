#include <bits/stdc++.h>
#define int long long
using namespace std;
int k,V,n,ans;
int f[5004][56],tmp[203];
int w[203],v[203];
signed main () {
	cin >> k >> V >> n;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	memset(f,0xcf,sizeof(f));
	f[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = V; j >= w[i]; j--) {
			for (int t = 1,x = 1,y = 1; t <= k; t++) {
				int t1 = f[j][x],t2 = f[j-w[i]][y]+v[i];
				if (t1 <= t2) {
					tmp[t] = f[j-w[i]][y++]+v[i];
				}else{
					tmp[t] = f[j][x++];
				}
			}
			for (int t = 1; t <= k; t++) {
				f[j][t] = tmp[t];
			}
		}
	}
	for (int i = 1; i <= k; i++) {
		ans += f[V][i];
	}
	cout << ans << '\n';
	return 0;
}