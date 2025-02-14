<<<<<<< HEAD
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
vector<int> e[100004];
int d[50004],sum[50004];
int f[50004][20],dep[50004];
inline void dfs1(int u,int fa) {
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (v == fa) continue;
		dfs1(v,u);
	}
}
inline void init() {
	int k = log2(n)+1;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i-1]][i-1];
		}
	}
}
inline int lca(int x,int y) {
	if (dep[x] > dep[y]) swap(x,y);
	int k = log2(dep[y])+1;
	if (dep[x] != dep[y]) {
		for (int i = k; i >= 0; i--) {
			if (f[y][i] != 0 && dep[x] <= dep[f[y][i]]) y = f[y][i];
		}
	}
	if (x == y) return x;
	for (int i = k; i >= 0; i--) {
		if (f[x][i] != 0 && f[y][i] != 0 && f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];
	}
	return f[x][0];
}
inline void modify(int s,int t) {
	d[s] += 1;
	d[t] += 1;
	d[lca(s,t)] -= 1;
	d[f[lca(s,t)][0]] -= 1;
}
inline void dfs2(int u,int fa) {
	sum[u] += d[u];
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (v == fa) continue;
		dfs2(v,u);
		sum[u] += sum[v];
	}
	ans = max(ans,sum[u]);
}
signed main () {
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);
	init();
	for (int i = 1; i <= k; i++) {
		int s,t;
		cin >> s >> t;
		modify(s,t);
	}
	dfs2(1,0);
	cout << ans << '\n';
	return 0;
=======
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
vector<int> e[100004];
int d[50004],sum[50004];
int f[50004][20],dep[50004];
inline void dfs1(int u,int fa) {
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (v == fa) continue;
		dfs1(v,u);
	}
}
inline void init() {
	int k = log2(n)+1;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i-1]][i-1];
		}
	}
}
inline int lca(int x,int y) {
	if (dep[x] > dep[y]) swap(x,y);
	int k = log2(dep[y])+1;
	if (dep[x] != dep[y]) {
		for (int i = k; i >= 0; i--) {
			if (f[y][i] != 0 && dep[x] <= dep[f[y][i]]) y = f[y][i];
		}
	}
	if (x == y) return x;
	for (int i = k; i >= 0; i--) {
		if (f[x][i] != 0 && f[y][i] != 0 && f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];
	}
	return f[x][0];
}
inline void modify(int s,int t) {
	d[s] += 1;
	d[t] += 1;
	d[lca(s,t)] -= 1;
	d[f[lca(s,t)][0]] -= 1;
}
inline void dfs2(int u,int fa) {
	sum[u] += d[u];
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (v == fa) continue;
		dfs2(v,u);
		sum[u] += sum[v];
	}
	ans = max(ans,sum[u]);
}
signed main () {
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);
	init();
	for (int i = 1; i <= k; i++) {
		int s,t;
		cin >> s >> t;
		modify(s,t);
	}
	dfs2(1,0);
	cout << ans << '\n';
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}