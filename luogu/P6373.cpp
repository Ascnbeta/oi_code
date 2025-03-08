#include <bits/stdc++.h>
#define int long long
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 5e5+6;
int n,m;
string s;
int a[maxn],sum[maxn];
struct node{
	int ioi,io,oi,i,o;
	node() {
		ioi = io = oi = i = o = 0;
	}
	node operator + (const node &b) const{
		node c;
		c.o = o + b.o;
		c.i = i + b.i;
		c.oi = oi + b.oi + o * b.i;
		c.io = io + b.io + i * b.o;
		c.ioi = ioi + b.ioi + io * b.i + i * b.oi;
		return c;
	}
}t[maxn<<2];
inline void pushup(int p) {
	t[p].o = t[ls].o + t[rs].o;
	t[p].i = t[ls].i + t[rs].i;
	t[p].oi = t[ls].oi + t[rs].oi + t[ls].o * t[rs].i;
	t[p].io = t[ls].io + t[rs].io + t[ls].i * t[rs].o;
	t[p].ioi = t[ls].ioi + t[rs].ioi + t[ls].io * t[rs].i + t[ls].i * t[rs].oi;
}
void build(int p,int l,int r) {
	if (l == r) {
		if (s[l] == 'O') {
			t[p].o = 1;
		}else{
			t[p].i = 1;
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(p);
} 
void modify(int p,int pos,char v,int s,int e) {
	if (s == e) {
		if (v == 'O') {
			t[p].o = 1,t[p].i = 0;
		}else{
			t[p].i = 1,t[p].o = 0;
		}
		return;
	}
	int mid = (s + e) >> 1;
	if (pos <= mid) modify(ls,pos,v,s,mid);
	else if (pos > mid) modify(rs,pos,v,mid+1,e);
	pushup(p);
}
node query(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		return t[p];
	}
	int mid = (s + e) >> 1;
	node t1,t2;
	if (l <= mid) t1 = query(ls,l,r,s,mid);
	if (r > mid) t2 = query(rs,l,r,mid+1,e);
	return t1+t2;
}
signed main () {
	cin >> n >> m >> s;
	s = ' ' + s;
	build(1,1,n);
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x;char ch;
			cin >> x >> ch;
			modify(1,x,ch,1,n);
		}else{
			int l,r;
			cin >> l >> r;
			cout << query(1,l,r,1,n).ioi << '\n';
		}
	}
	return 0;
}