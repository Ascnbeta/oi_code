#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e4;
const int maxn = 1e4+10;
const int maxm = 5e4+20;
int n,m,s,t,t0;
struct edge{
	int v,w;
};
vector<edge> e[maxn];
int ind[maxn],f[maxn],sum[maxn];
queue<int> q;
inline void topo() {
	q.push(s);
	sum[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto i : e[u]) {
			int v = i.v;
			--ind[v];
			sum[v] = (sum[v] + sum[u] % mod) % mod;
			f[v] = (f[v] + (f[u] + i.w % mod * sum[u] % mod) % mod) % mod;
			if (!ind[v]) q.push(v);
		}
	}
	f[t] = (f[t] + ((sum[t] - 1) % mod * t0) % mod) % mod;
	cout << f[t] << '\n';
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> m >> s >> t >> t0;
	for (int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		++ind[v];
	}
	topo();
	return 0;
}
