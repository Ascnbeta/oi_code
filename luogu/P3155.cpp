#include <bits/stdc++.h>
#define min(x,y) (x)>(y)?(y):(x)
using namespace std;
int n,m;
struct edge{
	int to,nxt;
}e[20004];
int head[10004],tot;
int c[26000];
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int f[10004][3];
void dfs(int u,int fa) {
	if (u >= 1 && u <= n) {
		f[u][c[u]] = 1;
		return;
	}
	f[u][1] = f[u][0] = 1;
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v,u);
		f[u][1] += min(f[v][1]-1,f[v][0]);
		f[u][0] += min(f[v][0]-1,f[v][1]);
	}
}
int main () {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= m - 1; i++) {
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	int ans = 0x3f3f3f3f;
	for (int i = n + 1; i <= m; i++) {
		memset(f,0x3f,sizeof(f));
		dfs(i,0);
		// cout << i << ' ';
		// // for (int i = 1; i <= m; i++) {
		// // 	cout << f[i] << ' ';
		// // }
		// cout << '\n'; 
		ans = min(ans,min(f[i][0],f[i][1]));
	}
	cout << ans << '\n';
	return 0;
}