#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2+10;
int n,k,sum,ans;
int e[maxn][maxn];
bool vis[maxn];
int dis[maxn];
inline void prim() {
	memset(dis,0x3f,sizeof(dis));
	dis[1] = 0;
	for (int i = 1 ; i < n; i++) {
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
		ans += dis[i];
	}
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> k;
	memset(e,0x3f,sizeof(e));
	for (int i = 1; i <= k; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		if (w != 0) {
			e[u][v] = e[v][u] = min(e[u][v],w);
		}
		sum += w;
	}
	prim();
	cout << sum - ans << '\n';
	return 0;
}