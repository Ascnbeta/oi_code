#include <bits/stdc++.h>
using namespace std;
int n;
struct edge{
	int to,nxt;
}e[100005];
int head[100006],tot,d[100006];
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int root,ans;
int maxx[100004],minn[100004],cnt[100004];
void dfs(int p) {
	maxx[p] = minn[p] = p;
	cnt[p] = 1;
	for (int i = head[p];i;i = e[i].nxt) {
		dfs(e[i].to);
		maxx[p] = max(maxx[p],maxx[e[i].to]);
		minn[p] = min(minn[p],minn[e[i].to]);
		cnt[p] += cnt[e[i].to];
	}
	if (maxx[p]-minn[p]+1 == cnt[p]) ++ans;
	return;
}
int main () {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int x,y;
		cin >> x >> y;
		add(x,y);
		++d[y];
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) {
			root = i;
			break;
		}
	}
	dfs(root);
	cout << ans << '\n';
	return 0;
}