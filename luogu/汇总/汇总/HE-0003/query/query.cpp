#include <cstdio>
#include <algorithm>
using namespace std;
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
	int v, t;
}e[1000050];
int n, m, c, _, b[1000050], d[1000050], s[1000050], h[1000050], f[23][1000050], g[23][1000050], p[1000050][23];
void A(int u, int v) {e[++c] = {v, h[u]}, h[u] = c;}
void D(int u, int k)
{
	f[0][u] = g[0][u] = u, b[u] = ++_;
	for(int i = h[u], v;i;i = e[i].t)
		if((v = e[i].v) != k)
		{
			d[v] = d[p[v][0] = u] + 1;
			for(int j = 1;p[v][j - 1];++j)
				p[v][j] = p[p[v][j - 1]][j - 1];
			D(v, u), s[u] += s[v];
		}
}
int L(int x, int y)
{
	if(d[x] < d[y])
		swap(x, y);
	while(d[x] > d[y])
		x = p[x][__lg(d[x] - d[y])];
	if(x == y)
		return x;
	for(int k = __lg(n);k >= 0;--k)
		if(p[x][k] != p[y][k])
			x = p[x][k], y = p[y][k];
	return p[x][0];
}
int QF(int l, int r)
{
	int k = __lg(r - l + 1);
	return b[f[k][l]] < b[f[k][r - (1 << k) + 1]] ? f[k][l] : f[k][r - (1 << k) + 1];
}
int QG(int l, int r)
{
	int k = __lg(r - l + 1);
	return b[g[k][l]] > b[g[k][r - (1 << k) + 1]] ? g[k][l] : g[k][r - (1 << k) + 1];
}
int Q(int l, int r)
{
	return L(QF(l, r), QG(l, r));
}
int main()
{
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	n = I();
	for(int i = 1, u, v;i < n;++i)
		u = I(), v = I(), A(u, v), A(v, u);
	D(d[1] = 1, 0);
	for(int j = 1;1 << j <= n;++j)
		for(int i = 1;i + (1 << j) - 1 <= n;++i)
		{
			f[j][i] = b[f[j - 1][i]] < b[f[j - 1][i + (1 << j - 1)]] ? f[j - 1][i] : f[j - 1][i + (1 << j - 1)];
			g[j][i] = b[g[j - 1][i]] > b[g[j - 1][i + (1 << j - 1)]] ? g[j - 1][i] : g[j - 1][i + (1 << j - 1)];
		}
	m = I();
	for(int i = 0, l, r, k;i < m;++i)
	{
		l = I(), r = I(), k = I();
		int z = 0;
		for(int j = l;j + k - 1 <= r;++j)
			z = max(z, d[Q(j, j + k - 1)]);
		printf("%d\n", z);
	}
	return 0;
}
