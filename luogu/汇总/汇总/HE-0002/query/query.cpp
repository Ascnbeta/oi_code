#include <bits/stdc++.h>
#define filein(x) freopen(x".in", "r", stdin);
#define file(x) {freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);}
using namespace std; // my guiding star.
const int N = 1e6 + 233;
int n, q, e[N], id[N], dep[N], cc;
vector<int> g[N];
inline void addedge(int u, int v){g[u].emplace_back(v);}
inline void ade(int u, int v){addedge(u, v); addedge(v, u);}
struct STA
{
	static const int _ = __lg(N) + 5;
	int f[_][N];
	inline void init(int n)
	{
		for (int i=1; i<=n; i++) f[0][i] = dep[e[i]];
		for (int b=1; (1<<b)<=n; b++)
			for (int i=1; i+(1<<b)-1<=n; i++) f[b][i] = min(f[b-1][i], f[b-1][i+(1<<(b-1))]);
	}
	inline int query(int l, int r){int b = __lg(r - l + 1); return min(f[b][l], f[b][r-(1<<b)+1]);}
}T1;
struct STB
{
	static const int _ = __lg(N) + 5;
	int f[_][N];
	inline void init(int n)
	{
		for (int i=1; i<=n; i++) f[0][i] = id[i];
		for (int b=1; (1<<b)<=n; b++)
			for (int i=1; i+(1<<b)-1<=n; i++) f[b][i] = min(f[b-1][i], f[b-1][i+(1<<(b-1))]);
	}
	inline int query(int l, int r){int b = __lg(r - l + 1); return min(f[b][l], f[b][r-(1<<b)+1]);}
}T2;
struct STC
{
	static const int _ = __lg(N) + 5;
	int f[_][N];
	inline void init(int n)
	{
		for (int i=1; i<=n; i++) f[0][i] = id[i];
		for (int b=1; (1<<b)<=n; b++)
			for (int i=1; i+(1<<b)-1<=n; i++) f[b][i] = max(f[b-1][i], f[b-1][i+(1<<(b-1))]);
	}
	inline int query(int l, int r){int b = __lg(r - l + 1); return max(f[b][l], f[b][r-(1<<b)+1]);}
}T3;
void dfs(int u, int fa)
{
	e[id[u] = ++cc] = u; dep[u] = dep[fa] + 1;
	for (int v : g[u])
		if (v != fa) dfs(v, u),
	e[++cc] = u;
}
int main()
{
	file("query");
	scanf("%d", &n);
	for (int i=1, u, v; i<n; i++) scanf("%d%d", &u, &v), ade(u, v);
	dfs(1, 0); T1.init(cc); T2.init(cc); T3.init(cc); int l, r, k;
	auto LCA = [&](int l, int r){return T1.query(T2.query(l, r), T3.query(l, r));};
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%d%d", &l, &r, &k);
		int ans = 0;
		for (int i=l; i<=r-k+1; i++) ans = max(ans, LCA(i, i+k-1));
		printf("%d\n", ans);
	}
	return 0;
}
