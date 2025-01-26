#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+4;
typedef long long ll;
int n;
ll ans;
struct rectangle {
	int x1,y1,x2,y2;
}m[maxn];
int b[maxn<<1];
struct op{
	int x,tp,p;
	bool operator < (const op &a) const{
		return x < a.x;
	}
}op[maxn<<1];
struct node{
	ll sum,len;
};
struct Segment_Tree {
	node t[maxn<<3];
	inline void pushup(int p,int l,int r) {
		if (t[p].sum) t[p].len = b[r+1] - b[l];
		else if (r == l) {
			t[p].len = 0; 
		}else{
			t[p].len = t[p<<1].len + t[p<<1|1].len;
		}
	}
	void modify(int p,int v,int l,int r,int s,int e) {
		if (l <= s && e <= r) {
			t[p].sum += v;
			pushup(p,s,e);
			return; 
		}
		int mid = (s + e) >> 1;
		if (l <= mid) modify(p<<1,v,l,r,s,mid);
		if (r > mid) modify(p<<1|1,v,l,r,mid+1,e);
		pushup(p,s,e);
	}
}tree;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m[i].x1 >> m[i].y1 >> m[i].x2 >> m[i].y2;
		b[i] = m[i].y1,b[i+n] = m[i].y2;
		op[i].x = m[i].x1,op[i].tp = 1,op[i].p = i,op[i+n].x = m[i].x2,op[i+n].tp = -1,op[i+n].p = i;
	}
	sort(b+1,b+2*n+1);
	int n1 = unique(b+1,b+2*n+1)-b-1;
	for (int i = 1; i <= n; i++) {
		m[i].y1 = lower_bound(b+1,b+n1+1,m[i].y1)-b;
		m[i].y2 = lower_bound(b+1,b+n1+1,m[i].y2)-b;
	}
	sort(op+1,op+2*n+1);
	for (int i = 1; i < 2*n; i++) {
		int l = m[op[i].p].y1,r = m[op[i].p].y2;
		tree.modify(1,op[i].tp,l,r-1,1,2*n);
		ans += tree.t[1].len*(op[i+1].x-op[i].x);
	}
	cout << ans << '\n';
	return 0;
}