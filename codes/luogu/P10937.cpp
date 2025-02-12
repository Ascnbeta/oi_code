#include <bits/stdc++.h>
using namespace std;
int n,m,t,ans;
vector<int> e[203];
bool f[203][203];
int match[203],vis[203];
bool hungary(int p,int tgt) {
	if (vis[p] == tgt) return false;
	vis[p] = tgt;
	for (int v : e[p]) {
		if (!match[v]||hungary(match[v],tgt)) {
			match[v] = p;
			return true;
		}
	}
	return false;
}
int main () {
	cin >> n >> m >> t;
	for (int i = 1; i <= t; i++) {
		int x,y;
		cin >> x >> y;
		f[x][y] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!f[i][j]) e[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (hungary(i,i)) ++ans;
	}
	cout << ans << '\n';
	return 0;
}