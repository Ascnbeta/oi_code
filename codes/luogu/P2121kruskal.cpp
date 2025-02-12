#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,K,ans;
struct edge{
	int u,v,w;
	bool operator < (const edge &y) const{
		return w > y.w;
	}
}e[200004];
int tot;
inline void add(int u,int v,int w) {
	e[++tot].v = v;
	e[tot].u = u;
	e[tot].w = w;
}
int father[100004],rk[100004],cnt;
inline int find(int x) {
	int t = x;
	while (x != father[x]) x = father[x];
	int w;
	while (t != father[t]) w = father[t],father[t] = x,t = w;
	return x;
}
inline void merge(int x,int y,int id) {
	int p = find(x),q = find(y);
	if (p == q) return;
	if (rk[p] <= rk[q]) {
		++cnt,ans += e[id].w;
		father[p] = q;
		rk[q] = max(rk[q],rk[p]+1);
	}else{
		++cnt,ans += e[id].w;
		father[q] = p;
		rk[p] = max(rk[p],rk[q]+1);
	}
}
signed main () {
	cin >> n >> m >> K;
	for (int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	sort(e+1,e+tot+1);
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= tot; i++) {
		merge(e[i].u,e[i].v,i);
		if (cnt == K) {
			cout << ans << '\n';
			return 0;
		} 
	}
	return 0;
}