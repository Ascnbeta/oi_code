#include <bits/stdc++.h>
using namespace std;
int n;
struct edge{
	int to,nxt;
}e[3004];
int head[1504],tot;
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int f[1504][3],w[1504];
void dfs(int u,int fa) {
	f[u][0] = w[u];
	f[u][2] = 0;
	int sum = 0;
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v,u);
		f[u][0] += min(f[v][0],min(f[v][1],f[v][2]));
		sum += min(f[v][0],f[v][1]);
		f[u][2] += min(f[v][0],f[v][1]);
	}
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		if (f[v][0] < f[v][1]) f[u][1] = min(f[u][1],sum);
		else f[u][1] = min(f[u][1],sum-f[v][1]+f[v][0]);
	}
}
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num,k,m;
		cin >> num >> k >> m;
		w[num] = k;
		for (int j = 1; j <= m; j++) {
			int x;
			cin >> x;
			add(num,x);
			add(x,num);
		}
	}
	memset(f,0x3f,sizeof(f));
	dfs(1,0);
	cout << min(f[1][0],f[1][1]) << '\n';
	return 0;
}