#include <bits/stdc++.h>
using namespace std;
int n;
int c[200005];
map<pair<int,int>,int> m;
struct edge{
	int to,nxt;
}e[400005];
int head[200005],tot;
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int f[200005][2],ans;
void dfs(int u,int fa) {
	for (int i = head[u];i;i = e[i].nxt) {
		if (e[i].to == fa) continue;
		int v = e[i].to;
		dfs(v,u);
		if (f[v][0]+1>f[u][0]) {
			f[u][1] = f[u][0];
			f[u][0] = f[v][0]+1;
		}else{
			f[u][1] = max(f[u][1],f[v][0]+1);
		}
	}
	ans = max(f[u][1]+f[u][0],ans);
}
int main () {
	cin >> n;
	for (int i = 1; i <= n - 2; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		if (a > b) swap(a,b);
		if (b > c) swap(b,c);
		if (a > b) swap(a,b);
		auto x = m.find(make_pair(a,b)),y = m.find(make_pair(b,c)),z = m.find(make_pair(a,c));
		if (x != m.end()) {
			add((*x).second,i);
			add(i,(*x).second);
		}else{
			m.insert(make_pair(make_pair(a,b),i));
		}
		if (y != m.end()) {
			add((*y).second,i);
			add(i,(*y).second);
		}else{
			m.insert(make_pair(make_pair(b,c),i));
		}
		if (z != m.end()) {
			add((*z).second,i);
			add(i,(*z).second);
		}else{
			m.insert(make_pair(make_pair(a,c),i));
		}
	}
	dfs(1,0);
	cout << ans + 1 << '\n';
	return 0;
}