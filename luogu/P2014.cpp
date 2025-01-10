#include <bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
	int to,nxt;
}e[306];
int head[305],tot,c[305];
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int f[305][305],ans;
void dfs(int p) {
	f[p][0] = 0;
	f[p][1] = c[p];
	for (int i = head[p];i;i = e[i].nxt) {
		dfs(e[i].to);
		for (int j = m + 1; j >= 1; j--) {
			for (int k = 0; k < j; k++) {
				f[p][j] = max(f[p][j],f[p][j-k]+f[e[i].to][k]);
			}
		}
	}
	
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x,y;
		cin >> x >> y;
		c[i] = y;
		add(x,i);
	}
	dfs(0);
	for (int i = 1; i <= m+1; i++) {
		ans = max(ans,f[0][i]);
	}
	cout << ans << '\n';
	return 0;
}