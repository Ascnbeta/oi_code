#include <bits/stdc++.h>
using namespace std;
int n,m;
int q;
int a[304][304],sum[103][304][304];
int t[102][304][304];
inline int lowbit(int x) {
	return x&-x;
}
inline void build() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				t[i][j][k] = sum[i][j][k] - sum[i][j-lowbit(j)][k] - sum[i][j][k-lowbit(k)] + sum[i][j-lowbit(j)][k-lowbit((k))];
			}
		} 
	}
}
inline void modify(int x,int y,int c) {
	for (int i = x; i <= n; i += lowbit(i)) {
		for (int j = y; j <= m; j += lowbit(j)) {
			t[a[x][y]][i][j] -= 1;
			t[c][i][j] += 1;
 		}
	}
	a[x][y] = c;
} 
inline int query(int x,int y,int c) {
	int ret = 0;
	for (int i = x;i > 0; i -= lowbit(i)) {
		for (int j = y; j > 0; j -= lowbit(j)) {
			ret += t[c][i][j];
		}
	}
	return ret;
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			for (int k = 1; k <= 100; k++) {
				if (k == a[i][j]) sum[k][i][j] = 1 + sum[k][i-1][j] + sum[k][i][j-1]- sum[k][i-1][j-1];
				else sum[k][i][j] = sum[k][i-1][j] + sum[k][i][j-1]- sum[k][i-1][j-1];
			}
//			modify(i,j,a[i][j]);
		}
	}
	cin >> q;
	while(q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x,y,c;
			cin >> x >> y >> c;
			modify(x,y,c);
		}else{
			int x1,x2,y1,y2,c;
			cin >> x1 >> x2 >> y1 >> y2 >> c;
			cout << query(x2,y2,c) - query(x1-1,y2,c) - query(x2,y1-1,c) + query(x1-1,y1-1,c) + 1 << '\n';
		}
	}
	return 0;
}
