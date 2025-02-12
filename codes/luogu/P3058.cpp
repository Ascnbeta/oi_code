#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
const int mod = 2012;
string s;
int n;
int sum[maxn],f[maxn][maxn];
int main () {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') sum[i] = sum[i-1] + 1;
		else sum[i] = sum[i-1] - 1;
	}
	if (sum[n] != 0) {
		cout << 0 << '\n';
		return 0;
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum[i]; j++) {
			if (s[i] == '(') {
				if (j - 1 >= 0) f[i][j] = (f[i][j] + f[i-1][j-1]) % mod;
				if (sum[i] - j - 1 >= 0) f[i][j] = (f[i][j] + f[i-1][sum[i]-j-1]) % mod;
			}else{
				if (j + 1 <= sum[i-1]) f[i][j] = (f[i][j] + f[i-1][j+1]) % mod;
				if (sum[i] - j + 1 <= sum[i-1]) f[i][j] = (f[i][j] + f[i-1][sum[i]-j+1]) % mod;
			}
		}
	}
	cout << f[n][0] << '\n'; 
 	return 0;
}