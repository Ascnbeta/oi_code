#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e2+10;
const int maxm = 3e4+10;
int n,m;
int c[maxn],d[maxn],ind[maxn],sum[maxn],oud[maxn];
struct edge{
	int v,w;
};
vector<edge> e[maxn];
queue<int> q;
inline void topo() {
	for (int i = 1; i <= n; i++) if (!ind[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto &i : e[u]) {
			ind[i.v]--;
			if (c[u] > 0) sum[i.v] += i.w*c[u];
			if (!ind[i.v]) {
				c[i.v] = sum[i.v] - d[i.v];
				q.push(i.v);
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!oud[i] && c[i] > 0) {
			cout << i << ' ' << c[i] << '\n';
			++cnt;
		}
	}
	if (cnt == 0) puts("NULL");
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> d[i];
	}
	for (int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		++ind[v];
		++oud[u];
	}
	topo();
	return 0;
}