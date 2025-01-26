#include <bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
	int to,nxt;
}e[400005];
int head[200005],tot;
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int c[200005],c1,c2,ans1,ans2;
struct node{
	int p,c;
};
queue<node> q;
void bfs(int s) {
	q.push({s,1});
	while(!q.empty()) {
		node t = q.front();
		q.pop();
		for (int i = head[t.p];i;i = e[i].nxt) {
			int v = e[i].to;
			if (c[v]) continue;
			if (t.c == 1) c[v] = 2,++c2;
			else c[v] = 1,++c1;
			q.push({v,c[v]});
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
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) {
			c1 = c2 = 0;
			c[i] = 1;
			c1 = 1;
			bfs(i);
			ans1 += min(c1,c2);
			ans2 += max(c1,c2);
		}
	}
	cout << ans1 << ' ' << ans2 << '\n';
	return 0;
}