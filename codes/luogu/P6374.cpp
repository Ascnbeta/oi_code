#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+20;
int n,q;
vector<int> e[maxn];
int top[maxn],dep[maxn],son[maxn],siz[maxn],fa[maxn],dfn[maxn],rnk[maxn],out[maxn],cnt;
void dfs1(int u) {
	dep[u] = dep[fa[u]] + 1;
	son[u] = 0;
	siz[u] = 1;
	for (auto v : e[u]) {
		if (v == fa[u]) continue;
		fa[v] = u;
		dfs1(v);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs2(int u,int tp) {
	top[u] = tp;
	dfn[u] = ++cnt;
	rnk[cnt] = u;
	if (son[u] == 0) {
		out[u] = cnt;
		return;
	}
	dfs2(son[u],tp);
	for (auto v : e[u]) {
		if (v == fa[u] || v == son[u]) continue;
		dfs2(v,v);
	}
	out[u] = cnt;
}
inline int get_lca(int u,int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] >= dep[top[v]]) {
			u = fa[top[u]];
		}else{
			v = fa[top[v]];
		}
	}
	return dep[u] > dep[v] ? v : u;
}
inline int find(int x,int f){
	if (x == f) return 0;
	while (top[x] != top[f]) {
		if (fa[top[x]]==f) return top[x];
		x = fa[top[x]];
	}	
	return son[f];
}		
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1);
	dfs2(1,1);
	// cout << top[2] << '\n';
	// cout << find(20,20) << "s\n";
	// puts("qwq");
	while (q--) {
		int a,b,c;
		cin >> a >> b >> c;
		if (get_lca(a,b) == c) {
			cout << n - siz[find(a,c)] - siz[find(b,c)] << '\n';
		}else if (dfn[c] <= dfn[a] && dfn[a] <= out[c] && !(dfn[c] <= dfn[b] && dfn[b] <= out[c])) {
			cout << siz[c] - siz[find(a,c)] << '\n';
		}else if(dfn[c] <= dfn[b] && dfn[b] <= out[c] && !(dfn[c] <= dfn[a] && dfn[a] <= out[c])){
			// puts("awa");
			cout << siz[c] - siz[find(b,c)] << '\n';
		}else{
			cout << 0 << '\n';
		}
	}
	return 0;
}