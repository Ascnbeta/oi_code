<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const int maxz = 1e5;
int n,m;
vector<int> e[maxn];
struct node{
	int max,ls,rs,id;
};
struct Segment_tree{
	int rt[maxn],tot = 0;
	node t[(int)(1e7)];
	inline void pushup(int p) {
		if (t[t[p].ls].max >= t[t[p].rs].max) {
			t[p].max = t[t[p].ls].max;
			t[p].id = t[t[p].ls].id;
		}else{
			t[p].max = t[t[p].rs].max;
			t[p].id = t[t[p].rs].id;
		}
	}
	void modify(int &p,int pos,int v,int l,int r) {
		if (!p)  p = ++tot;
		if (l == r) {
			t[p].max += v;
			t[p].id = pos;
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) modify(t[p].ls,pos,v,l,mid);
		if (pos > mid) modify(t[p].rs,pos,v,mid+1,r);
		pushup(p);
	}
	int merge(int p1,int p2,int l,int r) {
		if (!p1) return p2;
		if (!p2) return p1;
		if (l == r) {
			t[p1].max += t[p2].max;
			return p1;
		}
		int mid = (l + r) >> 1;
		t[p1].ls = merge(t[p1].ls,t[p2].ls,l,mid);
		t[p1].rs = merge(t[p1].rs,t[p2].rs,mid+1,r);
		pushup(p1);
		return p1;
	}
}tr;
int dep[maxn],f[maxn][30];
void dfs(int u,int fa) {
	dep[u] = dep[fa] + 1;
	for (auto &v : e[u]) {
		if (v == fa) continue;
		dfs(v,u);
		f[v][0] = u;
	}
}
inline void pre() {
	int k = __lg(n);
	for (int i = 1; (1 << i) <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i-1]][i-1];
		}
	}
}
inline int lca(int x,int y) {
	if (dep[x] > dep[y]) swap(x,y);
	int k = __lg(dep[y])+1;
	if (dep[y] > dep[x]) {
		for (int i = k; i >= 0; i--) {
			if (f[y][i] != 0 && dep[f[y][i]] >= dep[x]) y = f[y][i];
		}
	}
	if (x == y) return x;
	for (int i = k; i >= 0; i--) {
		if (f[x][i] != 0 && f[y][i] != 0 && f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];
	}
	return f[x][0];
}
int ans[maxn];
void solve(int u,int fa) {
	for (auto &v : e[u]) {
		if (v == fa) continue;
		solve(v,u);
		tr.rt[u] = tr.merge(tr.rt[u],tr.rt[v],1,maxz);
	}
	ans[u] = tr.t[tr.rt[u]].id;
	if (tr.t[tr.rt[u]].max == 0) ans[u] = 0;
}
int main () {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	pre();
	// cout << "debug: " << lca(3,4) << '\n';
	for (int i = 1; i <= m; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		int lc = lca(x,y);
		tr.modify(tr.rt[x],z,1,1,maxz);
		tr.modify(tr.rt[y],z,1,1,maxz);
		tr.modify(tr.rt[lc],z,-1,1,maxz);
		if (f[lc][0] != 0) tr.modify(tr.rt[f[lc][0]],z,-1,1,maxz);
	}
	solve(1,0);
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const int maxz = 1e5;
int n,m;
vector<int> e[maxn];
struct node{
	int max,ls,rs,id;
};
struct Segment_tree{
	int rt[maxn],tot = 0;
	node t[(int)(1e7)];
	inline void pushup(int p) {
		if (t[t[p].ls].max >= t[t[p].rs].max) {
			t[p].max = t[t[p].ls].max;
			t[p].id = t[t[p].ls].id;
		}else{
			t[p].max = t[t[p].rs].max;
			t[p].id = t[t[p].rs].id;
		}
	}
	void modify(int &p,int pos,int v,int l,int r) {
		if (!p)  p = ++tot;
		if (l == r) {
			t[p].max += v;
			t[p].id = pos;
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) modify(t[p].ls,pos,v,l,mid);
		if (pos > mid) modify(t[p].rs,pos,v,mid+1,r);
		pushup(p);
	}
	int merge(int p1,int p2,int l,int r) {
		if (!p1) return p2;
		if (!p2) return p1;
		if (l == r) {
			t[p1].max += t[p2].max;
			return p1;
		}
		int mid = (l + r) >> 1;
		t[p1].ls = merge(t[p1].ls,t[p2].ls,l,mid);
		t[p1].rs = merge(t[p1].rs,t[p2].rs,mid+1,r);
		pushup(p1);
		return p1;
	}
}tr;
int dep[maxn],f[maxn][30];
void dfs(int u,int fa) {
	dep[u] = dep[fa] + 1;
	for (auto &v : e[u]) {
		if (v == fa) continue;
		dfs(v,u);
		f[v][0] = u;
	}
}
inline void pre() {
	int k = __lg(n);
	for (int i = 1; (1 << i) <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i-1]][i-1];
		}
	}
}
inline int lca(int x,int y) {
	if (dep[x] > dep[y]) swap(x,y);
	int k = __lg(dep[y])+1;
	if (dep[y] > dep[x]) {
		for (int i = k; i >= 0; i--) {
			if (f[y][i] != 0 && dep[f[y][i]] >= dep[x]) y = f[y][i];
		}
	}
	if (x == y) return x;
	for (int i = k; i >= 0; i--) {
		if (f[x][i] != 0 && f[y][i] != 0 && f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];
	}
	return f[x][0];
}
int ans[maxn];
void solve(int u,int fa) {
	for (auto &v : e[u]) {
		if (v == fa) continue;
		solve(v,u);
		tr.rt[u] = tr.merge(tr.rt[u],tr.rt[v],1,maxz);
	}
	ans[u] = tr.t[tr.rt[u]].id;
	if (tr.t[tr.rt[u]].max == 0) ans[u] = 0;
}
int main () {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	pre();
	// cout << "debug: " << lca(3,4) << '\n';
	for (int i = 1; i <= m; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		int lc = lca(x,y);
		tr.modify(tr.rt[x],z,1,1,maxz);
		tr.modify(tr.rt[y],z,1,1,maxz);
		tr.modify(tr.rt[lc],z,-1,1,maxz);
		if (f[lc][0] != 0) tr.modify(tr.rt[f[lc][0]],z,-1,1,maxz);
	}
	solve(1,0);
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}