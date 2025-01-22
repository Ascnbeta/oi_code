#include <bits/stdc++.h>
using namespace std;
int n,m,q;
struct edge{
	int to,nxt,w;
}e[100004];
int head[10003],tot;
struct edg{
	int u,v,w;
}eg[100004];
int totg;
inline void addg(int u,int v,int w) {
	eg[++totg].u = u;
	eg[totg].v = v;
	eg[totg].w = w;
}
inline void add(int u,int v,int w) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	e[tot].w = w;
	head[u] = tot;
}
bool cmp(edg x,edg y) {
	return x.w > y.w;
}
int father[10004];
inline int find(int x) {
	int t = x;
	while (father[x] != x) x = father[x];
	while (father[t] != t) {
		int w = father[t];
		father[t] = x;
		t = w;
	}
	return x;
}
inline void merge(int x,int y) {
	while(father[x] != x) x = father[x];
	while(father[y] != y) y = father[y];
	father[x] = y;
}
inline void kruskal() {
	for (int i = 1; i <= n; i++) father[i] = i;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int t1 = find(eg[i].u),t2 = find(eg[i].v);
		if (t1 == t2) continue;
		else{
			add(eg[i].u,eg[i].v,eg[i].w);
			add(eg[i].v,eg[i].u,eg[i].w);
			merge(t1,t2);
		}
	}
}
int d[10004],f[10004][30],w[10004][30];
void dfs(int u,int fa) {
	d[u] = d[fa] + 1;
	for (int i = head[u];i ;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v,fa);
		f[v][0] = u;
		w[v][0] = e[i].w;
	}
}
inline int lca(int x,int y) {
	if (find(x) != find(y)) {
		return -1;
	}
	int ans = 0x3f3f3f3f;
	if (d[x] > d[y]) swap(x,y);
	for (int j = 15; j >= 0 && d[x] != d[y]; j--) {
		if (d[f[y][j]] == 0) continue;
		else {
			ans = min(ans,w[y][j]);
			y = f[y][j];
		} 
	}
	if (x == y) {
		return ans;
	}
	for (int j = 15; j >= 0; j--) {
		if (f[x][j] != f[y][j]) {
			ans = min(ans,min(w[x][j],w[y][j]));
			x = f[x][j],y = f[y][j];
		}
	}
	ans = min(ans,min(w[x][0],w[x][0]));
	return ans;
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		addg(x,y,z);
	}
	sort(eg+1,eg+m+1,cmp);
	kruskal();
	dfs(1,0);
	for (int i = 1; (1<<i) <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][j-1]][j-1];
			w[j][i] = min(w[j][i-1],w[w[j][i-1]][i-1]);
		}
	}
	cin >> q;
	while (q--) {
		int x,y;
		cin >> x >> y;
		cout << lca(x,y) << '\n';
		//puts("1");
	}
	return 0;
}