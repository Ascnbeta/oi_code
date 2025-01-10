#include <bits/stdc++.h>
using namespace std;
int n,p;
struct edge{
	int to,nxt;
}e[320];
int head[160],tot;
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int f[160][160],sum[160];
void dfs(int u,int fa) {
	f[u][1] = 0;
	sum[u] = 1;
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v,u);
		sum[u] += sum[v];
		for (int j = sum[u]; j >= 1; j--) {
			f[u][j] += 1;
			for (int k = 0; k <= min(j-1,sum[v]); k++) {
				f[u][j] = min(f[u][j],f[u][j-k]+f[v][k]);
			}
		}
	}
}
int main () {
	cin >> n >> p;
	for (int i = 1; i <= n - 1; i++) {
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	memset(f,0x3f,sizeof(f));
	dfs(1,0);
	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		if (i != 1) f[i][p]++;
		ans = min(ans,f[i][p]);
	}
	cout << ans << '\n';
	return 0;
}