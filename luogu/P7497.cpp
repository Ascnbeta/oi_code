#include <bits/stdc++.h>
#define int long long
#define ls (p<<1)
#define rs (p<<1|1)
using namespace std;
const int maxn = 2e5+6;
const int mod = 1e9+7;
int n,m;
struct node{
	int up,lp,lc,cnt;//up 区间未被封锁的数字的和，p 区间被封锁的数字的和，lc 区间被封锁的数字个数，cnt 区间被封锁次数。
	int tagt,tagp;
	node(){
		up = lp = lc = cnt = tagp = 0;
		tagt = 1;
	}
}t[maxn<<2];
int a[maxn];
inline void pushup(int p) {
	if (t[p].cnt == 0) {
		t[p].up = (t[ls].up % mod + t[rs].up % mod) % mod;
		t[p].lp = (t[ls].lp % mod + t[rs].lp % mod) % mod;
		t[p].lc = t[ls].lc + t[rs].lc;
	}
	
}
inline void pushdown(int p,int l,int r) {
	if (l == r) return;
	if (t[p].tagp == 0 && t[p].tagt == 1) return;
	if (t[p].cnt > 0) return;
	int mid = (l + r) >> 1;
	if (t[ls].cnt == 0) {
		t[ls].tagt = t[p].tagt*t[ls].tagt%mod;
		t[ls].tagp = (t[p].tagt*t[ls].tagp%mod+t[p].tagp%mod)%mod;
		t[ls].up = (t[ls].up%mod*t[p].tagt%mod+t[p].tagp%mod*(mid-l+1-t[ls].lc)%mod)%mod;
	}
	if (t[rs].cnt == 0) {
		t[rs].tagt = t[p].tagt*t[rs].tagt%mod;
		t[rs].tagp = (t[p].tagt*t[rs].tagp%mod+t[p].tagp%mod)%mod;
		t[rs].up = (t[rs].up%mod*t[p].tagt%mod+t[p].tagp%mod*(r-mid-t[rs].lc)%mod)%mod;
	}
	t[p].tagt = 1,t[p].tagp = 0;
}
void build(int p,int l,int r) {
	t[p].tagt = 1;
	if (l == r) {
		t[p].up = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(p);
}
void modify(int p,int v,int l,int r,int s,int e,int tp) {
	if (t[p].cnt > 0) return;
	if (l <= s && e <= r) {
		if (tp == 1) {
			t[p].up = ((e-s+1-t[p].lc)*v%mod+t[p].up)%mod;
			t[p].tagp = (t[p].tagp%mod+v%mod)%mod;
		}
		if (tp == 2) {
			t[p].up = (v%mod*t[p].up%mod)%mod;
			t[p].tagp = (t[p].tagp%mod*v%mod)%mod;
			t[p].tagt = (t[p].tagt%mod*v%mod)%mod; 
		}
		return;
	}
	int mid = (s + e) >> 1;
	pushdown(p,s,e);
	if (l <= mid) modify(ls,v,l,r,s,mid,tp);
	if (r > mid) modify(rs,v,l,r,mid+1,e,tp);
	pushup(p);
}
void lock(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		pushdown(p,s,e);
		if (t[p].cnt == 0) {
			t[p].lp = (t[p].lp+t[p].up)%mod;
			t[p].lc = e-s+1;
			t[p].up = 0;
		}
		++t[p].cnt;
		return;
	}
	int mid = (s + e) >> 1;
	pushdown(p,s,e);
	if (l <= mid) lock(ls,l,r,s,mid);
	if (r > mid) lock(rs,l,r,mid+1,e);
	pushup(p);
}
void unlock(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		--t[p].cnt;
		if (t[p].cnt == 0) {
			if (s == e) swap(t[p].up,t[p].lp),t[p].lc = 0;
			else pushup(p);
		}
		return;
	}
	int mid = (s + e) >> 1;
	pushdown(p,s,e);
	if (l <= mid) unlock(ls,l,r,s,mid);
	if (r > mid) unlock(rs,l,r,mid+1,e);
	pushup(p);
}
int query(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		return (t[p].up+t[p].lp)%mod;
	}
	int mid = (s + e) >> 1;
	pushdown(p,s,e);
	int ret = 0;
	if (l <= mid) ret = (ret + query(ls,l,r,s,mid)%mod) %mod;
	if (r > mid) ret = (ret + query(rs,l,r,mid+1,e)%mod) %mod;
	return ret;
}
struct Lock{
	int l,r,t;
	bool operator < (const Lock &a) const{
		return t > a.t;
	}
};
priority_queue<Lock> q;
signed main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	int l,r,op,x;
	for (int i = 1; i <= m; i++) {
		cin >> op >> l >> r;
		if (op == 1) {
			cin >> x;
			modify(1,x,l,r,1,n,1);
		}
		if (op == 2) {
			cin >> x;
			modify(1,x,l,r,1,n,2);
		}
		if (op == 3) {
			cin >> x;
			lock(1,l,r,1,n);
			q.push({l,r,i+x});
		}
		if (op == 4) {
			cout << query(1,l,r,1,n) % mod << '\n';
		}
		while (!q.empty()&&q.top().t == i) {
			unlock(1,q.top().l,q.top().r,1,n);
			q.pop();
		}
	}
	return 0;
}