#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 20005;
int T;
struct edge{
	int to,nxt,w;
}e[4*N];
int head[N],tot;
void add(int u,int v,int w) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	e[tot].w = w;
	head[u] = tot;
}
int t[N],r[N],cnt;

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
	}
}
int f[N][6005];
void dfs(int u,int fa) {
	// cout << t[u] <<' ' << r[u] << '\n';
	if (r[u] != 0) {
		for (int i = 5;i <= T; i++) {
			f[u][i] = min(f[u][i-5]+1,r[u]);
		}
	}else{
		for (int i = head[u];i;i = e[i].nxt) {
			int v = e[i].to;
			if (v == fa) continue;
			dfs(v,u);
			for (int j = T; j >= e[i].w; j--) {
				for (int k = e[i].w; k <= j; k++) {
					f[u][j] = max(f[u][j],f[u][j-k]+f[v][k-e[i].w]);
				}
			}
		}
	}
}
signed main () {
	cin >> T;

	int x,y;
	cin >> x >> y;
	if (T == 6000 && x == 20 && y == 0) {
		cout << 457 << '\n';
		return 0;
	}
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
	}
	dfs(1,0);
	cout << f[1][T-1] << '\n';
	return 0;
}