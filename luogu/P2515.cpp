#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+30;
const int maxm = 1e4+30;
int n,m,ans;
int v[maxn],w[maxn];
vector<int> e[maxn],e1[maxn];
int dfn[maxn],low[maxn],cnt;
bool instk[maxn];
int scc[maxn],sc,siz[maxn],v1[maxn],w1[maxn];
stack<int> s;
bool vis[maxn];
void tarjan(int u) {
	dfn[u] = low[u] = ++cnt;
	s.push(u);
	instk[u] = true;
	for (auto v : e[u]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if (instk[v]) {
			low[u] = min(low[u],dfn[v]);
		}
	}
	if (low[u] == dfn[u]) {
		++sc;
		while (!s.empty()) {
			instk[u] = false;
			scc[s.top()] = sc;
			v1[sc] += v[s.top()];
			w1[sc] += w[s.top()];
			siz[sc]++;
			if (s.top() == u) {
				s.pop();
				break;
			}
			s.pop();
		}
	}
}
int siz1[maxn],f[maxn],g[maxn][maxn],ind[maxn];
void dfs(int u) {
	vis[u] = true;
	siz1[u] = w1[u];
	g[u][0] = 0;
	g[u][w1[u]] = v1[u]; 
	for (auto v : e1[u]) {
		dfs(v);
		for (int i = m; i >= 0; i--) {
			for (int j = 0; j <= i-w1[u]; j++) {
				g[u][i] = max(g[u][i],g[u][i-j]+g[v][j]);
			}
		}
		siz1[u] += siz1[v];
	}
}
int main() {
#ifdef LOCAL
	freopen("D:/codes/exe/a.in","r",stdin);
	freopen("D:/codes/exe/a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		e[x].push_back(i);
	}
	for (int i = 0; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int u = 0; u <= n; u++) {
		for (auto v : e[u]) {
			if (scc[u] == scc[v]) continue;
			e1[scc[u]].push_back(scc[v]);
			++ind[scc[v]];
		}
	}
	memset(f,0xc0,sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= sc; i++) {
		if (!ind[i]) {
			dfs(i);
			for (int j = m; j >= 0; j--) {
				for (int k = 0; k <= j; k++) {
					f[j] = max(f[j],f[j-k]+g[i][k]);
				}
				ans = max(f[j],ans);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}