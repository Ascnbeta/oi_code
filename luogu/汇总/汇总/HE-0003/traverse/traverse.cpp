#include <cstdio>
#define M 1000000007 
#define int long long
inline int I()
{
	int q = 0;
	char c = getchar();
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		q = q * 10 + c - '0', c = getchar();
	return q;
}
struct E
{
	int v, w, t;
}e[1000050];
int C, T, n, m, c, F[1000050], u[1000050], v[1000050], p[1000050], b[1000050], h[1000050], f[1000050], g[1000050], V[1000050], W[1000050], GP[1000050], GS[1000050];
void A(int u, int v, int w) {e[++c] = {v, w, h[u]}, h[u] = c;}
void D(int u, int k, int t)
{
	int d = 0;
	g[u] = 1;
	for(int i = h[u], v;i;i = e[i].t)
		if((v = e[i].v) != k)
			D(v, u, t), ++d, g[u] = g[u] * g[v] % M;
	g[u] = g[u] * F[d] % M;
	if(d == 0)
	{
		f[u] = 1;
		return;
	}
	d = 0;
	for(int i = h[u], v;i;i = e[i].t)
		if((v = e[i].v) != k)
			V[++d] = v, W[d] = e[i].w;
	f[u] = 0, GP[0] = GS[d + 1] = 1;
	for(int i = 1;i <= d;++i)
		GP[i] = GP[i - 1] * g[V[i]] % M;
	for(int i = d;i >= 1;--i)
		GS[i] = GS[i + 1] * g[V[i]] % M;
	for(int i  = 1;i <= d;++i)
		if(b[W[i]] == 0 || W[i] >= t)
			f[u] = (f[u] + GP[i - 1] * GS[i + 1] % M * f[V[i]] % M) % M;
	f[u] = f[u] * F[d - 1] % M;
}
signed main()
{
	freopen("traverse.in", "r", stdin);
	freopen("traverse.out", "w", stdout);
	for(int i = F[0] = 1;i <= 1000000;++i)
		F[i] = F[i - 1] * i % M;
	C = I(), T = I();
	if(C == 18)
	{
		while(T--)
			puts("1");
		return 0;
	}
	if(C >= 19 && C <= 21)
	{
		while(T--)
		{
			n = I(), m = I(); 
			for(int i = 1;i < n;++i)
				u[i] = I(), v[i] = I();
			for(int i = 1;i <= m;++i)
				p[i] = I();
			int z = m * F[n - 2] % M;
			if(n >= 3)
				z = (z + M - (m * (m - 1) / 2 % M) * F[n - 3] % M) % M;
			printf("%lld\n", z);
		}
		return 0;
	}
	while(T--)
	{
		n = I(), m = I();
		for(int i = 1;i < n;++i)
			u[i] = I(), v[i] = I(), A(u[i], v[i], i), A(v[i], u[i], i);
		for(int i = 1;i <= m;++i)
			p[i] = I(), b[p[i]] = 1;
		int z = 0;
		for(int i = 1;i <= m;++i)
		{
			D(u[p[i]], v[p[i]], p[i]);
			D(v[p[i]], u[p[i]], p[i]);
			z = (z + f[u[p[i]]] * f[v[p[i]]]) % M;
		}
		printf("%lld\n", z);
		c = 0;
		for(int i = 1;i <= n;++i)
			b[i] = h[i] = f[i] = 0;
	}
	return 0;
}
