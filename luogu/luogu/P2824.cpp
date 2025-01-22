#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 1e5+6;
int n,m,q;
int a[maxn];
int t[maxn<<2],tg[maxn<<2];
int op[maxn],ll[maxn],rr[maxn];
inline void pushup(int p) {
	t[p] = t[ls] + t[rs];
}
inline void pushdown(int p,int l,int r) {
	int mid = (l + r) >> 1;
	tg[ls] = tg[rs] = tg[p];
	t[ls] = (mid-l+1)*tg[p];
	t[rs] = (r-mid)*tg[p];
	tg[p] = -1;
	return;
}
void build(int x,int p,int l,int r) {
	tg[p] = -1;
	if (l == r) {
		if (a[l] >= x) t[p] = 1;
		else t[p] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(x,ls,l,mid);
	build(x,rs,mid+1,r);
	pushup(p);
}
void modify(int p,int v,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		t[p] = (e-s+1)*v;
		tg[p] = v;
		return;
	}
	int mid = (s + e) >> 1;
	if (s != e && tg[p] != -1) pushdown(p,s,e);
	if (l <= mid) modify(ls,v,l,r,s,mid);
	if (r > mid) modify(rs,v,l,r,mid+1,e);
	pushup(p); 
}
int query(int p,int l,int r,int s, int e) {
	if (l <= s && e <= r) {
		return t[p];
	}
	int mid = (s + e) >> 1;
	if (s != e && tg[p] != -1) pushdown(p,s,e);
	int ret = 0;
	if (l <= mid) ret += query(ls,l,r,s,mid);
	if (r > mid) ret += query(rs,l,r,mid+1,e);
	return ret;
}
inline bool check(int x){
	build(x,1,1,n);
	for (int i = 1; i <= m; i++) {
		int cnt = query(1,ll[i],rr[i],1,n);
		if (cnt == 0) continue;
		if (cnt == rr[i] - ll[i] + 1) {
			modify(1,1,ll[i],rr[i],1,n);
			continue;
		}
		if (op[i] == 0) {
			modify(1,1,rr[i]-cnt+1,rr[i],1,n);
			modify(1,0,ll[i],rr[i]-cnt,1,n);
		}
		if (op[i] == 1) {
			modify(1,1,ll[i],ll[i]+cnt-1,1,n);
			modify(1,0,ll[i]+cnt,rr[i],1,n);
		}
	}
	if (query(1,q,q,1,n) == 1) return true;
	else return false;
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> op[i] >> ll[i] >> rr[i];
	cin >> q;
	int l = 1,r = n,ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}