#include <bits/stdc++.h>
using namespace std;
int n;
struct edge{
	int to,nxt;
}e[200005];
int head[100005],tot;
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int ans,f[100004][2];//1 -> longest 0 -> 
void dfs(int u,int fa) {
	for (int i = head[u];i;i = e[i].nxt) {
		if (e[i].to == fa) continue;
		dfs(e[i].to,u);
		if (f[e[i].to][1]+1>f[u][1]) {
			f[u][0] = f[u][1];
			f[u][1] = f[e[i].to][1]+1;
		}else {
			f[u][0] = max(f[u][0],f[e[i].to][1]+1);
		}
	}
	ans = max(ans,f[u][0]+f[u][1]);
}
int main () {
	cin >> n;
	for (int i = 1; i <= n-1; i++) {
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	cout << ans << '\n';
	return 0;
}