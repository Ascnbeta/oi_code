#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2005;
int T;
struct edge{
	int to,nxt,w;
}e[4*N];
int head[N],tot;
vector<int> w[N],c[N];
void add(int u,int v,int w) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	e[tot].w = w;
	head[u] = tot;
}
int t[N],r[N],cnt;
int siz[N];
void dfsin(int pre) {
	int x,y;
	cin >> x >> y;
	++cnt;
	int id = cnt;
	add(pre,id,2*x);
	add(id,pre,2*x);
	if (y == 0) {
		dfsin(id);
		dfsin(id);
	}else{
		r[cnt] = y;
		for (int i = 1; i <= y; i++) {
			int p,q;
			cin >> p >> q;
			w[id].push_back(p),c[id].push_back(q);
		}
	}
}
int f[N][605];
void dfs(int u,int fa) {
	// cout << t[u] <<' ' << r[u] << '\n';
	if (r[u] != 0) {
		for (int i = 0; i < r[u]; i++) {
			for (int j = T; j >= c[u][i]; j--) {
				f[u][j] = max(f[u][j],f[u][j-c[u][i]]+w[u][i]);
			}
		}
	}else{
		for (int i = head[u];i;i = e[i].nxt) {
			int v = e[i].to;
			if (v == fa) continue;
			dfs(v,u);
			siz[u] += siz[v]+e[i].w;
			for (int j = T; j >= e[i].w; j--) {
				for (int k = e[i].w; k <= j; k++) {
					f[u][j] = max(f[u][j],f[u][j-k]+f[v][k-e[i].w]);
				}
			}
		}
	}
}
signed main () {
#ifdef LOCAL
	freopen("D:/codes/exe/a.in","r",stdin);
	freopen("D:/codes/exe/a.out","w",stdout);
#endif
	cin >> T;
	int x,y;
	cin >> x >> y;
	if (y == 0) {
		cnt = 2;
		add(1,2,x*2);
		add(2,1,x*2);
		dfsin(2);
		dfsin(2);
	}else{
		add(1,2,x*2);
		add(1,2,x*2);
		cnt = 2;
		r[2] = y;
		for (int i = 1; i <= y; i++) {
			int p,q;
			cin >> p >> q;
			w[2].push_back(p),c[2].push_back(q);
		}
	}
	dfs(1,0);
	cout << f[1][T-1] << '\n';
	return 0;
}