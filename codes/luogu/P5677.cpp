#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3e5+15;
int n,m,ans;
int a[maxn],r,l;
map<int,int> pos;
struct zone{
	int id,l,r,ans;
}z[maxn];
struct node{
	int id,l,r;
	bool operator < (const node &y) const{
		return r < y.r;
	}
}no[maxn<<2];
int tot;
bool cmp1(zone &x,zone &y) {
	if (x.l == y.r) return x.l < y.r;
	return x.r < y.r;
}
int tr[maxn];
inline int lowbit(int x){
	return x&-x;
}
inline void modify(int pos,int x) {
	while (pos <= n) {
		tr[pos] += x;
		pos += lowbit(pos);
	}
}
inline int query(int pos) {
	if (pos == 0) return 0;
	int ret = 0;
	while (pos > 0) {
		ret += tr[pos];
		pos -= lowbit(pos);
	}
	return ret;
}
signed main () {
	cin >> n >> m;
	if (n == 1) {
		cout << ans << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++) cin >> a[i],pos[a[i]] = i;
	for (int i = 1; i <= m; i++) {
		cin >> z[i].l >> z[i].r;
		z[i].id = i;
	}
	sort(z+1,z+m+1,cmp1);
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			// puts("qwq");
			r = max(pos[a[i+1]],pos[a[i]]);
			l = min(pos[a[i+1]],pos[a[i]]);
			// cout << upd[1] << req[1] << '\n';
		}else if(i == n) {
			// puts("awa");
			r = max(pos[a[i-1]],pos[a[i]]);
			l = min(pos[a[i-1]],pos[a[i]]);
			// cout << upd[3] << req[3] << '\n';
		}else{
			int t;
			if (a[i+1]-a[i]<a[i]-a[i-1]) t = a[i+1];
			else if (a[i+1]-a[i]>a[i]-a[i-1]) t = a[i-1];
			else {
				r = max(pos[a[i]],pos[a[i+1]]);
				l = min(pos[a[i+1]],pos[a[i]]);
				no[++tot] = {pos[a[i]],l,r};
				r = max(pos[a[i]],pos[a[i-1]]);
				l = min(pos[a[i-1]],pos[a[i]]);
				no[++tot] = {pos[a[i]],l,r};
				continue;
			}
			r = max(pos[a[i]],pos[t]);
			l = min(pos[t],pos[a[i]]);
		}
		no[++tot] = {pos[a[i]],l,r};
	}
	// cout << "opt: \n";
	// for (int i = 1; i <= tot; i++) {
	// 	cout << no[i].l << ' ' << no[i].r << '\n';
	// }
	// cout << '\n';
	sort(no+1,no+tot+1);
	int j = 1;
	for (int i = 1; i <= m; i++) {
		for (; no[j].r <= z[i].r && j <= tot; j++) {
			modify(no[j].l,1);
		}
		//cout << z[i].id << ' ' << query(z[i].r) - query(z[i].l-1) << '\n';
		ans += (query(z[i].r) - query(z[i].l-1))*z[i].id;
	}
	// cout << "debug: ";
	// for (int i = 1; i <= n; i++) cout << query(i) << ' ';
	// cout << '\n';
	// sort(z+1,z+m+1,cmp2);
	cout << ans << '\n';
	return 0;
}