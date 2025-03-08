#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct edge{
	int to,nxt,w;
}e[606];
int head[304],tot;
inline void add(int u,int v,int w) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	e[tot].w = w;
	head[u] = tot;
}
int f[304][304][2],tmp[304][2];
void dfs(int u,int fa) {
	f[u][1][1] = 0;
	f[u][0][0] = 0;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v,u);
		memcpy(tmp,f[u],sizeof(tmp));
		memset(f[u],0x3f,sizeof(f[u]));
		for (int j = k; j >= 0; j--) {
			for (int l = 0; l <= j; l++) {
				f[u][j][1] = min(f[v][l][1]+tmp[j-l][1]+e[i].w,min(f[u][j][1],f[v][l][0]+tmp[j-l][1]));
				f[u][j][0] = min(f[v][l][0]+tmp[j-l][0]+(m==2)*e[i].w,min(f[u][j][0],f[v][l][1]+tmp[j-l][0]));
			}
		}
	}
}
signed main () {
	cin >> n >> m >> k;
	if (n - m < k - 1) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 1; i <= n - 1; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		add(x,y,z);
		add(y,x,z);
	}
	memset(f,0x3f,sizeof(f));
	dfs(1,-1);
	cout << f[1][k][1] << '\n';
	return 0;
}