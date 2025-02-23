#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+23;
int n,m;
int a[maxn];
vector<int> e[maxn];
int dep[maxn],dfn[maxn],top[maxn],son[maxn],f[maxn],siz[maxn],cnt;
int ans[maxn];
void dfs1(int u) {
	dep[u] = dep[f[u]] + 1;
	son[u] = 0;
	siz[u] = 1;
	for (auto v : e[u]) {
		if (v == f[u]) continue;
		f[v] = u;
		dfs1(v);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs2(int u,int tp) {
	top[u] = tp;
	dfn[u] = ++cnt;
	if (son[u] == 0) return;
	dfs2(son[u],tp);
	for (auto v : e[u]) {
		if (v == f[u] || v == son[u]) continue;
		dfs2(v,v);
	}
}
inline int get_lca(int x,int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] >= dep[top[y]]) {
			x = f[top[x]];
		}else{
			y = f[top[y]];
		}
	}
	return dep[x] > dep[y] ? y : x;
}
void dfs3(int u) {
	for (auto v : e[u]) {
		if (v == f[u]) continue;
		dfs3(v);
		ans[u] += ans[v];
	}
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1);
	dfs2(1,1);
	for (int i = 2; i <= n; i++) {
		int lca = get_lca(a[i-1],a[i]);
		++ans[a[i-1]],++ans[a[i]],--ans[lca],--ans[f[lca]];
	}
	dfs3(1);
	for (int i = 1; i <= n; i++) {
		if (i == a[1]) {
			cout << ans[i] << '\n';
		}else{
			cout << ans[i]-1 << '\n';
		}
	}
	return 0;
}