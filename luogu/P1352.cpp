#include <bits/stdc++.h>
using namespace std;
int n;
int r[6004];
struct edge{
	int to,nxt;
}e[12004];
int head[6004],tot;
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int f[6005][2];
void dfs(int u,int fa) {
	f[u][1] = r[u];
	f[u][0] = 0;
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v,u);
		f[u][1] += f[v][0];
		f[u][0] += max(f[v][1],f[v][0]);
	}
}
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		int l,k;
		cin >> l >> k;
		add(l,k);
		add(k,l);
	}
	memset(f,0xcf,sizeof(f));
	dfs(1,0);
	cout << max(f[1][0],f[1][1]) << '\n';
	return 0;
}