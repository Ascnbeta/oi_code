#include <bits/stdc++.h>
using namespace std;
const int mod = 1e4+7;
int n;
struct edge{
	int to,nxt;
}e[400005];
int head[100004],tot;
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int w[200005];
int ans1 = 0,ans2 = 0;
void dfs(int u,int fa) {
	int maxx = 0,sum = 0;
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v,u);
		ans1 = max(ans1,max(w[v]*w[fa],w[v]*maxx));
		ans2 = (ans2 % mod + sum * w[v] % mod) % mod;
		ans2 = (ans2 % mod + w[v] * w[fa] % mod) % mod;
		sum += w[v];
		sum %= mod;
		maxx = max(maxx,w[v]);
	}
}
int main () {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	for (int i = 1; i <= n; i++) cin >> w[i];
	dfs(1,0);
	cout << ans1 << ' ' << ans2 * 2 % mod << '\n';
	return 0;
}