#include <bits/stdc++.h>
#define ls (p<<1)
#define rs (p<<1|1)
#define int long long
using namespace std;
const int maxn = 2e5+6;
int n,m,p1,p2;
int k[maxn];
stack<int> st1;
int ll[maxn],rr[maxn];
int tr[maxn<<2],tg[maxn<<2];
struct node{
	int l,r,p,tp;
}s[maxn<<1],s1[maxn],s2[maxn];
int tot;
inline bool cmp1(const node x,const node y) {
	return x.l < y.l;
}
inline bool cmp2(const node x,const node y) {
	return x.r < y.r;
}
inline bool cmp3(const node x,const node y) {
	return x.p < y.p;
}
inline void pushup(int p) {
	tr[p] = tr[ls] + tr[rs];
}
inline void pushdown(int p,int l,int r) {
	int mid = (l + r) >> 1;
	tg[ls] += tg[p];
	tg[rs] += tg[p];
	tr[ls] += tg[p]*(mid-l+1);
	tr[rs] += tg[p]*(r-mid);
	tg[p] = 0;
}
inline void modify(int p,int v,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		tr[p] += v*(e-s+1);
		tg[p] += v;
		return;
	}
	int mid = (s + e) >> 1;
	if (s != e && tg[p]) pushdown(p,s,e);
	if (l <= mid) modify(ls,v,l,r,s,mid);
	if (r > mid) modify(rs,v,l,r,mid+1,e);
	pushup(p);
}
inline int query(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		return tr[p];
	}
	int mid = (s + e) >> 1;
	if (s != e && tg[p]) pushdown(p,s,e);
	int ret = 0;
	if (l <= mid) ret += query(ls,l,r,s,mid);
	if (r > mid) ret += query(rs,l,r,mid+1,e);
	return ret;
}
int ans[maxn];
signed main () {
	cin >> n >> m >> p1 >> p2;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		while (!st1.empty() && k[st1.top()] < k[i]) st1.pop();
		if (!st1.empty()) {
			ll[i] = st1.top();
		}
		st1.push(i);
	}
	while(!st1.empty()) st1.pop();
	for (int i = n; i >= 1; i--) {
		while (!st1.empty() && k[st1.top()] < k[i]) st1.pop();
		if (!st1.empty()) {
			rr[i] = st1.top();
		}else{
			rr[i] = n+1;
		}
		st1.push(i);
	}
//	for (int i = 1; i <= n; i++) {
//		cout << ll[i] << ' ' << rr[i] << '\n';
//	}
	for (int i = 1; i <= n; i++) {
		if (ll[i] >= 1 && rr[i] <= n) s[++tot] = node{ll[i],ll[i],rr[i],p1};
		if (ll[i] < i-1 && rr[i] <= n) s[++tot] = node{ll[i]+1,i-1,rr[i],p2};
		if (ll[i] >= 1 && rr[i] > i+1) s[++tot] = node{i+1,rr[i]-1,ll[i],p2};
	}
	for (int i = 1; i <= m; i++) {
		int x,y;
		cin >> x >> y;
		s1[i].l = s2[i].l = x;
		s1[i].r = s2[i].r = y; 
		s1[i].p = s2[i].p = i;
	}
	sort(s1+1,s1+m+1,cmp1);
	sort(s2+1,s2+m+1,cmp2);
	sort(s+1,s+tot+1,cmp3);
	int cnt1 = 1,cnt2 = 1,cnt3 = 1;	
	while(s1[cnt2].l == 1&&cnt2 <= m) ++cnt2;
	for (int i = 1; i <= n; i++) {
		while (cnt1 <= tot && i == s[cnt1].p) {
			modify(1,s[cnt1].tp,s[cnt1].l,s[cnt1].r,1,n);
			++cnt1;
		}
		while (cnt2 <= m && i + 1 == s1[cnt2].l) {
			ans[s1[cnt2].p] -= query(1,s1[cnt2].l,s1[cnt2].r,1,n);
			++cnt2;
		}
		while (cnt3 <= m && i == s2[cnt3].r) {
			ans[s2[cnt3].p] += query(1,s2[cnt3].l,s2[cnt3].r,1,n)+p1*(s2[cnt3].r-s2[cnt3].l);
			++cnt3;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
