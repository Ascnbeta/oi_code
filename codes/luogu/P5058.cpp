#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
const int maxm = 5e5+12;
int n,a,b;
vector<int> e[maxn];
int dfn[maxn],low[maxn],cnt;
bool f[maxn];
void tarjan(int u,int fa) {
	dfn[u] = low[u] = ++cnt;
	for (auto &v : e[u]) {
		if (!dfn[v]) {
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if (u != fa && !f[u] && low[v] >= dfn[u] && dfn[b] >= dfn[v]) f[u] = true;
			
		}
			low[u] = min(low[u],dfn[v]);
	}
}
int main () {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	while (1) {
		int u,v;
		cin >> u >> v;
		if (u == 0 && v == 0) break;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cin >> a >> b;
	tarjan(a,a);
	for (int i = 1; i <= n; i++) {
		if (f[i]) {
			cout << i << '\n';
			return 0;
		}
	}
	puts("No solution");
	return 0;
}