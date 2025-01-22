#include <bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
	int to,nxt,w;
}e[2000005],e1[2000005];
int head[1000005],head1[1000005],tot,tot1;
void add(int u,int v,int w){
	e[++tot].to = v;
	e[tot].w = w;
	e[tot].nxt = head[u];
	head[u] = tot;
}
void add1(int u,int v,int w){
	e1[++tot1].to = v;
	e1[tot1].w = w;
	e1[tot1].nxt = head1[u];
	head1[u] = tot1;
}
struct node{
	long long p,d;
};
bool operator < (const node x,const node y) {
	return x.d > y.d;
}
priority_queue<node> q;
long long dis[1000005],ans;
bool f[1000005];
void dij() {
	memset(dis,0x3f,sizeof(dis));
	memset(f,0,sizeof(f));
	dis[1] = 0;
	f[1] = true;
	q.push({1,0});
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		f[t.p] = true;
		for (int i = head[t.p];i; i = e[i].nxt) {
			int v = e[i].to;
			if (f[v]) continue;
			if (dis[t.p] + e[i].w < dis[v]) {
				dis[v] = dis[t.p] + e[i].w;
				q.push({v,dis[v]});
			}
		}
	}
}
void dij1() {
	memset(dis,0x3f,sizeof(dis));
	memset(f,0,sizeof(f));
	dis[1] = 0;
	f[1] = true;
	q.push({1,0});
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		f[t.p] = true;
		for (int i = head1[t.p];i; i = e1[i].nxt) {
			int v = e1[i].to;
			if (f[v]) continue;
			if (dis[t.p] + e1[i].w < dis[v]) {
				dis[v] = dis[t.p] + e1[i].w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		add(x,y,z);
		add1(y,x,z);
	}
	dij();
	for (int i = 2; i <= n; i++) {
		ans += dis[i];
	}
	dij1();
	for (int i = 2; i <= n; i++) {
		ans += dis[i];
	}
	cout << ans << '\n';
	return 0;
}