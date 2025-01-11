#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct edge{
	int to,nxt,w;
}e[10005];
int head[1004],tot;
inline void add(int u,int v,int w) {
	e[++tot].to = v;
	e[tot].w = w;
	e[tot].nxt = head[u];
	head[u] = tot;
}
queue<int> q;
bool f[1004];
int dis[1004],cnt[1004];
inline void spfa(int s) {
	q.push(s);
	f[s] = true;
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(f,0,sizeof(f));
	f[s] = true;
	dis[s] = 0;
	cnt[s] = 0;
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		f[p] = false;
		if (cnt[p] > n-1) {
			puts("Forever love");
			exit(0);
		}
		for (int i = head[p]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (dis[v]>dis[p]+e[i].w) {
				dis[v]=dis[p]+e[i].w;
				cnt[v]++;
				if (!f[v]) {
					q.push(v);
					f[v] = true;
				}
			}
		}
	}
}
signed main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,-w);
	}
	spfa(1);
	int t1 = dis[n];
	spfa(n);
	cout << min(t1,dis[n]) << '\n';
	return 0;
}