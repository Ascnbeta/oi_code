#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+6;
const int maxm = 2e5+64;
int n,m;
struct edge{
	int to,nxt,w;
}e[maxm],e1[maxm];
struct relation{
	int a,b,tp;
}r[maxm];
int head[maxn],tot,head1[maxn],tot1;
inline void add(int u,int v,int w) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	e[tot].w = w;
	head[u] = tot;
}
inline void add1(int u,int v,int w) {
	e1[++tot1].to = v;
	e1[tot1].nxt = head1[u];
	e1[tot1].w = w;
	head1[u] = tot1;
}
int dfn[maxn],low[maxn];
bool instk[maxn];
stack<int> s;
int scc[maxn],sc,cnt,size[maxn];
void tarjan(int u) {
	dfn[u] = low[u] = ++cnt;
	s.push(u);
	instk[u] = true;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if (instk[v]) low[u] = min(low[u],dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++sc;
		while (!s.empty()) {
			scc[s.top()] = sc;
			instk[s.top()] = false;
			++size[sc];
			if (s.top() == u) {
				s.pop();
				break;
			}
			s.pop();
		}
	}
}
int ind[maxn],cnt2,f[maxn],ans;
bool vis[maxn];
queue<int> q;
inline void topo(){
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = true;
		ans += size[u]*f[u];
		++cnt2;
		for (int i = head1[u]; i; i = e1[i].nxt) {
			int v = e1[i].to;
			if (vis[v]) continue;
			if (e1[i].w == 1) {
				f[v] = max(f[v],f[u]+1);
			}else{
				f[v] = max(f[v],f[u]);
			}
			--ind[v];
			if (ind[v] == 0) q.push(v);
		}
	}
}
signed main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> r[i].tp >> r[i].a >> r[i].b;
	for (int i = 1; i <= m; i++) {
		if (r[i].tp == 1) {
			add(r[i].a,r[i].b,0);
			add(r[i].b,r[i].a,0); 
		}
		if (r[i].tp == 3) {
			add(r[i].b,r[i].a,0);
		}
		if (r[i].tp == 5) {
			add(r[i].a,r[i].b,0);
		}
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++) {
		for (int j = head[i]; j; j = e[j].nxt) {
			int v = e[j].to;
			if (scc[i] == scc[v]) continue;
			add1(scc[i],scc[v],e[j].w);
			ind[scc[v]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (r[i].tp == 2) {
			add1(scc[r[i].a],scc[r[i].b],1);
			ind[scc[r[i].b]]++;
		}
		if (r[i].tp == 4) {
			add1(scc[r[i].b],scc[r[i].a],1);
			ind[scc[r[i].a]]++;
		}
	}
	for (int i = 1; i <= sc; i++) if (!ind[i]) f[i] = 1,q.push(i);
	topo();
	if (cnt2 < sc) puts("-1");
	else {
		cout << ans << '\n';
	}
	return 0;
}