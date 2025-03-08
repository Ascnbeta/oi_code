#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e3+10;
int n,k;
struct edge{
	int v,w;
};
vector<edge> e[maxn];
int f[maxn][maxn],siz[maxn];
void dfs(int u,int fa) {
	siz[u] = 1;
	for (auto &v : e[u]) {
		if (v.v == fa) continue;
		dfs(v.v,u);
		siz[u] += siz[v.v];
		for (int i = k; i >= 0; i--) {
			for (int j = max(0ll,i-siz[u]+siz[v.v]); j <= min(i,siz[v.v]); j++) {
				int tot = j*(k-j)+(siz[v.v]-j)*(n-k-siz[v.v]+j);
				f[u][i] = max(f[u][i],f[u][i-j]+f[v.v][j]+tot*v.w);
			}
		}
	}
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	dfs(1,0);
	cout << f[1][k] << '\n';
	return 0;
}