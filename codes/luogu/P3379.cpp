#include <bits/stdc++.h>
using namespace std;
const int maxn = 500004;
int n,m,s;
vector<int> e[maxn],q[maxn],id[maxn];
int ans[maxn];
int dep[maxn],father[maxn];
bool vis[maxn];
inline int find(int x) {
	int t = x;
	while (x != father[x]) x = father[x];
	int w;
	while (t != father[t]) w = father[t],father[t] = x,t = w;
	return x;
}
void tarjan(int u,int fa) {
	vis[u] = true;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (v == fa) continue;
		tarjan(v,u);
	}
	for (int i = 0; i < q[u].size(); i++) 
		if (vis[q[u][i]]) ans[id[u][i]] = find(q[u][i]);
	father[u] = fa;
}
int main () {
	cin >> n >> m >> s;
	for (int i = 1; i <= n - 1; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		father[i] = i;
	}
	father[n] = n;
	for (int i = 1; i <= m; i++) {
		int a,b;
		cin >> a >> b;
		q[a].push_back(b);
		q[b].push_back(a);
		id[a].push_back(i);
		id[b].push_back(i);
	}
	tarjan(s,0);
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}