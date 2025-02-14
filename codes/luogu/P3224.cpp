<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const int maxl = 3e6+10;
int n,m,Q;
int P[maxn];
int father[maxn];
inline int find(int x) {
	int t = x;
	while (x != father[x]) x = father[x];
	int w;
	while (t != father[t]) w = father[t],father[t] = x,t = w;
	return father[x];
}
int t[maxl],ls[maxl],rs[maxl];
int rt[maxn],tot;
inline void pushup(int p) {
	t[p] = t[ls[p]] + t[rs[p]];
} 
void modify(int &p,int pos,int v,int l,int r) {
	if (!p) p = ++tot;
	if (l == r) {
		t[p] += v;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) modify(ls[p],pos,v,l,mid);
	if (pos > mid) modify(rs[p],pos,v,mid+1,r);
	pushup(p);
}
int query(int p,int l,int r,int s,int e) {
	if (!p) return 0;
	if (l <= s && e <= r) {
		return t[p];
	}
	int mid = (s + e) >> 1;
	int ret = 0;
	if (l <= mid)  ret += query(ls[p],l,r,s,mid);
	if (r > mid) ret += query(rs[p],l,r,mid+1,e);
	return ret;
}
int merge(int p1,int p2,int l,int r) {
	if (!p1) return p2;
	if (!p2) return p1;
	if (l == r) {
		t[p1] = max(t[p1],t[p2]);
		return p1;
	}
	int mid = (l + r) >> 1;
	ls[p1] = merge(ls[p1],ls[p2],l,mid);
	rs[p1] = merge(rs[p1],rs[p2],mid+1,r);
	pushup(p1);
	return p1;
}
inline void Union(int x,int y) {
	int p = find(x),q = find(y);
	if (p == q) return;
	father[q] = p;
	rt[p] = merge(rt[p],rt[q],1,n);
}
int kth(int p,int k,int l,int r) {
	if (!p || k > t[p]) return -1;
	if (l == r) {
		return l;
	}
	int mid = (l + r) >> 1;
	if (k <= t[ls[p]]) return kth(ls[p],k,l,mid);
	else return kth(rs[p],k-t[ls[p]],mid+1,r);
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= n; i++ ) {
		int t;
		cin >> t;
		P[t] = i;
 		modify(rt[i],t,1,1,n);
	}
	// cout << "debug: ";
	// for (int i = 1; i <= n; i++) {
	// 	cout << query(rt[i],1,n,1,n) << ' ';
	// }	
	// cout << '\n';
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		// if (find(u) == find(v)) continue;
		Union(u,v);
	}
	// cout << "debug: ";
	// for (int i = 1; i <= n; i++) {
	// 	cout << t[rt[i]] << ' ';
	// }	
	// cout << '\n';
	cin >> Q;
	while (Q--) {
		char opt;int x,y;
		cin >> opt >> x >> y;
		if (opt == 'B') {
			Union(x,y);
		}else{
			int t = find(x);
			int w = kth(rt[t],y,1,n);
			if (w == -1) cout << -1 << '\n';
			else cout << P[w] << '\n';
		}
	}
	// cout << "debug: ";
	// for (int i = 1; i <= n; i++) {
	// 	cout << query(rt[find(i)],1,n,1,n) << ' ';
	// }	
	// cout << '\n';
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const int maxl = 3e6+10;
int n,m,Q;
int P[maxn];
int father[maxn];
inline int find(int x) {
	int t = x;
	while (x != father[x]) x = father[x];
	int w;
	while (t != father[t]) w = father[t],father[t] = x,t = w;
	return father[x];
}
int t[maxl],ls[maxl],rs[maxl];
int rt[maxn],tot;
inline void pushup(int p) {
	t[p] = t[ls[p]] + t[rs[p]];
} 
void modify(int &p,int pos,int v,int l,int r) {
	if (!p) p = ++tot;
	if (l == r) {
		t[p] += v;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) modify(ls[p],pos,v,l,mid);
	if (pos > mid) modify(rs[p],pos,v,mid+1,r);
	pushup(p);
}
int query(int p,int l,int r,int s,int e) {
	if (!p) return 0;
	if (l <= s && e <= r) {
		return t[p];
	}
	int mid = (s + e) >> 1;
	int ret = 0;
	if (l <= mid)  ret += query(ls[p],l,r,s,mid);
	if (r > mid) ret += query(rs[p],l,r,mid+1,e);
	return ret;
}
int merge(int p1,int p2,int l,int r) {
	if (!p1) return p2;
	if (!p2) return p1;
	if (l == r) {
		t[p1] = max(t[p1],t[p2]);
		return p1;
	}
	int mid = (l + r) >> 1;
	ls[p1] = merge(ls[p1],ls[p2],l,mid);
	rs[p1] = merge(rs[p1],rs[p2],mid+1,r);
	pushup(p1);
	return p1;
}
inline void Union(int x,int y) {
	int p = find(x),q = find(y);
	if (p == q) return;
	father[q] = p;
	rt[p] = merge(rt[p],rt[q],1,n);
}
int kth(int p,int k,int l,int r) {
	if (!p || k > t[p]) return -1;
	if (l == r) {
		return l;
	}
	int mid = (l + r) >> 1;
	if (k <= t[ls[p]]) return kth(ls[p],k,l,mid);
	else return kth(rs[p],k-t[ls[p]],mid+1,r);
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= n; i++ ) {
		int t;
		cin >> t;
		P[t] = i;
 		modify(rt[i],t,1,1,n);
	}
	// cout << "debug: ";
	// for (int i = 1; i <= n; i++) {
	// 	cout << query(rt[i],1,n,1,n) << ' ';
	// }	
	// cout << '\n';
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		// if (find(u) == find(v)) continue;
		Union(u,v);
	}
	// cout << "debug: ";
	// for (int i = 1; i <= n; i++) {
	// 	cout << t[rt[i]] << ' ';
	// }	
	// cout << '\n';
	cin >> Q;
	while (Q--) {
		char opt;int x,y;
		cin >> opt >> x >> y;
		if (opt == 'B') {
			Union(x,y);
		}else{
			int t = find(x);
			int w = kth(rt[t],y,1,n);
			if (w == -1) cout << -1 << '\n';
			else cout << P[w] << '\n';
		}
	}
	// cout << "debug: ";
	// for (int i = 1; i <= n; i++) {
	// 	cout << query(rt[find(i)],1,n,1,n) << ' ';
	// }	
	// cout << '\n';
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}