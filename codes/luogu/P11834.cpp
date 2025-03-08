#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int maxn = 20;
const int maxm = 400;
const int mod = 1e9+7;
int n,m,ans;
int c,T;
int e[maxn][maxn];
int e1[maxn][maxn];
pair<int,int> edge[maxm];
int dis[maxn];
bool vis[maxn];
int ni;
int sum = 0;
inline int binpow(int base,int p) {
	int ret = 1;
	while (p) {
		if (p&1) ret = ret * base % mod;
		base = base * base % mod;
		p >>= 1;
	}
	return ret;
}
inline int prim(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s] = 0;
	for (int i = 1; i < n; i++) {
		int p = 0;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]&&(p==0||dis[p]>dis[j])) p = j;
		}
		vis[p] = true;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) dis[j] = min(dis[j],e1[p][j]);
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (dis[i] == 0x3f3f3f3f) return 0x3f3f3f3f;
		else ret += dis[i];
	}
	return ret;
}
signed main () {
	// freopen("years.in","r",stdin);
	// freopen("years.out","w",stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> m;
		
		memset(e,0x3f,sizeof(e));
		memset(e1,0x3f,sizeof(e1));
		
		for (int i = 1; i <= m; i++) {
			int u,v,w;
			cin >> u >> v >> w;
//			cout << i << '\n';
			e[u][v] = e[v][u] = e1[u][v] = e1[v][u] = w;
			edge[i] = make_pair(u,v);
		}
		ni = binpow(1<<(2*m),1e9+5);
		ans = 0;
		sum = prim(1);
		cout << sum << '\n';
		if (1 <= c && c <= 6) {
			for (int i = 0; i < (1<<(2*m)); i++) {
				memset(e1,0x3f,sizeof(e1));
				int t = i;
//				cout << t << '\n';
				for (int j = 1 ; t; j++) {
					int u = edge[j].fi,v = edge[j].se;
					int x = (t&1)|(t&2);
//					cout << x << '\n';
					if (x == 0) {
						t >>= 2;
						continue;
					}else if (x == 1) {
						e1[u][v] = e[u][v];
					}else if (x == 2) {
						e1[v][u] = e[u][v];
					}else if (x == 3) {
						e1[u][v] = e1[v][u] = e[u][v];
 					}
 					t >>= 2;
				}
//				if (i == 35) {
//					for (int i = 1; i <= n; i++) {
//						for (int j = 1; j <= n; j++) {
//							cout << e1[i][j] << ' ';
//						}
//						cout << '\n';
//					}
//					cout << prim(3) << '\n';
//					cout << dis[1] << ' ' << dis[2] << ' ' << dis[3] << '\n';
//				}
				for (int j = 1; j <= n; j++) {
					if (prim(j) == sum) {
						cout << i << ' ' << j << '\n'; 
						++ans;
						break;
					}
				}
			}
//			cout << ans << '\n';
			cout << ans % mod * ni % mod << '\n';
		}
	}
	
	return 0;
}
