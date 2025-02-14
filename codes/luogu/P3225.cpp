<<<<<<< HEAD
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1003;
int n,t_n;
vector<int> e[maxn];
int dfn[maxn],low[maxn],cnt,num;
bool f[maxn];
int vis[maxn],size;
inline void init() {
	for (int i = 1; i <= maxn-1; i++) dfn[i] = low[i] = 0,e[i].clear(),f[i] = false,vis[i] = false;
	size = cnt = num = t_n = 0;
}
void tarjan(int u,int fa) {
	dfn[u] = low[u] = ++cnt;
	int ccnt = 0;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (!dfn[v]) {
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			++ccnt;
			if (low[v] >= dfn[u] && !f[u] && u != fa) {
				++num;
				f[u] = true;
			}
		}else if (v != fa) low[u] = min(low[u],dfn[v]);
	}
	if (u == fa && ccnt >= 2 && !f[u]) {
		++num;
		f[u] = true;
	}
}
int calc[maxn];
inline int C(int n, int m) {
	return calc[n] / (calc[m]*calc[n-m]);
}
void dfs(int u,int p) {
	vis[u] = p;
	++size;
	for (const auto &v : e[u]) {
		if (vis[v] == p) continue;
		if (f[v]) {
			++cnt,vis[v] = p;
			continue;
		}
		dfs(v,p);
	}
}
signed main () {
	int t = 0;
	calc[0] = 1;
	for (int i = 1; i <= maxn-1; i++) calc[i] = i*(i-1)/2;
	while (1) {
		++t;
		cin >> n;
		if (n == 0) return 0;
		init();
		for (int i = 1; i <= n; i++) {
			int u,v;
			cin >> u >> v;
			t_n = max(t_n,max(u,v));
			e[u].push_back(v);
			e[v].push_back(u);
		}
		tarjan(1,1);
		//cout << "debug: " << num << '\n';
		if (num == 0) {
			printf("Case %lld: 2 %lld\n",t,max(calc[t_n],1ll));
		}else{
			int pt = 0,ans1 = 0,ans2 = 1;
			for (int i = 1; i <= 500; i++) {
				if (!vis[i] && !f[i]) {
					cnt = size = 0,++pt;
					dfs(i,pt);
					if (cnt == 1) ans1 += 1,ans2 *= size;
				}
			}
			printf("Case %lld: %lld %lld\n",t,ans1,ans2);
		}
	}
	return 0;
=======
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1003;
int n,t_n;
vector<int> e[maxn];
int dfn[maxn],low[maxn],cnt,num;
bool f[maxn];
int vis[maxn],size;
inline void init() {
	for (int i = 1; i <= maxn-1; i++) dfn[i] = low[i] = 0,e[i].clear(),f[i] = false,vis[i] = false;
	size = cnt = num = t_n = 0;
}
void tarjan(int u,int fa) {
	dfn[u] = low[u] = ++cnt;
	int ccnt = 0;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (!dfn[v]) {
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			++ccnt;
			if (low[v] >= dfn[u] && !f[u] && u != fa) {
				++num;
				f[u] = true;
			}
		}else if (v != fa) low[u] = min(low[u],dfn[v]);
	}
	if (u == fa && ccnt >= 2 && !f[u]) {
		++num;
		f[u] = true;
	}
}
int calc[maxn];
inline int C(int n, int m) {
	return calc[n] / (calc[m]*calc[n-m]);
}
void dfs(int u,int p) {
	vis[u] = p;
	++size;
	for (const auto &v : e[u]) {
		if (vis[v] == p) continue;
		if (f[v]) {
			++cnt,vis[v] = p;
			continue;
		}
		dfs(v,p);
	}
}
signed main () {
	int t = 0;
	calc[0] = 1;
	for (int i = 1; i <= maxn-1; i++) calc[i] = i*(i-1)/2;
	while (1) {
		++t;
		cin >> n;
		if (n == 0) return 0;
		init();
		for (int i = 1; i <= n; i++) {
			int u,v;
			cin >> u >> v;
			t_n = max(t_n,max(u,v));
			e[u].push_back(v);
			e[v].push_back(u);
		}
		tarjan(1,1);
		//cout << "debug: " << num << '\n';
		if (num == 0) {
			printf("Case %lld: 2 %lld\n",t,max(calc[t_n],1ll));
		}else{
			int pt = 0,ans1 = 0,ans2 = 1;
			for (int i = 1; i <= 500; i++) {
				if (!vis[i] && !f[i]) {
					cnt = size = 0,++pt;
					dfs(i,pt);
					if (cnt == 1) ans1 += 1,ans2 *= size;
				}
			}
			printf("Case %lld: %lld %lld\n",t,ans1,ans2);
		}
	}
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}