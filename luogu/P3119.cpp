#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+30;
const int maxm = 1e5+30;
int n,m;
vector<int> e[maxn],e1[maxn],w1[maxn];
int dfn[maxn],low[maxn],cnt;
bool instk[maxn];
stack<int> s;
int scc[maxn],sc,siz[maxn];
void tarjan(int u) {	
	dfn[u] = low[u] = ++cnt;
	s.push(u);
	instk[u] = true;
	for (auto v : e[u]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(instk[v]) {
			low[u] = min(low[u],dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		++sc;
		while (!s.empty()) {
			instk[s.top()] = false;
			scc[s.top()] = sc;
			++siz[sc];
			if (s.top() == u) {
				s.pop();
				break;
			}
			s.pop();
		}
	}
}
queue<int> q;
int dis[maxn];
bool vis[maxn];
inline void spfa(int s) {
	q.push(s);
	vis[s] = true;
	dis[s] = siz[s];
	while(!q.empty()) {
		int u = q.front();
		vis[u] = false;
		q.pop();
		for (auto v : e1[u]) {
			if (dis[v] < dis[u] + siz[v]) {
				dis[v] = dis[u] + siz[v];
				if (!vis[v]) {
					q.push(v);
					vis[v] = true;
				}
			}
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
	for (int i = 1; i <= sc;i++) {
		siz[sc+i] = siz[i];
	}
	for (int u = 1; u <= n; u++) {
		// cout << scc[u] << ' ';
		for (auto v : e[u]) {
			if (scc[u] == scc[v]) continue;
			e1[scc[u]].push_back(scc[v]);
			e1[scc[u]+sc].push_back(scc[v]+sc);			
			e1[scc[v]].push_back(scc[u]+sc);
		}
	}
	// cout << '\n';
	// for (int i = 1; i <= 2*sc; i++) {
	// 	for (auto v : e1[i]) {
	// 		cout << i << ' ' << v << '\n';
	// 	}
	// }
	spfa(scc[1]);
	int ans = siz[scc[1]];
	cout << max(ans,dis[scc[1]+sc]-ans) << '\n';
	return 0;
}