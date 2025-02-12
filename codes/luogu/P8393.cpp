#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+10;
int n,m;
vector<int> e[maxn],e1[maxn];
struct node{
	int id,w;
	bool operator < (const node &y) const{
		return w < y.w;
	}
}s[maxn];
int father[maxn],w[maxn];
bool vis[maxn];
inline int find(int x) {
	int t = x;
	while (x != father[x]) x = father[x];
	int w;
	while (t != father[t]) w = father[t],father[t] = x,t = w;
	return x;
} 
void kruskal() {
	for (int i = 1; i <= n; i++) {
		vis[s[i].id] = true;
		for (int j = 0; j < e[s[i].id].size(); j++) {
			int v  = e[s[i].id][j];
			if (vis[v] && find(v) != s[i].id) {
				//cout << s[i].id << ' ' << v << ' ' << find(v) << '\n';
				e1[s[i].id].push_back(find(v));
				e1[find(v)].push_back(s[i].id);
				father[find(v)] = s[i].id;
			}
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j < e1[i].size(); j++) {
	// 		cout << i << ' ' << e1[i][j] << '\n';
	// 	}
	// }
}
int sum[maxn];
bool f[maxn];
void dfs1(int u,int fa) {
	sum[u] += w[u];
	for (auto &v : e1[u]) {
		if (v == fa) continue;
		dfs1(v,u);
		sum[u] += sum[v];
	}
	if (fa == -1 || sum[u] >= w[fa]) f[u] = true;
}
void dfs2(int u,int fa) {
	if (fa != -1 && !f[fa])  f[u] = false;
	for (auto &v : e1[u]) {
		if (v == fa) continue;
		dfs2(v,u);
	}
}
signed main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> s[i].w,s[i].id = i,w[i] = s[i].w;
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) father[i] = i;
	sort(s+1,s+n+1);
	kruskal();
	dfs1(s[n].id,-1);
	dfs2(s[n].id,-1);
	for (int i = 1; i <= n; i++) {
		if (f[i]) cout << '1';
		else cout << '0';
	}
	cout << '\n';
	return 0;
}