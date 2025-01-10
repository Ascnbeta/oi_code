#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
int n,m;
int a[maxn];
struct tree{
	int v,max1,max0,l0,l1,r0,r1;
	int t0,t1,tr;
}t[maxn<<2];
struct node{
	int m,l1,r1;
};
inline void pushup(int p,int l,int r) {
	int mid = (l + r) >> 1;
	t[p].v = t[p<<1].v + t[p<<1|1].v;
	t[p].l0 = t[p<<1].l0;
	if (t[p<<1].l0 == mid - l + 1) t[p].l0 += t[p<<1|1].l0;
	t[p].l1 = t[p<<1].l1;
	if (t[p<<1].l1 == mid - l + 1) t[p].l1 += t[p<<1|1].l1;
	t[p].r0 = t[p<<1|1].r0;
	if (t[p<<1|1].r0 == r - mid) t[p].r0 += t[p<<1].r0;
	t[p].r1 = t[p<<1|1].r1;
	if (t[p<<1|1].r1 == r - mid) t[p].r1 += t[p<<1].r1;
	t[p].max1 = max(t[p<<1].r1+t[p<<1|1].l1,max(t[p<<1].max1,t[p<<1|1].max1));
	t[p].max0 = max(t[p<<1].r0+t[p<<1|1].l0,max(t[p<<1].max0,t[p<<1|1].max0));
}
inline void pushdown(int p,int l,int r) {
	int mid = (l + r) >> 1;
	if (t[p].t0 == 1) {
		t[p<<1].v = t[p<<1|1].v = 0;
		t[p<<1].max1 = t[p<<1|1].max1 = 0;
		t[p<<1].max0 = mid - l + 1;
		t[p<<1|1].max0 = r - mid;
		t[p<<1].l1 = t[p<<1|1].l1 = 0;
		t[p<<1].r1 = t[p<<1|1].r1 = 0;
		t[p<<1].l0 = mid - l + 1;
		t[p<<1].r0 = mid - l + 1;
		t[p<<1|1].l0 = r - mid;
		t[p<<1|1].r0 = r - mid;
		t[p<<1].t0 = t[p<<1|1].t0 = 1;
		t[p<<1].t1 = t[p<<1|1].t1 = 0;
		t[p<<1].tr = t[p<<1|1].tr = 0;
	}else if (t[p].t1 == 1) {
		t[p<<1].v = mid - l + 1;
		t[p<<1|1].v = r - mid;
		t[p<<1].max0 = t[p<<1|1].max0 = 0;
		t[p<<1].max1 = mid - l + 1;
		t[p<<1|1].max1 = r - mid;
		t[p<<1].l0 = t[p<<1|1].l0 = 0;
		t[p<<1].r0 = t[p<<1|1].r0 = 0;
		t[p<<1].l1 = mid - l + 1;
		t[p<<1].r1 = mid - l + 1;
		t[p<<1|1].l1 = r - mid;
		t[p<<1|1].r1 = r - mid;
		t[p<<1].t0 = t[p<<1|1].t0 = 0;
		t[p<<1].t1 = t[p<<1|1].t1 = 1;
		t[p<<1].tr = t[p<<1|1].tr = 0;
	}
	if (t[p].tr == 1) {
		t[p<<1].v = mid - l + 1 - t[p<<1].v;
		t[p<<1|1].v  = r - mid - t[p<<1|1].v;
		swap(t[p<<1].max1,t[p<<1].max0);swap(t[p<<1|1].max1,t[p<<1|1].max0);
		swap(t[p<<1].l1,t[p<<1].l0);swap(t[p<<1|1].l1,t[p<<1|1].l0);
		swap(t[p<<1].r1,t[p<<1].r0);swap(t[p<<1|1].r1,t[p<<1|1].r0);
		t[p<<1].tr = (t[p<<1].tr + 1) % 2;
		t[p<<1|1].tr = (t[p<<1|1].tr + 1) % 2;
	}
	t[p].tr = t[p].t0 = t[p].t1 = 0;
}
inline void build(int p,int l,int r) {
	if (l == r) {
		t[p].v = a[l];
		if (a[l] == 1) {
			t[p].l1 = t[p].r1 = 1;
			t[p].max1 = 1;
		}else if(a[l] == 0) {
			t[p].l0 = t[p].r0 = 1;
			t[p].max0 = 1;
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p,l,r);
}
inline void modify(int p,int l,int r,int v,int s,int e) {
	if (l <= s && e <= r) { 
		if (v == 0) {
			t[p].v = 0;
			t[p].max0 = e - s + 1;
			t[p].max1 = 0;
			t[p].l1 = 0;
			t[p].r1 = 0;
			t[p].l0 = e - s + 1;
			t[p].r0 = e - s + 1;
			t[p].t0 = 1;
			t[p].t1 = 0;
			t[p].tr = 0;
		}else if (v == 1) {
			t[p].v = e - s + 1;
			t[p].max1 = e - s + 1;
			t[p].max0 = 0;
			t[p].l0 = 0;
			t[p].r0 = 0;
			t[p].l1 = e - s + 1;
			t[p].r1 = e - s + 1;
			t[p].t1 = 1;
			t[p].t0 = 0;
			t[p].tr = 0;
		}else {
			t[p].v = e - s + 1 - t[p].v;
			swap(t[p].max1,t[p].max0);
			swap(t[p].l0,t[p].l1);
			swap(t[p].r0,t[p].r1);
			t[p].tr = (t[p].tr + 1) % 2;
		}
		return;
	}
	int mid = (s + e) >> 1;
	if (s != e && (t[p].t0 || t[p].t1 || t[p].tr)) pushdown(p,s,e);
	if (l <= mid) modify(p<<1,l,r,v,s,mid);
	if (r > mid) modify(p<<1|1,l,r,v,mid+1,e);
	pushup(p,s,e);
}
inline int query1(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		return t[p].v;
	}
	int mid = (s + e) >> 1;
	if (s != e && (t[p].t0 || t[p].t1 || t[p].tr)) pushdown(p,s,e);
	int ret = 0;
	if (l <= mid) ret += query1(p<<1,l,r,s,mid);
	if (r > mid) ret += query1(p<<1|1,l,r,mid+1,e);
	return ret;
}
inline node query2(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		return (node){t[p].max1,t[p].l1,t[p].r1};
	}
	int mid = (s + e) >> 1;
	if (s != e && (t[p].t0 || t[p].t1 || t[p].tr)) pushdown(p,s,e);
	node ret1,ret2,ret;
	if (l <= mid && r > mid) {
		ret1 = query2(p<<1,l,r,s,mid);
		ret2 = query2(p<<1|1,l,r,mid+1,e);
		ret.m = 0;
		ret.m = max(ret1.r1+ret2.l1,max(ret1.m,ret2.m));
		ret.l1 = ret1.l1;
		if (ret1.l1 == mid - s + 1) ret.l1 += ret2.l1;
		ret.r1 = ret2.r1;
		if (ret2.r1 == e - mid) ret.r1 += ret1.r1;
		return ret;
	}
	if (r > mid) {
		ret2 = query2(p<<1|1,l,r,mid+1,e);
		ret.m = 0;
		ret.m = ret2.m;
		ret.l1 = ret2.l1;
		ret.r1 = ret2.r1;
		return ret;
	}
	if (l <= mid) {
		ret1 = query2(p<<1,l,r,s,mid);
		ret.m = 0;
		ret.m = ret1.m;
		ret.l1 = ret1.l1;
		ret.r1 = ret1.r1;
		return ret;
	}
//	ret.m = 0;
//	ret.m = max(ret1.r1+ret2.l1,max(ret1.m,ret2.m));
//	ret.l1 = ret1.l1;
//	if (ret1.l1 == mid - s + 1) ret.l1 += ret2.l1;
//	ret.r1 = ret2.r1;
//	if (ret2.r1 == e - mid) ret.r1 += ret1.r1;
	
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	while (m--) {
		int op,l,r;
		cin >> op >> l >> r;
		++l,++r;
		switch(op) {
			case 0:{
				modify(1,l,r,0,1,n);
				break;
			}
			case 1:{
				modify(1,l,r,1,1,n);
				break;
			}
			case 2:{
				modify(1,l,r,2,1,n);
				break;
			}
			case 3:{
				cout << query1(1,l,r,1,n) << '\n';
				break;
			}
			case 4:{
				cout << query2(1,l,r,1,n).m << '\n';
				break;
			}
		}
	}
	return 0;
}