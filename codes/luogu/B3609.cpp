#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int maxm = 1e5+4;
int n,m;
vector<int> e[maxn];
int sc[maxn];
int dfn[maxn],low[maxn],cnt;
stack<int> s;
bool instk[maxn],f[maxn];
vector<int> scc[maxn];
int scnt;
void tarjan(int u) {
	dfn[u] = low[u] = ++cnt;
	s.push(u);
	instk[u] = true;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(instk[v]) low[u] = min(low[u],dfn[v]);
	}
	if (dfn[u] == low[u]) {
		++scnt;
		while (!s.empty()) {
			scc[scnt].push_back(s.top());
			instk[s.top()] = false;
			sc[s.top()] = scnt;
			if (s.top() == u) {
				s.pop();
				break;
			}
			s.pop();
		}
	}
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	cout << scnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (f[i]) continue;
		f[i] = true;
		int p = sc[i];
		sort(scc[p].begin(),scc[p].end());
		for (int j = 0; j < scc[p].size(); j++) {
			cout << scc[p][j] << ' ';
			f[scc[p][j]] = true;
		}
		cout << '\n';
	}
	return 0;
}