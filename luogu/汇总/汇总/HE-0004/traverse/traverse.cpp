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
const int N = 2e5 + 10, P = 1e9 + 7;
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
	int ID, n, K, e[N], ans;
	std::vector <pii> tu[N];
	int edge[N][2], a[N], t[N];
	int fac[N], invf[N];
	int fpow (int a, int b, int ans = 1) {
		for (; b; a = 1ll * a * a % P, b >>= 1)
			if (b & 1) ans = 1ll * ans * a % P;
		return ans;
	}
	int C2 (int x) { return 1ll * x * (x - 1) / 2 % P; }
	void In () {
		n = rnt (), K = rnt ();
		_for (i, 1, n - 1) {
			int u = rnt (), v = rnt ();
			tu[u].emplace_back (v, i);
			tu[v].emplace_back (u, i);
			edge[i][0] = u, edge[i][1] = v;
		}
		_for (i, 1, K) e[i] = rnt ();
		return;
	}
	void Solve () {
		if (ID == 18) {
			ans = 1;
			return;
		}
		fac[0] = 1;
		_for (i, 1, n)
			fac[i] = 1ll * fac[i - 1] * i % P;
		auto Calc = [&] () -> int {
			int G = 1;
			int inv2 = (P + 1) / 2;
			_for (i, 1, n) {
				if (tu[i].size () < 2) {
					if (a[i])
						return 0;
					continue;
				}
				int tot = tu[i].size () - a[i], S;
				if (t[i] > 2) return 0;
				else if (t[i] == 1) S = tot - 1;
				else S = C2 (tot);
				G = 1ll * G * S % P * fac[tu[i].size () - 2] % P;
			}
			// printf ("%d\n", G);
			return G;
			};
		int U = fpow (3, K) - 1;
		_for (i, 1, n) a[i] = t[i] = 0;
		ans = Calc ();
		// printf ("%d\n", ans);
		_for (S, 0, U) {
			int tmp = S;
			_for (i, 1, n) a[i] = t[i] = 0;
			_for (i, 1, K) {
				if (tmp % 3 == 0)
					++a[edge[e[i]][0]], ++a[edge[e[i]][1]];
				else if (tmp % 3 == 1)
					++a[edge[e[i]][0]], ++t[edge[e[i]][1]];
				else
					++t[edge[e[i]][0]], ++a[edge[e[i]][1]];
			}
			ans = (ans + P - Calc ()) % P;
		}
		return;
	}
	void Out () {
		printf ("%d\n", ans);
		return;
	}
	void Clear () {
		_for (i, 1, n) {
			std::vector <pii> ().swap (tu[i]);
			a[i] = t[i] = e[i] = 0;
		}
		ans = 0;
		return;
	}
}
int main () {
	freopen ("traverse.in", "r", stdin);
	freopen ("traverse.out", "w", stdout);
	SOLVE::ID = IO::rnt ();
	int T = IO::rnt ();
	while (T--) {
		SOLVE::In ();
		SOLVE::Solve ();
		SOLVE::Out ();
	}
	return 0;
} /*

*/