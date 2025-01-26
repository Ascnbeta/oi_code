#include <bits/stdc++.h>
using namespace std;
int n,m,s;
struct edge{
    int to,nxt;
}e[1000005];
int tot,head[500004],d[500004];
void add(int u,int v) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot;
}
int el[1000004],fi[500004],st[1000004][40],cnt;
void dfs(int x,int p) {
    d[x] = d[p] + 1;
    el[++cnt] = x;
    fi[x] = cnt;
    for (int i = head[x];i;i = e[i].nxt) {
        if (e[i].to == p) continue;
        dfs(e[i].to,x);
        el[++cnt] = x;
    }
}
int Min(int x,int y) {
	if (d[x] > d[y]) return y;
	else return x;
}
void pre() {
	for (int i = 1; i <= cnt; i++) {
		st[i][0] = el[i];
	}
    for (int i = 1; (1<<i) <= cnt; i++) {
    	for (int j = 1; j+(1<<i)-1 <= cnt; j++) {
    		st[j][i] = Min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
    	}
    }
}
int query(int l, int r) {
    l = fi[l],r = fi[r];
	if (l < r) swap(l,r);
	int j = log2(r-l+1);
	return Min(st[l][j],st[r-(1<<j)+1][j]);
}
int main () {
    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i++) {
        int x,y;
        cin >> x >> y;
        add(x,y);
        add(y,x);
    }
    dfs(s,0);
    pre();
    while (m--) {
        int x,y;
        cin >> x >> y;
        cout << query(x,y) << '\n';
    }
    return 0;
}