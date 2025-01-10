#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 2e5+6;
int a[maxn];
double ts[maxn<<2],tc[maxn<<2],tg[maxn<<2],si,co;
int n,m;
inline void pushup(int p) {
	ts[p] = ts[ls] + ts[rs];
	tc[p] = tc[ls] + tc[rs];
}
inline void pushdown(int p) {
	tg[ls] += tg[p];
	tg[rs] += tg[p];
	double t1 = ts[ls],t2 = tc[ls];
	ts[ls] = cos(tg[p])*t1+sin(tg[p])*t2;
	tc[ls] = cos(tg[p])*t2-sin(tg[p])*t1;
	t1 = ts[rs],t2 = tc[rs];
	ts[rs] = cos(tg[p])*t1+sin(tg[p])*t2;
	tc[rs] = cos(tg[p])*t2-sin(tg[p])*t1;
	tg[p] = 0;
}
void build(int p,int l,int r) {
	if (l == r) {
		ts[p] = sin(a[l]);
		tc[p] = cos(a[l]);
		return;
	}
	int mid = (l + r) >> 1;
	if (l <= mid) build(ls,l,mid);
	if (r > mid) build(rs,mid+1,r);
	pushup(p);
}
void modify(int p,int v,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		double t1 = ts[p],t2 = tc[p];
		ts[p] = co*t1+si*t2;
		tc[p] = co*t2-si*t1;
		tg[p] += v;
		return;
	}
	int mid = (s + e) >> 1;
	if (s != e && tg[p]) pushdown(p);
	if (l <= mid) modify(ls,v,l,r,s,mid);
	if (r > mid) modify(rs,v,l,r,mid+1,e);
	pushup(p);
}
double query(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		return ts[p];
	}
	int mid = (s + e) >> 1;
	if (s != e && tg[p]) pushdown(p);
	double ret = 0;
	if (l <= mid) ret += query(ls,l,r,s,mid);
	if (r > mid) ret += query(rs,l,r,mid+1,e);
	return ret;
}
int main () {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1,1,n);
	cin >> m;
	for (int i = 1; i <= m; i ++) {
		int op,l,r;
		cin >> op >> l >> r;
		if (op == 1) {
			int v;
			cin >> v;
			si = sin(v),co = cos(v);
			modify(1,v,l,r,1,n);
		}else{
			printf("%.1f\n",query(1,l,r,1,n));
		}
	}
	return 0;
}