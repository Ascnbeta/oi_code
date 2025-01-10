#include <bits/stdc++.h>
using namespace std;
const int mod = 1e8;
int n,m;
int a[2004];
int f[2004][2004];
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i],a[i]%=m,f[i][a[i]%m]=1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			f[i][j] = (f[i][j] + f[i-1][(j-a[i]+m)%m] + f[i-1][j]) % mod;
		}
	}
	cout << f[n][0] % mod << '\n';
	return 0;
}
