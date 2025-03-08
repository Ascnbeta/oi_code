#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int tp,c;
}s[3004];
struct edge{
	int to,nxt,w;
}e[12004];
int head[3004],tot;
void add(int u,int v,int w) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	e[tot].w = w;
	head[u] = tot;
}
int f[3004][3004],r[3004],sum[3004];
void dfs(int u,int fa) {
	f[u][0] = 0;
	if (s[u].tp == 2) {
		f[u][1] = s[u].c;
		sum[u] = 1;
		return;
	}
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v,u);
		sum[u] += sum[v];
		for (int k = sum[u]; k > 0; k--) {
			for (int j = 1; j <= sum[v]; j++) {
				if (k >= j) f[u][k] = max(f[u][k],f[u][k-j]+f[v][j]-e[i].w);
			}
		}
	}
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n - m; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 1; j <= cnt; j++) {
			int x,y;
			cin >> x >> y;
			if (x >= 1 && x <= n - m) s[x].tp = 1;
			else s[x].tp = 2;
			add(i,x,y);
			add(x,i,y);
		}
	}
	for (int i = n - m + 1; i <= n; i++) {
		int x;
		cin >> x;
		s[i].c = x;
	}
	memset(f,0xcf,sizeof(f));
	dfs(1,0);
	int ans = 0;
	for (int i = 0; i <= m; i++) {
		// cout << f[1][i] << ' ';
		if (f[1][i] >= 0) ans = max(ans,i);
	}
	cout << ans << '\n';
	return 0;
}