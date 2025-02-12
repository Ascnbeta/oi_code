#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2+4;
int n,k,ans;
int e[maxn][maxn];
bool f[maxn];
int dis[maxn];
inline void prim(int s) {
	dis[s] = 0;
	while(1) {
		int p = 0;
		for (int i = 1; i <= n; i++) {
			if(!f[i]&&(p==0||dis[i]<dis[p])) p = i;
		}
		if (dis[p] == 0x3f3f3f3f) return;
		f[p] = true;
		for (int i = 1;i <= n; i++) {
			if (!f[i]) dis[i] = min(dis[i],e[p][i]);
		}
	}
}
int main () {
	cin >> n >> k;
	memset(e,0x3f,sizeof(e));
	memset(dis,0X3f,sizeof(dis));
	for (int i = 1; i <= n; i++) e[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u][v] = e[v][u] = min(e[u][v],-w);
	}
	for (int i = 1; i <= n; i++) {
		if (!f[i]) prim(i);
	}
	for (int i = 1; i <= n; i++) {
		ans += dis[i];
	}
	cout << -ans << '\n';
	return 0;
}