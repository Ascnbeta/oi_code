#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3e5+25;
int n,L,R,ans;
int a[maxn],sum[maxn];
vector<int> b;
int t[maxn<<2];
inline void pushup(int p) {
	t[p] = t[p<<1] + t[p<<1|1];
}
void modify(int p,int pos,int v,int s,int e) {
	if (s == e) {
		t[p] += v;
		return;
	}
	int mid = (s + e) >> 1;
	if (pos <= mid) modify(p<<1,pos,v,s,mid);
	if (pos > mid) modify(p<<1|1,pos,v,mid+1,e);
	pushup(p);
}
int query(int p,int l,int r,int s,int e) {
	if (l <= s && e <= r) {
		return t[p];
	}
	int mid = (s + e) >> 1;
	int ret = 0;
	if (l <= mid) ret += query(p<<1,l,r,s,mid);
	if (r > mid) ret += query(p<<1|1,l,r,mid+1,e);
	return ret;
}
signed main () {
	cin >> n >> L >> R;
	for (int i = 1; i <= n; i++) {cin >> a[i],sum[i]=a[i]+sum[i-1],b.push_back(sum[i]);}
	b.push_back(0);
	sort(b.begin(),b.end());
	unique(b.begin(),b.end());
	int tmp = lower_bound(b.begin(),b.end(),0)-b.begin()+1;
	modify(1,tmp,1,1,n+1);
	for (int i = 1; i <= n; i++) {
		int ll = lower_bound(b.begin(),b.end(),sum[i]-R)-b.begin()+1;
		int rr = upper_bound(b.begin(),b.end(),sum[i]-L)-b.begin();
		// cout<<ll<<' '<<rr<<endl;
		if (ll <= rr) ans += query(1,ll,rr,1,n+1);
		int p1 = lower_bound(b.begin(),b.end(),sum[i])-b.begin()+1;
		modify(1,p1,1,1,n+1);
	}
	cout << ans << '\n';
	return 0;
}