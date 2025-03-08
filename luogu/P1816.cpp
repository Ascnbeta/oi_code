#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
int m,n;
int a[maxn],st[maxn][30];
int f[maxn];
inline void init() {
	f[1] = 0;
	for (int i = 2; i <= m; i++) f[i] = f[i/2] + 1;
	for (int i = 1; (1<<i) <= m; i++) {
		for (int j = 1; j+(1<<i)-1 <= m; j++) {
			st[j][i] = min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
}
inline int query(int l,int r) {
	int j = f[r-l+1];
	return min(st[l][j],st[r-(1<<j)+1][j]);
}
int main () {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) cin >> a[i],st[i][0] = a[i];
	init();
	while(n--) {
		int l,r;
		cin >> l >> r;
		cout << query(l,r) << ' ';
	}
	return 0;
}