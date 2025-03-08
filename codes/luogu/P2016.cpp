#include <bits/stdc++.h>
using namespace std;
int n;
struct edge{
	int to,nxt;
}e[3005];
int head[1504],tot;
int f[1504][2];
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot; 
}
void dfs(int u,int fa) {
	f[u][1] = 1;
	for (int i = head[u];i;i = e[i].nxt) {
		if (e[i].to == fa) continue;
		int v = e[i].to;
		dfs(v,u);
		f[u][1] += min(f[v][0],f[v][1]);
		f[u][0] += f[v][1];
	}
}
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int id,k;
		cin >> id >> k;
		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			add(id+1,x+1);
			add(x+1,id+1);
		}
	}
	dfs(1,0);
	cout << min(f[1][0],f[1][1]) << '\n';
	return 0;
}