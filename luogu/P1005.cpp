#include <bits/stdc++.h>
using namespace std;
int n,m,mat[83][83];
__int128 f[83][83],p[83],tmp = 1,ans;
void print(__int128 x) {
	if (x > 9) print(x/10);
	putchar(x%10+'0');
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		tmp *= 2;
		p[i] = tmp;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}
	for (int t = 1; t <= n; t++) {
		memset(f,0,sizeof(f));
		for (int len = m; len >= 1; len--) {
			for (int i = 1; i <= m - len + 1; i++) {
				int j = i + len - 1;
				f[i+1][j] = max(f[i+1][j],f[i][j]+mat[t][i]*p[m-len+1]);
				f[i][j-1] = max(f[i][j-1],f[i][j]+mat[t][j]*p[m-len+1]);
			}
		}
		__int128 tmp1 = 0;
		for (int i = 1; i <= m; i++) tmp1 = max(tmp1,f[i+1][i]);
		ans += tmp1;
	}
	print(ans);
	return 0;
}