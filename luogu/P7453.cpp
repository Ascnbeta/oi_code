#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 2.5e5;
const int mod = 998244353;
int n,m;
int a[maxn],b[maxn],c[maxn];
struct matrix{
	int m[4][4],l=0,r=0;
	matrix(int x,int y) {
		for (int i = 0; i <= x; i++) {
			for (int j = 0; j <= y; j++) m[i][j] = 0;
		}
		l = x,r = y;
	}
	matrix() {
		return;
	}
	inline void reset() {
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				m[i][j] = 0;
			}
		}
	}
	inline void base() {
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				m[i][j] = (i==j)?(1):(0);
			}
		}
	}
	matrix operator * (const matrix &y) const{
		matrix c(l,r);
		assert(r==y.l);
		int tmp;
		for (int i = 1; i <= l; i++) {
			for (int k = 1; k <= r; k++) {
				tmp = m[i][k];
				for (int j = 1; j <= r; j++) {
					c.m[i][j] =(long long)( c.m[i][j] + (long long)tmp * y.m[k][j] % mod ) % mod;
				}
			}
		}
		return c;
	}
	matrix operator * (const int &y) const{
		matrix c(l,r);
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				c.m[i][j] = (long long)m[i][j] * y % mod;
			}
		}
		return c;
	}
	matrix operator + (const matrix &y) const {
		matrix c(l,r);
		assert(l==y.l&&r==y.r);
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				c.m[i][j] = (long long)(m[i][j]+y.m[i][j])%mod;
			}
		}
		return c;
	}
	bool operator != (const matrix &y) {
		if (l != y.l || r != y.r) return true;
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				if (m[i][j] != y.m[i][j]) return true;
			}
		}
		return false;
	}
	inline void print() {
		cout << l << ' ' << r << '\n';
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) cout << m[i][j] << ' ';
			cout << '\n';
		}
	}
}val[maxn<<2];
matrix tagm[maxn<<2],taga[maxn<<2];
matrix opt[10],used[3];
inline void init() {
	opt[1].l = 3,opt[1].r = 3;
	opt[1].m[1][1] = 1;
	opt[1].m[2][1] = 1,opt[1].m[2][2] = 1;
	opt[1].m[3][3] = 1;
	opt[2].l = 3,opt[2].r = 3;
	opt[2].m[1][1] = 1;
	opt[2].m[2][2] = 1;
	opt[2].m[3][2] = 1,opt[2].m[3][3] = 1;
	opt[3].l = 3,opt[3].r = 3;
	opt[3].m[1][1] = 1,opt[3].m[1][3] = 1;
	opt[3].m[2][2] = 1;
	opt[3].m[3][3] = 1;
	opt[4].l = 1,opt[4].r = 3;
	opt[4].m[1][1] = 1,opt[4].m[1][2] = 0,opt[4].m[1][3] = 0;
	opt[5].l = 3,opt[5].r = 3;
	opt[5].m[1][1] = 1;
	opt[5].m[2][2] = 1;
	opt[5].m[3][3] = 1;
	opt[6].l = 3,opt[6].r = 3;
	opt[6].m[1][1] = 1;
	opt[6].m[2][2] = 1;
	opt[7].l = 1,opt[7].r = 3;
	opt[7].m[1][1] = 0,opt[7].m[1][2] = 0,opt[7].m[1][3] = 1;
	used[1].l = 3,used[1].r = 3,used[1].base();
	used[2].l = 1,used[2].r = 3;
}
inline void pushup(int p) {
	val[p] = val[ls] + val[rs];
}
inline void pushdown(int p,int l,int r) {
	int mid = (l + r) >> 1;
	val[ls] = val[ls] * tagm[p];
	val[ls] = val[ls] + taga[p] * (mid-l+1);
	val[rs] = val[rs] * tagm[p];
	val[rs] = val[rs] + taga[p] * (r-mid);
	tagm[ls] = tagm[ls] * tagm[p];
	tagm[rs] = tagm[rs] * tagm[p];
	taga[ls] = taga[ls] * tagm[p] + taga[p];
	taga[rs] = taga[rs] * tagm[p] + taga[p];
	tagm[p].base(),taga[p].reset();
}
inline void build(int p,int l,int r) {
	tagm[p].l = 3,tagm[p].r = 3,tagm[p].base();
	taga[p].l = 1,taga[p].r = 3;
	if (l == r) {
		val[p].l = 1,val[p].r = 3;
		val[p].m[1][1] = a[l],val[p].m[1][2] = b[l],val[p].m[1][3] = c[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(p);
}
inline void modifym(int p,int s,int e,int tp,int l,int r) {
	if (s <= l && r <= e) {
		val[p] = val[p] * opt[tp];
		taga[p] = taga[p] * opt[tp];
		tagm[p] = tagm[p] * opt[tp];
		return;
	}
	int mid = (l + r) >> 1;
	if (l != r && (tagm[p] != used[1] || taga[p] != used[2])) pushdown(p,l,r);
	if (s <= mid) modifym(ls,s,e,tp,l,mid);
	if (e > mid) modifym(rs,s,e,tp,mid+1,r);
	pushup(p);
}
inline void modifya(int p,int s,int e,int tp,int l,int r) {
	if (s <= l && r <= e) {
		val[p] = val[p] + opt[tp] * (r-l+1);
		taga[p] = taga[p] + opt[tp];
		return;
	}
	int mid = (l + r) >> 1;
	if (l != r && (tagm[p] != used[1] || taga[p] != used[2])) pushdown(p,l,r);
	if (s <= mid) modifya(ls,s,e,tp,l,mid);
	if (e > mid) modifya(rs,s,e,tp,mid+1,r);
	pushup(p);
}
inline matrix query(int p,int s,int e,int l,int r) {
	if (s <= l && r <= e) {
		return val[p];
	}
	int mid = (l + r) >> 1;
	if ((tagm[p] != used[1] || taga[p] != used[2]) && l != r) pushdown(p,l,r);
	matrix ret(1,3);
	if (s <= mid) ret = ret + query(ls,s,e,l,mid);
	if (e > mid) ret = ret + query(rs,s,e,mid+1,r);
	return ret;
}
int main () {
	#ifdef LOCAL
		freopen("D:/codes/exe/a.in","r",stdin);
		freopen("D:/codes/exe/a.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i]; 
	build(1,1,n);
	init();
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			int x,y;
			cin >> x >> y;
			modifym(1,x,y,1,1,n);
		}else if (op == 2) {
			int x,y;
			cin >> x >> y;
			modifym(1,x,y,2,1,n);
		}else if (op == 3) {
			int x,y;
			cin >> x >> y;
			modifym(1,x,y,3,1,n);
		}else if (op == 4) {
			int x,y,v;
			cin >> x >> y >> v;
			opt[4].m[1][1] = v;
			modifya(1,x,y,4,1,n);
			opt[4].m[1][1] = 1;
		}else if (op == 5) {
			int x,y,v;
			cin >> x >> y >> v;
			opt[5].m[2][2] = v;
			modifym(1,x,y,5,1,n);
			opt[5].m[2][2] = 1;
		}else if (op == 6) {
			int x,y,v;
			cin >> x >> y >> v;
			modifym(1,x,y,6,1,n);
			opt[7].m[1][3] = v;
			modifya(1,x,y,7,1,n);
			opt[7].m[1][3] = 0;
		}else{
			int x,y;
			cin >> x >> y;
			matrix tmp = query(1,x,y,1,n);
			cout << tmp.m[1][1] << ' ' << tmp.m[1][2] << ' ' << tmp.m[1][3] << '\n';
		}
	}
	return 0;
}