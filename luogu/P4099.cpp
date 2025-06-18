#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e3+40;
const ll mod = 1e9+7;
int T,n;
inline void read(int &x) {
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
vector<int> e[maxn],tp[maxn];
ll f[maxn][maxn],g[maxn];int siz[maxn];
ll c[maxn][maxn];
void dfs(int u,int fa) {
	f[u][1] = 1;siz[u] = 1;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (v == fa) continue;
		dfs(v,u);
		memcpy(g,f[u],sizeof(f[u]));
		memset(f[u],0,sizeof(f[u]));
		if (tp[u][i]) {
			for (int p1 = 1; p1 <= siz[u]; p1++) {
				for (int p3 = p1; p3 <= p1+siz[v]-1; p3++) {
					f[u][p3] = (f[u][p3]+c[p3-1][p1-1]*c[siz[u]+siz[v]-p3][siz[u]-p1]%mod*g[p1]%mod*(f[v][siz[v]]-f[v][p3-p1]+mod)%mod)%mod;
 				}
			}
		}else{
			for (int p1 = 1; p1 <= siz[u]; p1++) {
				for (int p3 = p1+1; p3 <= p1+siz[v]; p3++) {
					f[u][p3] = (f[u][p3]+c[p3-1][p1-1]*c[siz[u]+siz[v]-p3][siz[u]-p1]%mod*g[p1]%mod*(f[v][p3-p1]-f[v][0]+mod)%mod)%mod;
				}
			}
		}
		siz[u] += siz[v];
	}
	for (int i = 1; i <= siz[u]; i++) f[u][i] = (f[u][i-1]+f[u][i])%mod;
}
int main () {
	read(T);
	c[1][0] = c[0][0] = 1;
	for (int i = 1; i <= 1000; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	while (T--) {
		read(n);
		memset(f,0,sizeof(f));
		for (int i = 1; i <= n; i++) e[i].clear(),tp[i].clear();
		for (int i = 1; i < n; i++) {
			int u,v;char ch;
			read(u),ch=getchar(),read(v);++u,++v;
			if (ch=='<') {
				e[u].push_back(v);
				tp[u].push_back(1);
				e[v].push_back(u);
				tp[v].push_back(0);
			}else if(ch=='>'){
				e[u].push_back(v);
				tp[u].push_back(0);
				e[v].push_back(u);
				tp[v].push_back(1);
			}else{
				assert(0);
			}
		}
		dfs(1,0);
//		for (int i = 1; i <= n; i++) {
//			cout << f[i][1] << ' ';
//		}
//		cout << '\n';
		printf("%lld\n",f[1][n]);
	}
	return 0;
}