#include <bits/stdc++.h>
#define int long long
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 1e5+10;
int n,m;
int c[maxn];
struct edge{
	int to,nxt;
}e[maxn<<1];
int head[maxn],tot;
inline void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
} 
int dfn[maxn],top[maxn],f[maxn],dep[maxn],son[maxn],siz[maxn],rnk[maxn],cnt;
void dfs1(int u,int fa) {
	dep[u] = dep[fa] + 1;
	siz[u] = 1;
	son[u] = 0;
	for (int i = head[u]; i ;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		f[v] = u;
		dfs1(v,u);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs2(int u,int fa,int tp) {
	top[u] = tp;
	dfn[u] = ++cnt;
	rnk[cnt] = u;
	if (son[u] == 0) return;
	dfs2(son[u],u,tp);
	for (int i = head[u]; i ;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa || v == son[u]) continue;
		dfs2(v,u,v);
	}
}
struct node{
	int lc,rc,cnt,lz_t;
}t[maxn<<2];
node operator + (const node &x,const node &y) {
	if (x.cnt == 0) return y;
	if (y.cnt == 0) return x;
	node z = {x.lc,y.rc,x.cnt+y.cnt,0};
	if (x.rc == y.lc) --z.cnt;
	return z;
}
inline void pushup(int p) {
	t[p].cnt = t[ls].cnt + t[rs].cnt;
	if (t[rs].lc == t[ls].rc) --t[p].cnt;
	t[p].lc = t[ls].lc,t[p].rc = t[rs].rc;
}
inline void pushdown(int p) {
	t[ls].lc = t[ls].rc = t[rs].lc = t[rs].rc = t[ls].lz_t = t[rs].lz_t = t[p].lz_t;
	t[ls].cnt = t[rs].cnt = 1;
	t[p].lz_t = 0;
}
void build(int p,int s,int e) {
	if (s == e) {
		t[p].lc = t[p].rc = c[rnk[s]];
		t[p].cnt = 1;
		return;
	}
	int mid = (s + e) >> 1;
	build(ls,s,mid);
	build(rs,mid+1,e);
	pushup(p);
}
void modify(int p,int v,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		t[p].lc = t[p].rc = v;
		t[p].cnt = 1;
		t[p].lz_t = v;
		return;
	}
	int mid = (s + e) >> 1;
	if (s != e && t[p].lz_t) pushdown(p);
	if (l <= mid) modify(ls,v,l,r,s,mid);
	if (r > mid) modify(rs,v,l,r,mid+1,e);
	pushup(p);
}
node query(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		return t[p];
	}
	int mid = (s + e) >> 1;
	if (s != e && t[p].lz_t) pushdown(p);
	node ret1 = {0,0,0,0},ret2 = {0,0,0,0};
	if (l <= mid) ret1 = query(ls,l,r,s,mid);
	if (r > mid) ret2 = query(rs,l,r,mid+1,e);
	return ret1 + ret2;
}
inline void modify_path(int x,int y,int v) {
	int fx = top[x],fy = top[y];
	while (fx != fy) {
		if (dep[fx] >= dep[fy]) {
			modify(1,v,dfn[fx],dfn[x],1,n);
			x = f[fx];
			fx = top[x];
		}else{
			modify(1,v,dfn[fy],dfn[y],1,n);
			y = f[fy];
			fy = top[y];
		}
	}
	if (dep[x] >= dep[y]) {
		modify(1,v,dfn[y],dfn[x],1,n);
	}else{
		modify(1,v,dfn[x],dfn[y],1,n);
	}
}
inline int query_path(int x,int y) {
	node retx = {0,0,0,0},rety = {0,0,0,0};
	int fx = top[x],fy = top[y];
	while (fx != fy) {
		if (dep[fx] >= dep[fy]) {
			retx = query(1,dfn[fx],dfn[x],1,n) + retx;
			x = f[fx];
			fx = top[x];
		}else{
			rety = query(1,dfn[fy],dfn[y],1,n) + rety;
			y = f[fy];
			fy = top[y];
		}
	}
	node ret = {0,0,0,0};
	if (dep[x] >= dep[y]) {
		ret = query(1,dfn[y],dfn[x],1,n) + retx;
		ret.cnt += rety.cnt;
		if (ret.lc == rety.lc) --ret.cnt;
	}else{
		ret = query(1,dfn[x],dfn[y],1,n) + rety;
		ret.cnt += retx.cnt;
		if (ret.lc == retx.lc) --ret.cnt;
	}
	return ret.cnt;
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	dfs2(1,0,1);
	build(1,1,n);
	while (m--) {
		char opt;
		cin >> opt;
		if (opt == 'C') {
			int x,y,z;
			cin >> x >> y >> z;
			modify_path(x,y,z);
		}else{
			int x,y;
			cin >> x >> y;
			cout << query_path(x,y) << '\n';
		}

	}
	return 0;
}