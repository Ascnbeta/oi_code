#include <bits/stdc++.h>
using namespace std;
int T;
int n,q;
struct edge{
	int to,nxt,w;
}e[2003],eq[2003];
int head[1003],tot,headq[1003],totq,ans[1003];
bool f[1003];
inline void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
inline void addq(int u,int v,int w) {
	eq[++totq].to = v;
	eq[totq].nxt = headq[u];
	eq[totq].w = w;
	headq[u] = totq;
}
int father[1003];
inline int find(int x){
	int t = x;
	if (father[x] == x) return x;
	while(father[x] != x) x = father[x];
	while(father[t] != t) {
		int w = father[t];
		father[t] = x;
		t = w;
	}
	return x;
}
void tarjan(int u,int fa) {
	f[u] = true;
	for (int i = head[u];i ;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa && f[v]) continue;
		tarjan(v,u);
		father[v] = u; 
	}
	for (int i = headq[u];i ;i = eq[i].nxt) {
		int v = eq[i].to,w = eq[i].w;
		if (ans[w]) continue;
		if (!f[v]) continue;
		ans[w] = find(v);
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> T;
	for (int t = 1;t <= T; t++) {
		cin >> n;
		tot = totq = 0;
		for (int i = 1; i <= n; i++) {
			head[i] = headq[i] = 0;
			father[i] = i;
			f[i] = false;
		}
		for (int i = 1; i <= n; i++) {
			int m;
			cin >> m;
			for (int j = 1; j <= m; j++) {
				int x;
				cin >> x;
				add(i,x);
				add(x,i);
			}
		}
		cin >> q;
		for (int i = 1; i <= q; i++) {
			int u,v;
			cin >> u >> v;
			addq(u,v,i);
			addq(v,u,i);
			ans[i] = 0;
		}
		tarjan(1,-1);
		// cout << "Case " << t << ":" << '\n';
		for (int i = 1; i <= q; i++) {
			cout << ans[i] << '\n';
		}
	}
	return 0;
}