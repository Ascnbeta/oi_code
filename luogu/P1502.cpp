#include <bits/stdc++.h>
#define int long long
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 1e4+10;
const int inf = (1ll<<31)-1;
int T,n,w,h,n1,ans;
struct opt{
	int x,l,r,v;
	bool operator < (const opt &y) const{
		if (x == y.x) return v > y.v;
		return x < y.x;
	}
}op[maxn<<1];
int tot;
vector<int> tmp;
struct node{
	int max;
	int lz_t;
}t[maxn<<3];
inline void pushup(int p) {
	t[p].max = max(t[ls].max,t[rs].max);
}
inline void pushdown(int p) {
	t[ls].max += t[p].lz_t;
	t[ls].lz_t += t[p].lz_t;
	t[rs].max += t[p].lz_t;
	t[rs].lz_t += t[p].lz_t;
	t[p].lz_t = 0;
}
void build(int p,int l,int r) {
	if (l == r) {
		t[p].max = 0;
		t[p].lz_t = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(p);
}
void modify(int p,int v,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		t[p].max += v;
		t[p].lz_t += v;
		return;
	}
	int mid = (s + e) >> 1;
	if (t[p].lz_t && s != e) pushdown(p);
	if (l <= mid) modify(ls,v,l,r,s,mid);
	if (r > mid) modify(rs,v,l,r,mid+1,e);
	pushup(p);
}
signed main () {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin >> T;
	while(T--) {
		cin >> n >> w >> h;
		tmp.clear();
		tot = ans = 0;
		memset(op,0,sizeof(op));
		memset(t,0,sizeof(t));
		for (int i = 1; i <= n; i++) {
			int x,y,v;
			cin >> x >> y >> v;
			op[++tot].x = x,op[tot].r = y+h-1,op[tot].l = y,op[tot].v = v;
			op[++tot].x = x+w-1,op[tot].r = y+h-1,op[tot].l = y,op[tot].v = -v;
			tmp.push_back(y+h-1);
			tmp.push_back(y);
		}
		// for (auto &i : tmp) {
		// 	cout << i << ' ';
		// }
		sort(tmp.begin(),tmp.end());
		n1 = unique(tmp.begin(),tmp.end())-tmp.begin()-1;
		// cout << n1 << '\n';
		build(1,1,n1);
		sort(op+1,op+tot+1);
		// for (auto &i : tmp) {
		// 	cout << i << ' ';
		// }
		// cout << '\n';
		for (int i = 1; i <= tot; ++i) {
			int ll = lower_bound(tmp.begin()+1,tmp.begin()+n1+1,op[i].l)-tmp.begin();
			int rr = lower_bound(tmp.begin()+1,tmp.begin()+n1+1,op[i].r)-tmp.begin();
			//cout << "debug: " << op[i].x << ' ' << ll << ' ' << rr << ' ' << op[i].v << '\n';
			if (ll > rr) continue;
			modify(1,op[i].v,ll,rr,1,n1);
			ans = max(ans,t[1].max);
		}
		cout << ans << '\n';
	}
	return 0;
}