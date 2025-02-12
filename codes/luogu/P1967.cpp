#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+8;
const int maxm = 1e5+6;
int n,m,q;
struct edge{
	int u,v,w;
	bool operator < (const edge &y) const{
		return w > y.w;
	}
}ed[maxm];
int father[maxn],rk[maxn];
inline int find(int x) {
	int t = x;
	while (x != father[x]) x = father[x];
	int w;
	while (t != father[t]) w = father[t],father[t] = x,t = w;
	return x;
}
inline void merge(int x,int y) {
	int p = find(x),q = find(y);
	if (rk[p] <= rk[q]) {
		father[p] = q;
		rk[q] = max(rk[p]+1,rk[q]);
	}else{
		father[q] = p;
		rk[p] = max(rk[q]+1,rk[p]);
	}
}
struct node{
	int to,w;
};
vector<node> e[maxn];
inline void kruskal() {
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= m; i++) {
		if (find(ed[i].u) != find(ed[i].v)) {
			e[ed[i].u].push_back({ed[i].v,ed[i].w});
			e[ed[i].v].push_back({ed[i].u,ed[i].w});
			//cout << ed[i].u << ed[i].v << '\n';
			merge(ed[i].u,ed[i].v);
		}
	}
}
int f[maxn][20],dep[maxn],minn[maxn][20];
bool vis[maxn];
void dfs(int u,int fa) {
	//cout << u << '\n';
	vis[u] = true;
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i].to;
		if (v == fa) continue;
		dfs(v,u);
		minn[v][0] = e[u][i].w;
	}
}
inline void init() {
	int k = log2(n) + 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i-1]][i-1];
			minn[j][i] = min(minn[j][i-1],minn[f[j][i-1]][i-1]);
		}
	}
}
inline int lca(int x,int y) {
	if (find(x) != find(y)) return -1;
	if (dep[x] > dep[y]) swap(x,y);
	int k = log2(dep[y]) + 1,ret = 0x3f3f3f3f;
	//cout << k << '\n';
	if (dep[x] != dep[y]) {
		for (int i = k; i >= 0; i--) {
			// puts("1");
			if (f[y][i] != 0 && dep[f[y][i]] >= dep[x]) ret = min(ret,minn[y][i]),y = f[y][i];
		}
	}
	if (x == y) return ret;
	for (int i = k; i >= 0; i--) {
		if (f[x][i] != 0 && f[y][i] != 0 && f[x][i] != f[y][i]) {
			// puts("1");
			//cout << minn[x][i] << '\n';
			ret = min(ret,minn[x][i]);
			ret = min(ret,minn[y][i]);
			x = f[x][i];
			y = f[y][i];
		}
	}
	return min(minn[x][0],min(minn[y][0],ret));
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> ed[i].u >> ed[i].v >> ed[i].w;
	}
	memset(minn,0x3f,sizeof(minn));
	sort(ed+1,ed+m+1);
	kruskal();
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i,0);
	}
	init();
	cin >> q;
	while (q--) {
		int x,y;
		cin >> x >> y;
		cout << lca(x,y) << '\n';
	}
	return 0;
}