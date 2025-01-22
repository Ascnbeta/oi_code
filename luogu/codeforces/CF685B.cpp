#include <bits/stdc++.h>
using namespace std;
int n,q;
struct edge{
	int to,nxt;
}e[300004];
int head[300004],tot;
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int f[300005],g[300005],p[300005];
void dfs(int u) {
	f[u] = 1;
	g[u] = u;
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		dfs(v);
		f[u] += f[v];
	}
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (f[v] * 2 > f[u]) {
			g[u] = g[v];
			while(g[u] != u) {
				if (f[g[u]] * 2 >= f[u]) break;
				g[u] = p[g[u]];
			}
		}
	}
}
int main () {
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		add(x,i);
		p[i] = x;
	}
	dfs(1);
	while(q--) {
		int r;
		cin >> r;
		cout << g[r] << '\n';
	}
	return 0;
}