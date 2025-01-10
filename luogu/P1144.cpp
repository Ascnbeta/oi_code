#include <bits/stdc++.h>
using namespace std;
const int mod = 100003;
int n,m;
struct edge{
	int to,nxt,w;
}e[4000006];
int head[1000006],tot;
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	e[tot].w = 1;
	head[u] = tot;
}
struct node{
	int p,d;
};
int dis[1000005],cnt[1000005];
bool operator < (node x,node y) {
	return x.d > y.d;
}
priority_queue<node> q;
void dij(int x) {
	memset(dis,0x3f,sizeof(dis));
	dis[x] = 0;
	cnt[x] = 1;
	q.push(node{x,0});
	while(!q.empty()) {
		node t = q.top();
		q.pop();
		for (int i = head[t.p];i;i = e[i].nxt) {
			int tmp = e[i].to;
			if (dis[tmp] > dis[t.p] + 1) {
				dis[tmp] = dis[t.p] + 1;
				cnt[tmp] = cnt[t.p];
				q.push(node{tmp,dis[tmp]});
			}else if (dis[tmp] == dis[t.p] + 1) {
				cnt[tmp] = (cnt[tmp] + cnt[t.p]) % mod;
			}
		}
	}
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	dij(1);
	for (int i = 1; i <= n; i++) cout << cnt[i] << '\n';
	return 0;
}