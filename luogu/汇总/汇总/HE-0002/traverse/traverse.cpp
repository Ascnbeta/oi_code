#include <bits/stdc++.h>
#define filein(x) freopen(x".in", "r", stdin);
#define file(x) {freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);}
using namespace std; // my guiding star.
const int N = 1e5 + 233, P = 1000000007;
int n, q, u[N], v[N], fac[N];
vector<int> g[N];
inline void addedge(int u, int v){g[u].emplace_back(v);}
inline void ade(int u, int v){addedge(u, v); addedge(v, u);}
inline void init(int n)
{
	fac[0] = 1;
	for (int i=1; i<=n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
}
int dfs(int u, int fa)
{
	if (g[u].size() == 1) return 1;
	int ans = fac[g[u].size() - 1];
	for (int v : g[u])
		if (v != fa) ans = 1ll * ans * dfs(v, u) % P;
	return ans;
}
int main()
{
	file("traverse");
	int c, T; scanf("%d%d", &c, &T); init(1e5);
	while (T--)
	{
		scanf("%d%d", &n, &q);
		for (int i=1; i<n; i++) scanf("%d%d", u+i, v+i), ade(u[i], v[i]);
		if (q == 1)
		{
			scanf("%d", &q);
			printf("%lld\n", 1ll * dfs(u[q], v[q]) * dfs(v[q], u[q]) % P);
		}
		else
		{
			printf("%d\n", 1); // chain
		}
		for (int i=1; i<=n; i++) g[i].clear();
	}
	return 0;
}
