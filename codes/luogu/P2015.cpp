#include <bits/stdc++.h>
using namespace std;
int n,q;
struct edge{
	int to,nxt,w;
}e[60004];
int head[30004],tot;
void add(int u,int v,int w) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	e[tot].w = w;
	head[u] = tot;
}
int r[30004];
int f[30004][304];
void dfs(int u,int fa) {
	for (int i = 0; i <= q; i++) f[u][i] = r[u];
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		r[v] = e[i].w;
		dfs(v,u);
		for (int j = q; j >= 0; j--) {
			for (int k = 0; k < j; k++) {
				f[u][j] = max(f[u][j],f[u][j-k-1]+f[v][k]);
			}
		}
	}
}
int main () {
	cin >> n >> q;
	for (int i = 1; i <= n - 1; i++) {
		int x,y,w;
		cin >> x >> y >> w;
		add(x,y,w);
		add(y,x,w);
	}
	dfs(1,0);
	cout << f[1][q] << '\n';
	return 0;
}