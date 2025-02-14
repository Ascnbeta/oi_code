<<<<<<< HEAD
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+6;
const int maxm = 1e6+3;
int n,m,mod,ans,num;
struct edge{
	int to,nxt;
}e[maxm],e1[maxm];
int head[maxn],tot,head1[maxn],tot1;
inline void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
inline void add1(int u,int v) {
	e1[++tot1].to = v;
	e1[tot1].nxt = head1[u];
	head1[u] = tot1;
}
int dfn[maxn],low[maxn];
bool instk[maxn];
stack<int> s;
int scc[maxn],sc,cnt,size[maxn];
set<int> st;
void tarjan(int u) {
	dfn[u] = low[u] = ++cnt;
	s.push(u);
	instk[u] = true;
	for (int i = head[u]; i ; i = e[i].nxt) {
		int v = e[i].to;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if (instk[v]) low[u] = min(low[u],dfn[v]);
	}
	if (dfn[u] == low[u]) {
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
int f[maxn],g[maxn];
signed main () {
	cin >> n >> m >> mod;
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		add(u,v);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++) {
		for (int j = head[i]; j; j = e[j].nxt) {
			int v = e[j].to;
			if (scc[v] == scc[i]) continue;
			add1(scc[i],scc[v]);
		}
	}
	for (int i = 1; i <= sc; i++) {
		f[i] = size[i];
		g[i] = 1;
	}
	for (int i = sc; i >= 1; i--) {
		for (int j = head1[i]; j ; j = e1[j].nxt) {
			int v = e1[j].to;
			if (st.find(100000*i+v) != st.end()) continue;
			st.insert(100000*i+v);
			if (f[i] + size[v] > f[v]) {
				f[v] = size[v] + f[i];
				g[v] = g[i];
			}else if(f[i] + size[v] == f[v]) {
				g[v] = (g[v] + g[i]) % mod;
			}
		}
	}
	for (int i = 1; i <= sc; i++) {
		if (f[i] > ans) {
			ans = f[i];
			num = g[i];
		}else if (f[i] == ans) {
			num = (num + g[i]) % mod;
		}
	}
	cout << ans << '\n' << num << '\n';
 	return 0;
=======
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+6;
const int maxm = 1e6+3;
int n,m,mod,ans,num;
struct edge{
	int to,nxt;
}e[maxm],e1[maxm];
int head[maxn],tot,head1[maxn],tot1;
inline void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
inline void add1(int u,int v) {
	e1[++tot1].to = v;
	e1[tot1].nxt = head1[u];
	head1[u] = tot1;
}
int dfn[maxn],low[maxn];
bool instk[maxn];
stack<int> s;
int scc[maxn],sc,cnt,size[maxn];
set<int> st;
void tarjan(int u) {
	dfn[u] = low[u] = ++cnt;
	s.push(u);
	instk[u] = true;
	for (int i = head[u]; i ; i = e[i].nxt) {
		int v = e[i].to;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if (instk[v]) low[u] = min(low[u],dfn[v]);
	}
	if (dfn[u] == low[u]) {
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
int f[maxn],g[maxn];
signed main () {
	cin >> n >> m >> mod;
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		add(u,v);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++) {
		for (int j = head[i]; j; j = e[j].nxt) {
			int v = e[j].to;
			if (scc[v] == scc[i]) continue;
			add1(scc[i],scc[v]);
		}
	}
	for (int i = 1; i <= sc; i++) {
		f[i] = size[i];
		g[i] = 1;
	}
	for (int i = sc; i >= 1; i--) {
		for (int j = head1[i]; j ; j = e1[j].nxt) {
			int v = e1[j].to;
			if (st.find(100000*i+v) != st.end()) continue;
			st.insert(100000*i+v);
			if (f[i] + size[v] > f[v]) {
				f[v] = size[v] + f[i];
				g[v] = g[i];
			}else if(f[i] + size[v] == f[v]) {
				g[v] = (g[v] + g[i]) % mod;
			}
		}
	}
	for (int i = 1; i <= sc; i++) {
		if (f[i] > ans) {
			ans = f[i];
			num = g[i];
		}else if (f[i] == ans) {
			num = (num + g[i]) % mod;
		}
	}
	cout << ans << '\n' << num << '\n';
 	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}