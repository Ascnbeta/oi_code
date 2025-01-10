#include <bits/stdc++.h>
using namespace std;
int n,m,q;
struct edge{
	int to,nxt,w;
}e[400005];
int head[100004],tot;
void add(int u,int v,int w) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	e[tot].w = w;
	head[u] = tot;
}
bool f[100004];
int dis[100004];
void dfs(int u) {
	f[u] = true;
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (f[v]) continue;
		dis[v] = dis[u]^e[i].w;
		dfs(v);
	}
}
int main () {
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1);
	while (q--) {
		int x,y;
		cin >> x >> y;
		cout << (dis[x]^dis[y]) << '\n';
	}
	return 0;
}