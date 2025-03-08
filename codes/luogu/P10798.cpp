#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
int a[500004],b[500004];
int st[500004][30],f[500004];
bool ud[500004],b0;
int g0[500004],g[500004];
vector<int> pos[500004];
int p[500004];
inline void init() {
	for (int i = 2; i <= n; i++) f[i] = f[i/2]+1;
	for (int i = 1; (1<<i) <= n; i++) {
		for (int j = 1; j+(1<<i)-1 <= n; j++) {
			st[j][i] = max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
	for (int i = 1; i <= n; i++) {
		g0[i] = i*(i-1)/2;
		g[i] = g[i-1]+(i-1)/2;
	}
}
inline int query(int l,int r) {
	int j = f[r-l+1];
	return max(st[l][j],st[r-(1<<j)+1][j]);
}
signed main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) b0 = true;
		a[i] = abs(a[i]);
		b[i] = a[i];
	}
	sort(b+1,b+n+1);
	int n1 = unique(b+1,b+n+1)-b-1;
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(b+1,b+n1+1,a[i])-b;
		pos[a[i]].push_back(i);
		st[i][0] = a[i];
	}
	init();
	for (int i = 1; i <= n; i++) {
		if (ud[i]) continue;
		int j = p[a[i]],cnt = 0;
		for (;j < pos[a[i]].size(); j++) {
			if (query(i,pos[a[i]][j]) > a[i]) break;
			++cnt;
		}
		if (b0 && a[i] == 1) ans += g0[cnt];
		else ans += g[cnt];
		p[a[i]] = j;
	}
	cout << ans << '\n';
	return 0;
}