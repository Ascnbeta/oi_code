#include <bits/stdc++.h>
#define _for(i,a,b) for (int i = (a); i <= (b); ++i)
#define for_(i,a,b) for (int i = (a); i >= (b); --i)
#define far(i,vec) for (auto i : vec)
typedef unsigned long long ull;
typedef long double ldb;
typedef long long ll;
typedef double db;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
const int N = 5e5 + 10, P = 1e9 + 7;
namespace IO {
	int rnt () {
		int x = 0, w = 1; char c = getchar ();
		while (!isdigit (c)) { if (c == '-') w = -1; c = getchar (); }
		while (isdigit (c)) x = x * 10 + c - '0', c = getchar ();
		return x * w;
	}
}
namespace SOLVE {
	using namespace IO;
	int n, q, fa[N][20], dep[N];
	std::vector <int> T[N];
	int min[20][N];
	void DFS (int u) {
		dep[u] = dep[fa[u][0]] + 1;
		_for (k, 1, 19)
			fa[u][k] = fa[fa[u][k - 1]][k - 1];
		far (v, T[u]) if (v != fa[u][0])
			fa[v][0] = u, DFS (v);
		return;
	}
	int LCA (int u, int v) {
		for_ (k, 19, 0) if (dep[fa[u][k]] >= dep[v]) u = fa[u][k];
		for_ (k, 19, 0) if (dep[fa[v][k]] >= dep[u]) v = fa[v][k];
		for_ (k, 19, 0) if (fa[u][k] != fa[v][k]) u = fa[u][k], v = fa[v][k];
		return (u == v) ? u : fa[u][0];
	}
	int Que (int l, int r) {
		int k = std::__lg (r - l + 1);
		return std::min (min[k][l], min[k][r - (1 << k) + 1]);
	}
	void In () {
		n = rnt ();
		_for (i, 1, n - 1) {
			int u = rnt (), v = rnt ();
			T[u].emplace_back (v);
			T[v].emplace_back (u);
		}
		return;
	}
	void Solve () {
		DFS (1);
		memset (min, 0x3f, sizeof (min));
		_for (i, 1, n - 1) min[0][i] = dep[LCA (i, i + 1)];
		_for (k, 1, 19) {
			int len = 1 << (k - 1);
			_for (i, 1, n - len + 1)
				min[k][i] = std::min (min[k - 1][i], min[k - 1][i + len]);
		}
		return;
	}
	void Out () {
		q = rnt ();
		_for (i, 1, q) {
			int l = rnt (), r = rnt (), k = rnt () - 1, ans = 0;
			if (!k)
				_for (j, l, r)
					ans = std::max (ans, dep[j]);
			else {
				r = r - k;
				_for (j, l, r) ans = std::max (ans, Que (j, j + k - 1));
			}
			printf ("%d\n", ans);
		}
		return;
	}
}
int main () {
	freopen ("query.in", "r", stdin);
	freopen ("query.out", "w", stdout);
	SOLVE::In ();
	SOLVE::Solve ();
	SOLVE::Out ();
	return 0;
} /*

*/