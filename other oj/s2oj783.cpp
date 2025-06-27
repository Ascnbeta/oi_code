#include <bits/stdc++.h>
using namespace std;
const int maxn= 5e4+10;
template <typename T>
inline void read(T &x) {
	x=0;int f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
int n,m,tot,s,ed;
struct edge{
	int v,w;
};
int L,R;
vector<edge> e[maxn];int t[maxn],y[maxn];bool vis[maxn];
inline void dfs(int u,int p) {
	vis[u] = true;
	if (u == ed) return;
	for (auto i : e[u]) {
		int v = i.v,w = i.w;
		if (vis[v]) continue;
		if (1.0*(y[t[u]]+y[t[v]])/200.0*w < 1.0*p) continue;
		dfs(v,p);
	}
}
inline void dfs1(int u,int p) {
	vis[u] = true;
	if (u == ed) return;
	for (auto i : e[u]) {
		int v = i.v,w = i.w;
		if (vis[v]) continue;
		if ((y[t[u]]+y[t[v]])/200.0*w < 1.0*L || (y[t[u]]+y[t[v]])/200.0*w > 1.0*p) continue;
		dfs1(v,p);
	}
}
inline bool check(int x) {
	memset(vis,0,sizeof(vis));
	dfs(s,x);
	return vis[ed];
}
inline bool check1(int x) {
	memset(vis,0,sizeof(vis));
	dfs1(s,x);
	return vis[ed];
}
int main () {

#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
	read(n),read(m);
	int maxx = 0;
	for (int i = 1; i <= m; i++) {
		int u,v,w;
		tot = max(tot,max(u,v));
		read(u),read(v),read(w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		maxx = max(maxx,w);
	}
	for (int i = 1; i <= n; i++) {
		int cnt;
		read(cnt);
		for (int j = 1; j <= cnt; j++) {
			int x;read(x);t[x] = i;
		}
	}
	// for (int i = 1; i <= tot; i++) {
	// 	cout << t[i] << ' ';
	// }
	// cout << '\n';
	for (int i = 1; i <= n; i++) read(y[i]);
	read(s),read(ed);
	int l = 0,r = 15000;L = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			L = mid;
			l = mid + 1;
		}else {
			r = mid - 1;
		}
	}
	l = L,r = 15000,R = 15000;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check1(mid)) {
			R = mid;
			r = mid - 1;
		}else {
			l = mid + 1;
		}
	}
	if (L < 0 ) L = 0;if (R > 15000) R = maxx;
	cout << L << ' ' << R << '\n';
	return 0;
}
/*
3 7
1 2 3
5 2 8
1 3 7
5 4 5
2 4 9
3 5 10
3 4 2
2 1 2
1 3
2 4 5
30 50 60
1 5
*/
