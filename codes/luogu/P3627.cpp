<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+13;
int n,m,ans;
vector<int> e[maxn],e1[maxn];
int a[maxn],S,p,a1[maxn];
bool ed[maxn];
int dfn[maxn],low[maxn],cnt;
stack<int> s;
bool instk[maxn];
int scc[maxn],sc;
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
	if (low[u] == dfn[u]) {
		++sc;
		while (!s.empty()) {
			scc[s.top()] = sc;
			instk[s.top()] = false;
			a1[sc] += a[s.top()]; 
			if (s.top() == u) {
				s.pop();
				break;
			}
			s.pop();
		}
	}
}
bool vis[maxn];
int ind[maxn];
void dfs(int u) {
	vis[u] = true;
	for (int i = 0; i < e1[u].size(); i++) {
		int v = e1[u][i];
		if (!vis[v]) dfs(v);
	}
}
queue<int> q;
int f[maxn];
inline void topo() {
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < e1[u].size(); i++) {
			int v = e1[u][i];
			f[v] = max(f[v],f[u]+a1[v]);
			--ind[v];
			if (ind[v] == 0) q.push(v);
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
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> S >> p;
	for (int i = 1; i <= p; i++) {
		int x;
		cin >> x;
		ed[x] = true;
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < e[i].size(); j++) {
			int v = e[i][j];
			if (scc[i] == scc[v]) continue;
			e1[scc[i]].push_back(scc[v]);
			++ind[scc[v]];
		}
	}
	dfs(scc[S]);
	for (int i = 1; i <= sc; i++) {
		if (!vis[i]) {
			for (int j = 0; j < e1[i].size(); j++) {
				int v = e1[i][j];
				--ind[v];
			}
		}
	}
	q.push(scc[S]);
	f[scc[S]] = a1[scc[S]];
	topo();
	for (int i = 1; i <= n; i++) {
		if (ed[i]) ans = max(ans,f[scc[i]]);
	}
	cout << ans << '\n';
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+13;
int n,m,ans;
vector<int> e[maxn],e1[maxn];
int a[maxn],S,p,a1[maxn];
bool ed[maxn];
int dfn[maxn],low[maxn],cnt;
stack<int> s;
bool instk[maxn];
int scc[maxn],sc;
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
	if (low[u] == dfn[u]) {
		++sc;
		while (!s.empty()) {
			scc[s.top()] = sc;
			instk[s.top()] = false;
			a1[sc] += a[s.top()]; 
			if (s.top() == u) {
				s.pop();
				break;
			}
			s.pop();
		}
	}
}
bool vis[maxn];
int ind[maxn];
void dfs(int u) {
	vis[u] = true;
	for (int i = 0; i < e1[u].size(); i++) {
		int v = e1[u][i];
		if (!vis[v]) dfs(v);
	}
}
queue<int> q;
int f[maxn];
inline void topo() {
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < e1[u].size(); i++) {
			int v = e1[u][i];
			f[v] = max(f[v],f[u]+a1[v]);
			--ind[v];
			if (ind[v] == 0) q.push(v);
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
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> S >> p;
	for (int i = 1; i <= p; i++) {
		int x;
		cin >> x;
		ed[x] = true;
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < e[i].size(); j++) {
			int v = e[i][j];
			if (scc[i] == scc[v]) continue;
			e1[scc[i]].push_back(scc[v]);
			++ind[scc[v]];
		}
	}
	dfs(scc[S]);
	for (int i = 1; i <= sc; i++) {
		if (!vis[i]) {
			for (int j = 0; j < e1[i].size(); j++) {
				int v = e1[i][j];
				--ind[v];
			}
		}
	}
	q.push(scc[S]);
	f[scc[S]] = a1[scc[S]];
	topo();
	for (int i = 1; i <= n; i++) {
		if (ed[i]) ans = max(ans,f[scc[i]]);
	}
	cout << ans << '\n';
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}