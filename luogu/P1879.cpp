#include <bits/stdc++.h>
using namespace std;
const int mod = 1e8;
int n,m,ans;
int c[20][20];
int f[20][10000];
inline bool check(int p,int x,int y) {
	if (y&(y<<1)) return false;
	if (y&(y>>1)) return false;
	if (x&y) return false;
	int tmp = y,cnt = n;
	while (tmp) {
		if ((tmp&1)&&c[p][cnt] == 0) return false;
		--cnt;
		tmp >>= 1;
	}
	return true; 
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	f[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= (1<<n)-1; j++) {
			for (int k = 0; k <= (1<<n)-1; k++) {
				if (check(i,k,j)) f[i][j] = (f[i][j] + f[i-1][k]) % mod;
			} 
		}
	}
	for (int i = 0; i <= (1<<n)-1; i++) ans = (ans + f[m][i]) % mod;
	cout << ans << '\n';
	return 0;
}