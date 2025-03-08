#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2+4;
int n;
vector<int> e[maxn];
int f[maxn],dep[maxn],d,w,cnt[maxn];
void dfs(int u,int fa) {
	f[u] = fa;
	dep[u] = dep[fa] + 1;
	cnt[dep[u]]++;
	d = max(d,dep[u]);
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (v == fa) continue;
		dfs(v,u);
	}
}
inline int lca(int x,int y) {
	if (x == y) return 0;
	int cntx = 0,cnty = 0;
	if (dep[x] > dep[y]) {
		while (dep[x] != dep[y]) {
			x = f[x];
			cntx++;
		}
	}
	if (dep[x] < dep[y]) {
		while (dep[x] != dep[y]) {
			y = f[y];
			cnty++;
		}
	}
	while (x != y) {
		x = f[x],y = f[y];
		++cntx,++cnty;
	}
	return cntx * 2 + cnty;
}
int main () {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	cout << d << '\n';
	for (int i = 1; i <= n; i++) {
		w = max(w,cnt[i]);
	}
	cout << w << '\n';
	int x,y;
	cin >> x >> y;
	cout << lca(x,y) << '\n';
	return 0;
}