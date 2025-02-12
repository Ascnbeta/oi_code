#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int n,m;
struct edge{
	int v,id;
};
vector<edge> e[maxn];
int fr[maxn],to[maxn],co[maxn];
int num[maxn],cnt = 0;
int father[maxn];
inline int find(int x) {
	int t = x;
	while (x != father[x]) x = father[x];
	int w;
	while (t != father[t]) w = father[t],father[t] = x,t = w;
	return father[x];
}
inline void merge(int x,int y) {
	int p = find(x),q = find(y);
	if (p == q) return;
	father[q] = p;
}
int dep[maxn],f[maxn][20],g[maxn];
void dfs(int u,int fa) {
	f[u][0] =fa;
	dep[u] = dep[fa] + 1;
	for (auto &i : e[u]) {
		if (i.v == fa) continue;
		g[i.v] = i.id;
		dfs(i.v,u);
		
	}
}
inline void init() {
	int k = __lg(n) + 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (f[j][i-1] != 0) f[j][i] = f[f[j][i-1]][i-1];
		}
	}
}
inline int lca(int x,int y) {
	if (dep[x] > dep[y]) swap(x,y);
	int k = __lg(dep[y])+1;
	if (dep[y] > dep[x]) {
		for (int i = k; i >= 0; i--) {
			if (f[y][i] && dep[y]-(1<<i) >= dep[x]) y = f[y][i];
		}
	}
	if (x == y) return x;
	for (int i = k; i >= 0; i--) {
		if (f[x][i] && f[y][i] && f[x][i] != f[y][i]) {
			x = f[x][i],y = f[y][i];
		}
	}
	return f[x][0];
}
vector<int> v;
bool cmp(int x,int y) {
	return g[x] < g[y];
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> m;
	// if (m == n-1) {
	// 	for (int i = 1; i <= m; i++) cout << i << ' ';
	// 	cout << '\n';
	// 	return 0;
	// }
	for (int i = 1; i <= m; i++) {
		int u,v,c;
		cin >> u >> v >> c;
		fr[i] = u,to[i] = v,co[i] = c;
		if (c == 1) {
			e[u].push_back({v,i});
			e[v].push_back({u,i});
			// puts("x");
		}
	}
	dfs(1,0);
	init();
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= m; i++) {
		if (dep[fr[i]]>dep[to[i]]) swap(fr[i],to[i]);
	}
	for (int i = 1; i <= m; i++) {
		if (num[i]) continue;
		if (co[i] == 1) {
			num[i] = ++cnt;
			merge(fr[i],to[i]);
		}else{
			if (find(fr[i]) == find(to[i])) num[i] = ++cnt;
			else{
				v.clear();
				int x = find(fr[i]),y = find(to[i]);
				int lc = lca(x,y);
				// cout << lc << '\n';
				while (dep[x]>dep[lc]) {
					v.push_back(x);
					x = find(f[x][0]);
				}
				while (dep[y]>dep[lc]) {
					v.push_back(y);
					y = find(f[y][0]);
				}
				sort(v.begin(),v.end(),cmp);
				for (int j = 0; j < v.size(); j++) {
					num[g[v[j]]] = ++cnt;
					merge(fr[g[v[j]]],to[g[v[j]]]);

					// cout << v[j] << '\n';
				}
				num[i] = ++cnt;
			}
		}
	}
	for (int i = 1; i < m; i++) cout << num[i] << ' ';
		cout << num[m] << '\n';
	return 0;
}