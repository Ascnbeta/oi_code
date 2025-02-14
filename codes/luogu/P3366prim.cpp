<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+3;
const int maxm = 2e5+3;
int n,m,ans;
int e[maxn][maxn];
int dis[maxn];
bool vis[maxn];
inline void prim() {
	memset(dis,0x3f,sizeof(dis));
	dis[1] = 0;
	for (int i = 1; i < n; i++) {
		int p = 0;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]&&(p==0||dis[j]<dis[p])) p = j;
		}
		vis[p] = true;
		for (int j = 1; j <= n; j++) {
			if(!vis[j]) dis[j] = min(dis[j],e[p][j]);
		}
	}
}
int main () {
	cin >> n >> m;
	memset(e,0x3f,sizeof(e));
	for (int i = 1; i <= n; i++) e[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u][v] = e[v][u] = w;
	} 
	prim();
	for (int i = 1; i <= n; i++) {
		if (dis[i] == 0x3f3f3f3f) {
			puts("orz");
			return 0;
		}else{
			ans += dis[i];
		}
	}
	cout << ans << '\n';
	return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+3;
const int maxm = 2e5+3;
int n,m,ans;
int e[maxn][maxn];
int dis[maxn];
bool vis[maxn];
inline void prim() {
	memset(dis,0x3f,sizeof(dis));
	dis[1] = 0;
	for (int i = 1; i < n; i++) {
		int p = 0;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]&&(p==0||dis[j]<dis[p])) p = j;
		}
		vis[p] = true;
		for (int j = 1; j <= n; j++) {
			if(!vis[j]) dis[j] = min(dis[j],e[p][j]);
		}
	}
}
int main () {
	cin >> n >> m;
	memset(e,0x3f,sizeof(e));
	for (int i = 1; i <= n; i++) e[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u][v] = e[v][u] = w;
	} 
	prim();
	for (int i = 1; i <= n; i++) {
		if (dis[i] == 0x3f3f3f3f) {
			puts("orz");
			return 0;
		}else{
			ans += dis[i];
		}
	}
	cout << ans << '\n';
	return 0;
}
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
