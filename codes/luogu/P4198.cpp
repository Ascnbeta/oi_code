#include <bits/stdc++.h>
#define ls (p<<1)
#define rs (p<<1|1)
using namespace std;
const int maxn = 1e5+10;
int n,m;
struct node{
	double max;
	int cnt;
}t[maxn<<2];
inline int count(int p,int l,int r,double v) {
	if (t[p].max <= v) return 0;
	if (l == r) return t[p].max > v;
	int mid = (l + r) >> 1;
	if (t[ls].max <= v) {
		return count(rs,mid+1,r,v);
	}
	return count(ls,l,mid,v)+t[p].cnt-t[ls].cnt;
}
inline void pushup(int p,int l,int r) {
	int mid = (l + r) >> 1;
	t[p].max = max(t[ls].max,t[rs].max);
	t[p].cnt = t[ls].cnt + count(rs,mid+1,r,t[ls].max);
}
void modify(int p,int pos,double v,int s,int e) {
	if (s == e && s == pos) {
		//cout << t[p].v << '\n';
		t[p].max = v;
		t[p].cnt = 1;
		return;
	}
	int mid = (s + e) >> 1;
	if (pos <= mid) modify(ls,pos,v,s,mid);
	if (pos > mid) modify(rs,pos,v,mid+1,e);
	pushup(p,s,e); 
}
int main () {
	cin >> n >> m;
	while (m--) {
		int x,y;
		cin >> x >> y;
		modify(1,x,1.0*y/x,1,n);
		cout << t[1].cnt << '\n';
	}
	return 0;
}