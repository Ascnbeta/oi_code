#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4+10;
int n,ans = 0x3f3f3f3f,minn = 0x3f3f3f3f;
vector<int> e[maxn];
int f[maxn],g[maxn];
void dfs(int u,int fa) {
	f[u] = 1;
	for (auto v : e[u]) {
		if (v == fa) continue;
		dfs(v,u);
		f[u] += f[v];
		g[u] = max(g[u],f[v]);
	}
	g[u] = max(g[u],n-f[u]);
	if (g[u] < minn) {
		minn = g[u];
		ans = u;
	}else if(g[u] == minn) {
		ans = min(ans,u);
	}
} 
void dfs2(int u,int fa) {
	
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	cout << ans << '\n';
	dfs2(ans,0);
	return 0;
}