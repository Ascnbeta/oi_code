#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+20;
int n,m;
vector<int> e[maxn];
int dep[maxn],f[maxn],son[maxn],size[maxn],dfn[maxn],top[maxn],cnt;
void dfs1(int u,int fa) {
	dep[u] = dep[fa] + 1;
	size[u] = 1;
	son[u] = 0;
	for (auto &v : e[u]) {
		if (v == fa) continue;
		f[v] = u;
		dfs1(v,u);
		size[u] += size[v];
		if (size[v] > size[son[u]]) son[u] = v;
	}
}
void dfs2(int u,int fa,int tp) {
	top[u] = tp;
	dfn[u] = ++cnt;
	if (son[u] == 0) return;
	dfs2(son[u],u,tp);
	for (auto &v : e[u]) {
		if (v == fa || v == son[u]) continue;
		dfs2(v,u,v);
	}
}
inline int lca(int x,int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] > dep[top[y]]) {
			x = f[top[x]];
		}else{
			y = f[top[y]];
		}
	}
	return dep[x] > dep[y] ? y : x;
}
int main () {
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	} 
	dfs1(1,0);
	dfs2(1,0,1);
	while (m--) {
		int x,y,z;
		cin >> x >> y >> z;
		int ans1 = lca(x,y) ^ lca(x,z) ^ lca(y,z);
		int ans2 = dep[x]+dep[y]+dep[z]-dep[lca(x,y)]-dep[lca(x,z)]-dep[lca(y,z)];
		cout << ans1 << ' ' << ans2 << '\n';
	}
	return 0;
}