#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 4e5+6;
struct edge{
	int to,nxt;
}e[maxn<<1];
int head[maxn],tot;
inline void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int n,m,cnt;
int c[maxn];
int f[maxn],l[maxn],pos[maxn];
void dfs(int p,int fa) {
	pos[++cnt] = p;
	f[p] = cnt;
	for (int i = head[p]; i; i = e[i].nxt) {
		if (e[i].to == fa) continue;
		dfs(e[i].to,p);
	}
	l[p] = cnt;
}
struct node{
	int v,tag;
}t[maxn<<2];
inline void pushup(int p) {
	t[p].v = t[p<<1].v | t[p<<1|1].v;
}
inline void pushdown(int p) {
	t[p<<1].tag = t[p<<1|1].tag = t[p].tag;
	t[p<<1].v = 1ll<<(t[p].tag);
	t[p<<1|1].v = 1ll<<(t[p].tag);
	t[p].tag = -1;
}
void build(int p,int l,int r) {
	t[p].tag = -1;
	if (l == r) {
		t[p].v = 1ll<<(c[pos[l]]);
		return;
	}
	int mid = (l + r) >> 1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
void modify(int p,int v,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		t[p].v = 1ll<<v;
		t[p].tag = v;
		return;
	}
	int mid = (s + e) >> 1;
	if (s != e && t[p].tag != -1) pushdown(p);
	if (l <= mid) modify(p<<1,v,l,r,s,mid);
	if (r > mid) modify(p<<1|1,v,l,r,mid+1,e);
	pushup(p);
}
int query(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		return t[p].v;
	}
	int mid = (s + e) >> 1;
	if (s != e && t[p].tag != -1) pushdown(p);
	int ret = 0;
	if (l <= mid) ret |= query(p<<1,l,r,s,mid);
	if (r > mid ) ret |= query(p<<1|1,l,r,mid+1,e);
	return ret; 
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	build(1,1,n);
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int u,co;
			cin >> u >> co;
			modify(1,co,f[u],l[u],1,n);
		}else{
			int u;
			cin >> u;
			cout << __builtin_popcountll(query(1,f[u],l[u],1,n)) << '\n';
		}
	}
	return 0;
}