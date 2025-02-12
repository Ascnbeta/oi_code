#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
const int maxm = 5e5+12;
int n,m;
int pc[maxn];
struct edge{
	int to,nxt;
}e[maxm<<1],e1[maxn<<1];
int head[maxn],tot;
inline void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int head1[maxn],tot1;
inline void add1(int u,int v) {
	e1[++tot1].to = v;
	e1[tot1].nxt = head1[u];
	head1[u] = tot1;
}
int dfn[maxn],low[maxn];
bool instk[maxn];
stack<int> s;
int scc[maxn],sc,cnt;
int minn[maxn],maxx[maxn];
void tarjan(int u) {
	dfn[u] = low[u] = ++cnt;
	s.push(u);
	instk[u] = true;
	for (int i = head[u]; i ;i = e[i].nxt) {
		int v = e[i].to;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if (instk[v]) low[u] = min(low[u],dfn[v]);
	}
	if (dfn[u] == low[u]) {
		++sc;
		while (!s.empty()) {
			instk[s.top()] = false;
			scc[s.top()] = sc;
			minn[sc] = min(minn[sc],pc[s.top()]);
			maxx[sc] = max(maxx[sc],pc[s.top()]);
			if (s.top() == u) {
				s.pop();
				break;
			}
			s.pop();
		}
	}
}
int f[maxn],ind[maxn],minp[maxn];
bool vis[maxn];
queue<int> q;
void topo(int s) {
	q.push(s);
	while (!q.empty()) {
		int t = q.front();
		vis[t] = true;
		q.pop();
		for (int i = head1[t]; i; i = e1[i].nxt) {
			int v = e1[i].to;
			if (!vis[v]) {
				if (f[t] > f[v]) {
					minp[v] = min(minn[v],minp[t]);
					f[v] = f[t];
				}
				if (maxx[v] - minp[t] > f[v]) {
					minp[v] = min(minn[v],minp[t]);
					f[v] = maxx[v] - minp[t];
				} 
				--ind[v];
				if (ind[v] == 0) q.push(v);
			}
 		}
	}
}
bool vis1[maxn];
void dfs(int u) {
	vis1[u] = true;
	for (int i = head1[u]; i; i = e1[i].nxt) {
		int v = e1[i].to;
		if (!vis1[v]) {
			dfs(v);
		}
 	}
}
int main () {
	cin >> n >> m;
	memset(minn,0x3f,sizeof(minn));
	for (int i = 1; i <= n; i++) cin >> pc[i];
	for (int i = 1; i <= m; i++) {
		int u,v,z;
		cin >> u >> v >> z;
		if (z == 1) {
			add(u,v);
		}else{
			add(u,v);
			add(v,u);
		}
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++) {
		for (int j = head[i]; j; j = e[j].nxt) {
			int v = e[j].to;
			if (scc[v] == scc[i] || scc[v] == scc[1]) continue;
			add1(scc[i],scc[v]);
			++ind[scc[v]];
		}
	}
	dfs(scc[1]);
	for (int i = 1; i <= sc; i++) {
		if (!vis1[i]) {
			for (int j = head1[i]; j; j = e1[j].nxt) {
				int v = e1[j].to;
				--ind[v];
			}
		}
	}
	//cout << scc[2] << '\n';
	for (int i = 1; i <= sc; i++) f[i] = maxx[i] - minn[i],minp[i] = minn[i];
	topo(scc[1]);
	cout << f[scc[n]] << '\n';
	return 0;
}