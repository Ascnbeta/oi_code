#include <bits/stdc++.h>
using namespace std;
int n,m,r;
struct egde{
	int to,nxt;
}e[2000005];
int head[1000005],tot;
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int d[1000005],lca[1000005];
bool vis[1000005];
sturct node{
	int p,l;
};
queue<node> q;
void bfs(int x) {
	lca[x] = x;
	q.push(node{x,0});
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		vis[t.p] = true;
		d[t.p] = t.l;
		for (int i = head[t.p];i;i = e[i].to) {
			if (vis[e[i].to]) continue;
			q.push(node{e[i].to,t.l+1});
			lca[e[i].to] = t.p;
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= m; i++) {
		int x,y;
		add(x,y);
		add(y,x);
	}
	bfs(r);
	cout << "I'm here!" << '\n';
	cin >> q;
	while (q--) {
		int x,y;
		cin >> x >> y;
		if (d[x] < d[y]) {
			cout << "Terry" << '\n';
		}else if (d[x] > d[y]) {
			cout << "Jom" << '\n';
		}else{
			if (lca[x] == r) {
				cout << "Terry" << '\n';
			}else{
				
			}
		}
	}
	return 0;
}