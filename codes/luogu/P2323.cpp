#include <bits/stdc++.h>
using namespace std;
int n,k,m,ans,cnt;
struct edge{
	int u,v,w1,w2,id;
}e1[20012],e2[20012];
int father[10002],rk[10002];
bool f[20012];
inline int find(int x) {
	int t = x;
	while (x != father[x]) x = father[x];
	int w;
	while (t != father[t]) w = father[t],father[t] = x,t = w;
	return father[x];
}
inline void merge(int x,int y) {
	int p = find(x),q = find(y);
	if (p == q) return;
	if (rk[p] <= rk[q]) {
		father[p] = q;
		rk[q] = max(rk[q],rk[p]+1);
		--cnt;
	}else{
		father[q] = p;
		rk[p] = max(rk[p],rk[q]+1);
		--cnt;
	}
}
bool cmp1(edge x,edge y) {
	return x.w1 < y.w1;
}
bool cmp2(edge x,edge y) {
	return x.w2 < y.w2;
}
vector<edge> ve;
inline bool check(int x) {
	for (int i = 1; i <= n; i++) father[i] = i,rk[i] = 0;
	cnt = n;
	for (int i = 1; i <= m; i++) f[i] = false;
	ve.clear();
	int chs = 0;
	for (int i = 1; i <= m; i++) {
		if (e1[i].w1 > x) break;
		int u = e1[i].u,v = e1[i].v;
		if (find(u) == find(v)) continue;
		else{
			merge(u,v);
			++chs;
			f[e1[i].id] = true;
			ve.push_back({1,0,e1[i].id,0,0});
		}
	}
	if (chs < k) return false;
	for (int i = 1; i <= m; i++) {
		if (e2[i].w2 > x) break;
		int u = e2[i].u,v = e2[i].v;
		if (f[e2[i].id] || find(u) == find(v)) continue;
		else{
			merge(u,v);
			f[e2[i].id] = true;
			ve.push_back({2,0,e2[i].id,0,0});
		}
	}
	if (cnt == 1) return true;
	else return false;
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> k >> m;
	for (int i = 1; i < m; i++) {
		cin >> e1[i].u >> e1[i].v >> e1[i].w1 >> e1[i].w2;
		e1[i].id = i;
		e2[i] = e1[i];
	}
	--m;
	sort(e1+1,e1+m+1,cmp1);
	sort(e2+1,e2+m+1,cmp2);
	int l = 0, r = 30000;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	cout << ans << '\n';
	check(ans);
	sort(ve.begin(),ve.end(),cmp1);
	for (auto i : ve) {
		cout << i.w1 << ' ' << i.u << '\n';
	}
	return 0;
}