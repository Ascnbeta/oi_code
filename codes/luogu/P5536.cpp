#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+300;
int n,k,ans = 0,cnt;
vector<int> e[maxn],di;
struct node{
	int p,v;
	bool operator < (const node &y) const{
		return v > y.v;
	}
};
vector<node> dot;
int x0,x1,x2;
int f[maxn],dis[maxn],len,maxdis[maxn];
void dfs(int u,int fa) {
	for (auto v : e[u]) {
		if (v == fa) continue;
		f[v] = u;
		dis[v] = dis[u] + 1;
		if (dis[v] > len) {
			len = dis[v];
			x0 = v;
		}
		dfs(v,u);
	}
}
void dfs1(int u,int fa) {
	maxdis[u] = dis[u];
	for (auto v : e[u]) {
		if (v == fa) continue;
		f[v] = u;
		dis[v] = dis[u] + 1;
		dfs1(v,u);
		maxdis[u] = max(maxdis[u],maxdis[v]);
	}
	dot.push_back({u,maxdis[u]-dis[u]});
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	x1 = x0;
	len = 0;
	memset(f,0,sizeof(f));
	memset(dis,0,sizeof(dis));
	dfs(x1,0);
	x2 = x0;
	for (int i = x2; i; i = f[i]) ++cnt,di.push_back(i);
	int mid = di[cnt/2];
	// cout << mid << '\n';
	memset(f,0,sizeof(f));
	memset(dis,0,sizeof(dis));
	dfs1(mid,0);
	sort(dot.begin(),dot.end());
	for (int i = k; i <= dot.size(); i++) {
		int p = dot[i].p;
		ans = max(ans,maxdis[p]-dis[p]+1);
	}
	cout << ans << '\n';
	return 0;
}