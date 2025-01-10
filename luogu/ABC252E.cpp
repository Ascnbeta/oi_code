#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+10;
int n,m;
struct edge{
	int to,nxt,w,num;
}e[maxn<<1];
int head[maxn],tot;
inline void add(int u,int v,int w,int num) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	e[tot].w = w;
	e[tot].num = num;
	head[u] = tot;
}
bool f[maxn];
int dis[maxn],ans[maxn];
struct node{
	int p,w;
	bool operator < (const node &x) const{
		return w > x.w;
	}
};
priority_queue<node> q;
inline void dij(int s) {
	q.push(node{s,0});
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		f[t.p] = true;
		for (int i = head[t.p]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (f[v]) continue;
			if (dis[v] > dis[t.p] + e[i].w) {
				dis[v] = dis[t.p] + e[i].w;
				q.push(node{v,dis[v]});
				ans[v] = e[i].num;
			}
		}
	}
}
signed main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		add(x,y,z,i);
		add(y,x,z,i);
	}
	dij(1);
	for (int i = 2; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}