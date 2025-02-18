#include <bits/stdc++.h>
using namespace std;
int n,W,ans;
int e[203][203];
int dis[203];bool vis[203];
inline void prim() {
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	ans = 0;
	dis[1] = 0;
	for (int i = 1; i < n; i++) {
		int p = 0;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]&&(p==0||dis[j]<dis[p])) p = j;
		}
		vis[p] = true;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) dis[j] = min(dis[j],e[p][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dis[i] == 0x3f3f3f3f) {
			puts("-1");
			return;
		}
		ans += dis[i];
	}
	cout << ans << '\n';
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> W;
	memset(e,0x3f,sizeof(e));
	for (int i = 1; i <= W; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u][v] = e[v][u] = min(e[u][v],w);
		prim();
	}
	return 0;
}