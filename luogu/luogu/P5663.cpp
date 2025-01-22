#include <bits/stdc++.h>
using namespace std;
int n,m,Q;
struct edge{
	int to,nxt,w;
}e[200005];
int head[100005],tot;
inline void add(int u,int v,int w) {
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
int dis[100005][2],f[100005][2];//把一个点的奇偶分开，可以理解为两个点。
priority_queue<node> q;
inline void dij(int s) {
	q.push({s,0});
	memset(dis,0x3f,sizeof(dis));
	dis[1][0]=0;//注意初始化只有偶最短路，自己到达自己路径长度为 0，因此只用初始化偶最短路。
	while(!q.empty()) {
		node t = q.top();
		q.pop();
		if (f[t.p][t.w%2]) continue;
		f[t.p][t.w%2] = 1;
		for (int i = head[t.p]; i; i = e[i].nxt) {
			int v = e[i].to,w = t.w+e[i].w;
			if (dis[v][w%2]>w) {
				dis[v][w%2] = w;
				q.push({v,w});
			}else if(dis[v][w%2]>w) {
				dis[v][w%2] = w;
				q.push({v,w});
			}
		}
	}
}
int main () {
	cin >> n >> m >> Q;
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		add(u,v,1);
		add(v,u,1);//双向边
	}
	dij(1);
	// for (int i = 1; i <= n; i++) {
	// 	cout << dis[i][0] << ' ' << dis[i][1] << '\n'; 
	// }
	while(Q--) {
		int u,v;
		cin >> u >> v;
		if (dis[u][v%2] <= v) {//最短路如果大于 v 则一定不需要，因为在路径中途 v 就会减为 0。
			puts("Yes");
		}else{
			puts("No");
		}
	}
	return 0;
}