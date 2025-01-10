#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 5e5 + 10 ;
int in[MAXN] ;
struct edge {
	int to, nxt ;
}e[MAXN] ;
int head[MAXN], tot, dep[MAXN], f[MAXN] ;
int siz[MAXN], son[MAXN], top[MAXN] ;
int t[MAXN * 4] ;
inline void add (int u, int v) {
	e[++tot].to = v ;
	e[tot].nxt = head[u] ;
	head[u] = tot ;
}
inline void dfs (int x, int fa) {
	siz[x] = 1 ;
	f[x] = fa ;
	for (int i = head[x] ; i ; i = e[i].nxt) {
		int v = e[i].to ;
		if (v == fa) continue ;
		dep[v] = dep[x] + 1 ;
		dfs(v, x) ;
		siz[x] += siz[v] ;
		if (siz[son[x]] < siz[v]) son[x] = v ;
	}
}
inline void redfs (int x, int t, int fa) {
	top[x] = t ;
	if (son[x]) redfs(son[x], t, x) ;
	for (int i = head[x] ; i ; i = e[i].nxt) {
		int v = e[i].to ;
		if (v == fa) continue ;
		if (v == son[x]) continue ;
		redfs(v, v, x) ;
	}
}
inline int LCA (int x, int y) {
	while (top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y) ;
		x =  f[top[x]] ;
	} 
	if (dep[x] < dep[y]) return x ;
	else return y ;
}
inline void build (int now, int l ,int r) {
	if (l == r) {
		t[now] = dep[l] ;
		return ;
	}
	int mid = (l + r) / 2 ;
	build (now * 2, l, mid) ;
	build (now * 2 + 1, mid + 1, r) ;
	t[now] = min (t[now * 2], t[now * 2 + 1]) ;
}
int main () {
	freopen("query.in","r",stdin) ;
	freopen("query.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	int n, u, v, q, l, r, k ;
	bool key = 1 ;
	cin >> n ;
	for (int i = 1 ; i <= n - 1 ; i++) {
		cin >> u >> v ;
		in[v]++ ;
		if (in[v] > 1) key = 0 ;
		add (u, v) ;
		add (v, u) ;
	}
	dep[1] = 1 ;
	dfs (1, 0) ;
	redfs (1, 1, 0) ;
//	if (key) {
//		build(1, 1, n) ;
//		cin >> q ;
//		while (q--) {
//			cin >> l >> r >> k ;
//			cout << query(l, r) << '\n' ;
//		}
//	}
	cin >> q ;
	while (q--) {
		int ans = 0 ;
		cin >> l >> r >> k ;
		for (int i = l ; i <= r - k + 1 ; i++) {
			int g = i ;
			for (int j = i + 1 ; j <= i + k - 1 ; j++) g = LCA(g, j) ;
			ans = max(ans, dep[g]) ;
		}
		cout << ans << '\n' ;
	}
}
