#include <bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
	int to,nxt,w;
}e[200005];
int head[100005],tot;
inline void add(int u,int v ,int w) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	e[tot].w = w;
	head[u] = tot;
}
struct node{
	int p,w;
	bool operator < (const node &x) const{
		return w > x.w;
	}
};
int dis1[100004],dis2[100004];
bool f[100004];
priority_queue<node> q;
inline void dij(int s) {
	memset(dis1,0x3f,sizeof(dis1));
	memset(dis2,0x3f,sizeof(dis2));
	dis1[s] = 0;
	q.push({s,0});
	while(!q.empty()) {
		node t = q.top();
		q.pop();
		for (int i = head[t.p]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (dis1[v]>dis1[t.p]+e[i].w) {
				dis2[v] = dis1[v];
				dis1[v] = dis1[t.p]+e[i].w;
				q.push({v,dis1[v]});
			}
			if(dis1[v]<dis1[t.p]+e[i].w&&dis2[v]>dis1[t.p]+e[i].w) {
				dis2[v] = dis1[t.p]+e[i].w;
				q.push({v,dis1[v]});
			}
			if(dis2[v]>dis2[t.p]+e[i].w) {
				dis2[v] = dis2[t.p]+e[i].w;
				q.push({v,dis1[v]});
			}
		}
	}
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	dij(1);
	cout << dis2[n] << '\n';
	return 0;
}