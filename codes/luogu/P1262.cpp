<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3+10;
int n,p,r,ans;
int c[3005],c1[3005],id[maxn];
vector<int> e[3005],e1[3005];
int dfn[maxn],low[maxn],cnt;
bool instk[maxn];
stack<int> s;
int sc,scc[maxn],ind[maxn],minn = 0x3f3f3f3f;
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
		++sc;
		while (!s.empty()) {
			scc[s.top()] = sc;
			instk[s.top()] = false;
			id[sc] = min(id[sc],s.top());
			c1[sc] = min(c1[sc],c[s.top()]);
			if (s.top() == u) {
				s.pop();
				break;
			}
			s.pop();
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	memset(c,0x3f,sizeof(c));
	memset(c1,0x3f,sizeof(c1));
	memset(id,0x3f,sizeof(id));
	cin >> n >> p;
	for (int i = 1; i <= p; i++) {
		int pt;
		cin >> pt;
		cin >> c[pt];
	}
	cin >> r;
	for (int i = 1; i <= r; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++) {
		// cout << c[i] << '\n';
		for (int j = 0; j < e[i].size(); j++) {
			if (scc[i] == scc[e[i][j]]) {
				continue;
			}
			e1[scc[i]].push_back(scc[e[i][j]]);
			++ind[scc[e[i][j]]];
		}
	}
	// for (int i = 1; i <= sc; i++) {
	// 	cout << c1[i] << '\n';
	// 	for (int j = 0; j < e1[i].size(); j++) {
	// 		cout << i << ' ' << e1[i][j] << '\n';
	// 	}
	// }
	// for (int i = 1; i <= n; i++) cout << scc[i] << ' ';
	// cout << '\n';
	bool noa = false;
	for (int i = 1; i <= sc; i++) {
		if (c1[i] == 0x3f3f3f3f && ind[i] == 0) {
			//cout << sc << '\n';
			minn = min(id[i],minn);
			noa = true;
		}else if (c1[i] == 0x3f3f3f3f) {
			minn = min(id[i],minn);
		}
		if (ind[i] != 0) continue;
		ans += c1[i];
	}
	if (noa) cout << "NO" << '\n' << minn << '\n';
	else cout << "YES" << '\n' << ans << '\n';
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3+10;
int n,p,r,ans;
int c[3005],c1[3005],id[maxn];
vector<int> e[3005],e1[3005];
int dfn[maxn],low[maxn],cnt;
bool instk[maxn];
stack<int> s;
int sc,scc[maxn],ind[maxn],minn = 0x3f3f3f3f;
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
		++sc;
		while (!s.empty()) {
			scc[s.top()] = sc;
			instk[s.top()] = false;
			id[sc] = min(id[sc],s.top());
			c1[sc] = min(c1[sc],c[s.top()]);
			if (s.top() == u) {
				s.pop();
				break;
			}
			s.pop();
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	memset(c,0x3f,sizeof(c));
	memset(c1,0x3f,sizeof(c1));
	memset(id,0x3f,sizeof(id));
	cin >> n >> p;
	for (int i = 1; i <= p; i++) {
		int pt;
		cin >> pt;
		cin >> c[pt];
	}
	cin >> r;
	for (int i = 1; i <= r; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++) {
		// cout << c[i] << '\n';
		for (int j = 0; j < e[i].size(); j++) {
			if (scc[i] == scc[e[i][j]]) {
				continue;
			}
			e1[scc[i]].push_back(scc[e[i][j]]);
			++ind[scc[e[i][j]]];
		}
	}
	// for (int i = 1; i <= sc; i++) {
	// 	cout << c1[i] << '\n';
	// 	for (int j = 0; j < e1[i].size(); j++) {
	// 		cout << i << ' ' << e1[i][j] << '\n';
	// 	}
	// }
	// for (int i = 1; i <= n; i++) cout << scc[i] << ' ';
	// cout << '\n';
	bool noa = false;
	for (int i = 1; i <= sc; i++) {
		if (c1[i] == 0x3f3f3f3f && ind[i] == 0) {
			//cout << sc << '\n';
			minn = min(id[i],minn);
			noa = true;
		}else if (c1[i] == 0x3f3f3f3f) {
			minn = min(id[i],minn);
		}
		if (ind[i] != 0) continue;
		ans += c1[i];
	}
	if (noa) cout << "NO" << '\n' << minn << '\n';
	else cout << "YES" << '\n' << ans << '\n';
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}