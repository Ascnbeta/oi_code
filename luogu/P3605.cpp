#include <bits/stdc++.h>
using namespace std;
int n;
int p[100005],tmp[100005],ans[100005];
int t[100005];
struct edge{
	int to,nxt;
}e[200005];
int head[100005],tot;
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
inline int lowbit(int x){
	return x&-x;
}
inline void modify(int p,int x) {
	while (p <= n) {
		t[p] += x;
		p += lowbit(p);
	}
}
inline int query(int p) {
	int ret = 0;
	while (p > 0) {
		ret += t[p];
		p -= lowbit(p);
	}
	return ret;
}
void dfs(int u,int fa) {
	ans[u] -= query(n) - query(p[u]);
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v,u);
	}
	ans[u] += query(n) - query(p[u]);
	modify(p[u],1);
}
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i],tmp[i] = p[i];
	sort(tmp+1,tmp+n+1);
	for (int i = 1; i <= n; i++) {
		int l = 1,r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (tmp[mid] >= p[i]) {
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		p[i] = l;
	}
	// for (int i = 1; i <= n; i++) cout << p[i] << ' ';
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		add(i,x);
		add(x,i);
	}
	dfs(1,0);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}