<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+10;
const int maxm = 1e5+6;
int n,m,ans;
vector<int> e[maxn];
int dfn[maxn],low[maxn];
bool vis[maxn],f[maxn];
int cnt;
void tarjan(int u,int fa) {
	dfn[u] = low[u] = ++cnt;
	vis[u] = true;
	int num = 0;
	for (const auto &v : e[u]) {
		if (!vis[v]) {
			++num;
			tarjan(v,u);
			low[u] = min(low[v],low[u]);
			if (fa != 0 && low[v] >= dfn[u] && !f[u]) {
				++ans;
				f[u] = true;
			}
		}else if(v != fa){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if (0 == fa && num >= 2 && !f[u]) {
		++ans;
		f[u] = true;
	}
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			cnt = 0;
			tarjan(i,0);
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		if (f[i]) cout << i << ' ';
	}
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+10;
const int maxm = 1e5+6;
int n,m,ans;
vector<int> e[maxn];
int dfn[maxn],low[maxn];
bool vis[maxn],f[maxn];
int cnt;
void tarjan(int u,int fa) {
	dfn[u] = low[u] = ++cnt;
	vis[u] = true;
	int num = 0;
	for (const auto &v : e[u]) {
		if (!vis[v]) {
			++num;
			tarjan(v,u);
			low[u] = min(low[v],low[u]);
			if (fa != 0 && low[v] >= dfn[u] && !f[u]) {
				++ans;
				f[u] = true;
			}
		}else if(v != fa){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if (0 == fa && num >= 2 && !f[u]) {
		++ans;
		f[u] = true;
	}
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			cnt = 0;
			tarjan(i,0);
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		if (f[i]) cout << i << ' ';
	}
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}