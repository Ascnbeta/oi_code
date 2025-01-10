#include <bits/stdc++.h>
using namespace std;
int n,m,ans = 0x3f3f3f3f,hi = 0x3f3f3f3f;
char ch;
int f[17][105];
struct floor{
	int cnt,l,r;
}fl[17];
void dfs(int x,int y,int res) {
	if (x == hi) {
		if (y == 1) {
			ans = min(ans,res+fl[x].r-1);
			return;
		}
		if (y == m) {
			ans = min(ans,res+m-fl[x].l);
			return;
		}
	}
	if (fl[x].cnt == 0) {
		dfs(x-1,y,res+1);
		return;
	}
	if (y == 1) {
		dfs(x-1,1,res+2*(fl[x].r-1)+1);
		dfs(x-1,m,res+m);
	}
	if (y == m) {
		dfs(x-1,1,res+m);
		dfs(x-1,m,res+2*(m-fl[x].l)+1);
	}
}
int main () {
	cin >> n >> m;
	m += 2;
	for (int i = 1; i <= n; i++) {
		int cnt = 0,l = 0,r = 0;
		for (int j = 1; j <= m; j++) {
			cin >> ch;
			if (ch == '1') {
				f[i][j] = 1;
				if (cnt == 0) l = j;
				r = j;
				++cnt;
			}
			
		}
		fl[i].cnt = cnt,fl[i].l = l,fl[i].r = r;
		if (cnt != 0) hi = min(hi,i);
	}
	if (hi == 0x3f3f3f3f) {
		cout << 0 << endl;
		return 0;
	}
//	for (int i = 1; i <= n ; i++) {
//			cout << fl[i].cnt << ' ' << fl[i].l << ' ' << fl[i].r << endl;
//	}
	dfs(n,1,0);
	cout << ans << endl;
	return 0;
}
