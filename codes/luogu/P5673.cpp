#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
const int maxm = 5e5+10;
int n,m,k;
vector<int> pos[maxn];
int pt[maxn];
int p[maxn],v[maxn];
struct zone{
	int l,r,id,ans;
}z[maxm];
bool cmp1(zone &x,zone &y) {
	if (x.r == y.r) return x.l < y.l; 
	return x.r < y.r;
}
bool cmp2(zone &x,zone &y) {
	return x.id < y.id;
}
int t[maxn];
inline int lowbit(int x){
	return x&-x;
}
inline void modify(int p,int x) {
	while (p <= n) {
		t[p] += x;
		p += lowbit(p);
	}
}
inline int query(int p) {
	int ret = 0;
	while (p > 0) {
		ret += t[p];
		p -= lowbit(p);
	}
	return ret;
}
int main () {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> m >> k;
	--k;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <= m; i++) {
		cin >> z[i].l >> z[i].r;
		z[i].id = i;
	}
	sort(z+1,z+m+1,cmp1);
	int j = 1;
	for (int i = 1; i <= m; i++) {
		for (; j <= z[i].r && j <= n; j++) {
			if (pos[p[j]].size() < k) {
				pos[p[j]].push_back(j);
				modify(j,v[j]);
				pt[p[j]] = (pt[p[j]] + 1) % k;
			}else{
				modify(pos[p[j]][pt[p[j]]],-v[pos[p[j]][pt[p[j]]]]);
				pos[p[j]][pt[p[j]]] = j;
				modify(j,v[j]);
				pt[p[j]] = (pt[p[j]] + 1) % k;
			}
		}
		z[i].ans = query(z[i].r) - query(z[i].l-1);
	}
	sort(z+1,z+m+1,cmp2);
	for (int i = 1; i <= m; i++) {
		cout << z[i].ans << '\n';
	}
	return 0;
}