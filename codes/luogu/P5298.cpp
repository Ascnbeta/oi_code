#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3e5+10;
const int maxl = 7e6+10;
const int mod = 998244353;
int n;
vector<int> e[maxn];
int p[maxn],w[maxn],w1[maxn],ccnt[maxn];
int t[maxl],ls[maxl],rs[maxl],tot,rt[maxn];
inline int binpow(int a,int p) {
	int base = a,ret = 1;
	while (p) {
		if (p & 1) ret = ret * base % mod;
		p >>= 1;
		base = base * base % mod;
	}
	return ret % mod;
}
const int d = binpow(10000,mod-2);
inline void pushup(int p) {
	t[p] = (t[ls[p]] + t[rs[p]]) % mod;
}
void modify(int &p,int pos,int v,int l,int r) {
	if (!p) p = ++tot;
	// cout << pos << ' ' << p << ' ' << l << ' ' << r << '\n';
	if (l == r) {
		t[p] = v;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) modify(ls[p],pos,v,l,mid);
	if (pos > mid) modify(rs[p],pos,v,mid+1,r);
	pushup(p);
}
int query(int &p,int l,int r,int s,int e) {
	// cout << p << ' ' << s << ' ' << e <<  '\n';
	if (!p) return 0;
	if (l <= s && e <= r) {
		return t[p]%mod;
	}
	int mid = (s + e) >> 1;
	int ret = 0;
	if (l <= mid) ret = (ret + query(ls[p],l,r,s,mid)) % mod;
	if (r > mid) ret = (ret + query(rs[p],l,r,mid+1,e)) % mod;
	return ret % mod;
}
int merge(int &p1,int p2,int p3,int l,int r,int u) {
	if (!p2 && !p3) return 0;
	cout << l << ' ' << r << '\n'; 
	if (!p1) p1 = ++tot;
	if (l == r) {
		t[p1] = (t[p2]*((p[u]*query(rt[e[u][1]],1,l-1,1,maxn)%mod+(10000-p[u])*query(rt[e[u][1]],l+1,maxn,1,maxn)%mod)%mod)%mod+
				t[p3]*((p[u]*query(rt[e[u][0]],1,l-1,1,maxn)%mod+(10000-p[u])*query(rt[e[u][0]],l+1,maxn,1,maxn)%mod)%mod)%mod)%mod;
		cout << t[p1] << '\n';
	}
	int mid = (l + r) >> 1;
	ls[p1] = merge(ls[p1],ls[p2],ls[p3],l,mid,u);
	rs[p1] = merge(rs[p1],rs[p2],rs[p3],mid+1,r,u);
	pushup(p1);
	return p1;
}
void dfs(int u) {
	if (e[u].size() == 0) return;
	else if (e[u].size() == 1) {
		puts("qwq");
		dfs(e[u][0]);
		rt[u] = rt[e[u][0]];
	}else{
		puts("awa");
		// cout << e[u][0] << ' ' << e[u][1] << ' ' << e[u][2] << '\n';
		dfs(e[u][0]),dfs(e[u][1]);
		cout << e[u][0] << ' ' << e[u][1] << '\n';
		rt[u] = merge(rt[u],rt[e[u][0]],rt[e[u][1]],1,maxn,u);
	} 
}
signed main () {
	//cout << binpow(2,mod-2) << '\n';
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		e[t].push_back(i);
		ccnt[t]++;
		rt[i] = ++tot;
	}
	for (int i = 1; i <= n; i++) {
		if (ccnt[i] == 0) cin >> w[i],w1[i] = w[i];
		else {
			int t;
			cin >> t;
			p[i] = t*d%mod;
		}
	}
	sort(w1+1,w1+n+1);
	int n1 = unique(w1+1,w1+n+1)-w1-1;
	for (int i = 1; i <= n; i++) {
		if (w[i] == 0) continue;
		w[i] = lower_bound(w1+1,w1+n1+1,w[i])-w1;
		modify(rt[i],w[i],1,1,maxn);
	}
	//for (int i = 1; i <= n1; i++) cout << w1[i] << ' ';
	// cout << query(rt[3],2,2,1,maxn) << '\n';
	//^^^离散化
	dfs(1);
	cout << query(rt[1],3,3,1,maxn) << '\n';
	return 0;
}