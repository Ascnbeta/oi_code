<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+4;
int n,m;
struct edge{
	int to,w;
};
vector<edge> e[maxn];
int f[maxn][25],res[maxn][25],dep[maxn];
void dfs(int u,int fa) {
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i].to;
		if (v == fa) continue;
		dfs(v,u);
		res[v][0] = e[u][i].w;
	}
}
inline void init() {
	int k = log2(n) + 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i-1]][i-1];
			res[j][i] = res[j][i-1] ^ res[f[j][i-1]][i-1];
		}
	}
}
inline int lca(int x,int y) {
	if (dep[x] > dep[y]) swap(x,y);
	int k = log2(dep[y])+1,ret = 0;
	if (dep[x] != dep[y]) {
		for (int i = k; i >= 0; i--) {
			if (f[y][i] != 0 && dep[x] <= dep[f[y][i]]){
				ret ^= res[y][i];
				y = f[y][i];
			}
		}
	}
	if (x == y) return ret;
	for (int i = k; i >= 0; i--) {
		if (f[y][i] != 0 && f[x][i] != 0 && f[x][i] != f[y][i]) {
			ret ^= res[x][i];
			ret ^= res[y][i];
			x = f[x][i];
			y = f[y][i];
		}
	}
	return ret^res[x][0]^res[y][0];
}
int main () {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	dfs(1,0);
	init();
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a,b;
		cin >> a >> b;
		cout << lca(a,b) << '\n';
	}
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+4;
int n,m;
struct edge{
	int to,w;
};
vector<edge> e[maxn];
int f[maxn][25],res[maxn][25],dep[maxn];
void dfs(int u,int fa) {
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i].to;
		if (v == fa) continue;
		dfs(v,u);
		res[v][0] = e[u][i].w;
	}
}
inline void init() {
	int k = log2(n) + 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i-1]][i-1];
			res[j][i] = res[j][i-1] ^ res[f[j][i-1]][i-1];
		}
	}
}
inline int lca(int x,int y) {
	if (dep[x] > dep[y]) swap(x,y);
	int k = log2(dep[y])+1,ret = 0;
	if (dep[x] != dep[y]) {
		for (int i = k; i >= 0; i--) {
			if (f[y][i] != 0 && dep[x] <= dep[f[y][i]]){
				ret ^= res[y][i];
				y = f[y][i];
			}
		}
	}
	if (x == y) return ret;
	for (int i = k; i >= 0; i--) {
		if (f[y][i] != 0 && f[x][i] != 0 && f[x][i] != f[y][i]) {
			ret ^= res[x][i];
			ret ^= res[y][i];
			x = f[x][i];
			y = f[y][i];
		}
	}
	return ret^res[x][0]^res[y][0];
}
int main () {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	dfs(1,0);
	init();
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a,b;
		cin >> a >> b;
		cout << lca(a,b) << '\n';
	}
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}