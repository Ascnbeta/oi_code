#include <bits/stdc++.h>
using namespace std;
int n;
struct edge{
	int to,nxt;
}e[32005];
int head[16004],tot;
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot; 
}
int r[16007];
int f[16007],ans = INT_MIN;
void dfs(int u,int fa) {
	f[u] = r[u];
	for (int i = head[u];i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v,u);
		f[u] = max(f[u],f[u]+f[v]);
	}
	ans = max(ans,f[u]);
}
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> r[i];
	for (int i = 1; i <= n - 1; i++) {
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	cout << ans << '\n';
	return 0;
}