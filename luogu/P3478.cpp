#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6+40;
template <typename T>
inline void read(T &x) {
	x=0;int f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
int n;
vector<int> e[maxn];
ll f[maxn],siz[maxn];
void dfs1(int u,int fa) {
	f[u] = 0;
	siz[u] = 1;
	for (auto v : e[u]) {
		if (v == fa) continue;
		dfs1(v,u);
		f[u] += f[v]+siz[v];
		siz[u] += siz[v];
	}
}
int ans;
void dfs2(int u,int fa) {
	if (f[u] > f[ans]) ans = u;
	for (auto v : e[u]) {
		if (v == fa) continue;
		f[v] += f[u]-(f[v]+siz[v])+n-siz[v];
		dfs2(v,u);
	}
}
int main () {
	read(n);
	for (int i = 1; i < n; i++) {
		int u,v;
		read(u),read(v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);
//	for (int i = 1; i <= n; i++) cout << f[i] << ' ';
//	cout << '\n';
	dfs2(1,0);
//	for (int i = 1; i <= n; i++) cout << f[i] << ' ';
//	cout << '\n';
	printf("%d",ans);
	return 0;
}