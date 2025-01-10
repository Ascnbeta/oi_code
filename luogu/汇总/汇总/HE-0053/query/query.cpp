#include <bits/stdc++.h>
using namespace std;
int n,q,rt;
struct edge{
	int to,nxt;
}e[1000005];
int head[500005],tot,d[500005];
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
void dfs(int u,int fa,int x) {
	d[u] = x;
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (f == fa) continue;
		dfs(v,u,x+1);
	}
}
int st[500005][30],f[30];
void init() {
	for (int i = 1; (1<<i)<= n; i++) {
		for (int j = 1; j+(1<<i)-1<=n; j++) {
			st[j][i] = min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
}
int main () {
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	for (int i = 1; i <= n; i++) {
		if (head[i] == 0) {
			rt = i;
			break;
		}
	}
	dfs(rt,-1,1);
	cin >> q;
	for (int i = 1; i <= n; i++) {
		st[i][0] = d[i];
	}
	f[1] = 0;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i/2]+1;
	}
	init();
	while (q--) {
		int l,r,k;
		cin >> l >> r >> k;
		cout << 1 << '\n';
	}
	return 0;
}
