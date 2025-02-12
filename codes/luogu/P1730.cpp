#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
const double eps = 1e-8;
int n,m,Q;
struct edge{
	int v,w;
};
vector<edge> e[maxn];
int x,y;
queue<int> q;
bool vis[maxn],f;
double dis[maxn];
inline bool spfa(int s,int tgt,double val) {
	q.push(s);
	for (int i = 1; i <= n; i++) dis[i] = 1e9;
	dis[s] = 0;
	vis[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = 0; i < e[u].size(); i++) {
			int v = e[u][i].v;
			if (dis[v] > dis[u] + e[u][i].w - val) {
				dis[v] = dis[u] + e[u][i].w - val;
				if (!vis[v]) q.push(v);
			}
		}
	}
	if (dis[tgt] > 0) return false;
	else return f = true;
}
double ans[maxn][maxn];
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
	}
	cin >> Q;
	while (Q--) {
		cin >> x >> y;
		if (ans[x][y] != 0) {
			if (ans[x][y] != 1e9) printf("%.3f\n",ans[x][y]);
			else puts("OMG!");
			continue;
		}
		double l = 0,r = 1e5;
		f = false;
		while (r - l > eps) {
			double mid = (l + r) / 2;
			if (spfa(x,y,mid)) {
				r = mid;
			}else{
				l = mid;
			}
		}
		if (!f) puts("OMG!"),ans[x][y] = 1e9;
		else printf("%.3f\n",l),ans[x][y] = l;
	}
	return 0;
}