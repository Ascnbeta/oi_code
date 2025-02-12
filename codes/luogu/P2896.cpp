#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+20;
int n;
int c[maxn],ans = LONG_LONG_MAX;
struct edge{
	int v,w;
};
vector<edge> e[maxn];
int f[maxn],sum[maxn],f1[maxn];
void dfs1(int u,int fa) {
	f[u] = 0;
	for (auto &i : e[u]) {
		int v = i.v;
		if (v == fa) continue;
		dfs1(v,u);
		sum[u] += sum[v];
		f[u] += f[v]+sum[v]*i.w;
	}
}
void dfs2(int u,int fa) {
	for (auto &i : e[u]) {
		int v = i.v;
		if (v == fa) continue;
		f1[v] = f1[u] + (sum[u] - 2 * sum[v]) * i.w;
		sum[v] = sum[u];
		// cout << "debug: " << v << ' ' << f1[v] << '\n';
		ans = min(ans,f1[v]);
		dfs2(v,u);
	}
}
signed main () {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i],sum[i] = c[i];
	for (int i = 1; i < n; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	dfs1(1,0);
	ans = min(ans,f[1]);
	f1[1] = f[1];
	dfs2(1,0);
	cout << ans << '\n';
	return 0;
}