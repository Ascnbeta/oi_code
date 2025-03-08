#include <bits/stdc++.h>
using namespace std;
const int N = 5e4+4;
int n,q;
int st1[N][30],st2[N][30];
int h[N];
int f[N];
void init() {
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st1[i][j] = max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
			st2[i][j] = min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int l,int r) {
	int j = f[r-l+1];
	int q1 = max(st1[l][j],st1[r-(1<<j)+1][j]);
	int q2 = min(st2[l][j],st2[r-(1<<j)+1][j]);
	return q1 - q2;
}
int main () {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		st1[i][0] = st2[i][0] = h[i];
	}
	f[1] = 0;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i/2]+1;
		// cout << f[i] << ' ';
	}
	init();
	while (q--) {
		int x,y;
		cin >> x >> y;
		cout << query(x,y) << '\n';
	}
	return 0;
}