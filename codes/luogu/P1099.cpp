#include <bits/stdc++.h>
using namespace std;
const int maxn = 300012;
int n,s,ans = 0x3f3f3f3f;
struct edge{
	int v,w;
};
vector<edge> e[maxn];
int x0,x1,x2,d;
int f[maxn],dis[maxn];
bool vis[maxn];
void dfs1(int u,int fa) {
	for (auto i : e[u]) {
		int v = i.v,w = i.w;
		if (v == fa) continue;
		f[v] = u;
		dis[v] = dis[u] + w;
		if (dis[v] > d) {
			d = dis[v];
			x0 = v;
		}
		dfs1(v,u);
	}
}
void dfs2(int u,int fa) {
	for (auto i : e[u]) {
		int v = i.v,w = i.w;
		if (v == fa || vis[v]) continue;
		f[v] = u;
		dis[v] = dis[u] + w;
		dfs2(v,u); 
	}
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> s;
	for (int i = 1; i < n; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	dfs1(1,0);
	x1 = x0;
	d = 0;
	memset(dis,0,sizeof(dis));
	memset(f,0,sizeof(f));
	dfs1(x1,0);
	x2 = x0;
	for (int i = x2; i; i = f[i]) {
		vis[i] = true;
	}
	for (int i = x2,j = x2;;j = f[j]) {
		while (dis[i] - dis[j] > s) i = f[i];
		ans = min(ans,max(dis[j],dis[x2]-dis[i]));
		if (j == x1) break; 
	}
	memset(dis,0,sizeof(dis));
	memset(f,0,sizeof(f));
	for (int i = 1; i <= n; i++) {
		if (vis[i]) dfs2(i,f[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) ans = max(ans,dis[i]);
	}
	cout << ans << '\n';
	return 0;
}