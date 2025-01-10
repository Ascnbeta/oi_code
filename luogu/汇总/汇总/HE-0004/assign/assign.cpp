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
namespace MATRIX {
	class Matrix {
	private:
		std::array <std::array <int, 2>, 2> a;

	public:
		Matrix () { far (&b, a) b.fill (0); }
		std::array <int, 2>& operator [] (int i) { return a[i]; }
		friend Matrix operator * (Matrix a, Matrix b) {
			Matrix c;
			_for (i, 0, 1) _for (k, 0, 1) _for (j, 0, 1)
				c[i][j] = (c[i][j] + 1ll * a[i][k] * b[k][j]) % P;
			return c;
		}
		friend Matrix operator ^ (Matrix a, int b) {
			Matrix ans;
			ans[0][0] = ans[1][1] = 1;
			ans[0][1] = ans[1][0] = 0;
			for (; b; a = a * a, b >>= 1)
				if (b & 1) ans = ans * a;
			return ans;
		}
	};
}
namespace SOLVE {
	using namespace IO;
	using namespace MATRIX;
	int n, m, v, c[N], d[N], ans;
	Matrix F, A, B, C, D;
	void In () {
		n = rnt (), m = rnt (), v = rnt ();
		_for (i, 1, m)
			c[i] = rnt (), d[i] = rnt ();
		return;
	}
	void Solve () {
		std::map <int, int> vis;
		_for (i, 1, m) {
			if (vis.count (c[i]) && vis[c[i]] != d[i])
				{ ans = 0; return; }
			vis[c[i]] = d[i];
		}
		// A : vis[i] && vis[i + 1]
		A[0][0] = A[1][0] = 1ll * (v - 1) * v % P;
		A[0][1] = A[1][1] = 1;
		// B : vis[i] && !vis[i + 1]
		B[0][0] = B[1][0] = 1ll * (v - 1) * v % P;
		B[0][1] = B[1][1] = v;
		// C : !vis[i] && vis[i + 1]
		C[0][0] = 1ll * v * v % P;
		C[1][0] = 1ll * (v - 1) * v % P;
		C[0][1] = 0, C[1][1] = 1;
		// D : !vis[i] && !vis[i + 1]
		D[0][0] = 1ll * v * v % P;
		D[1][0] = 1ll * (v - 1) * v % P;
		D[0][1] = 0, D[1][1] = v;

		F[0][0] = 1, F[0][1] = 0;
		int la = 0;
		far (p, vis) {
			int i = p.first;
			if (la) {
				if (la + 1 == i)
					F = F * A;
				else
					F = F * B * (D ^ (i - la - 2)) * C;
			}
			else if (i > 1)
				F = F * (D ^ (i - 2)) * C;
			la = i;
		}
		if (la < n)
			F = F * B * (D ^ (n - la - 1));
		ans = (F[0][0] + F[0][1]) % P;
		return;
	}
	void Out () {
		printf ("%d\n", ans);
		return;
	}
}
int main () {
	freopen ("assign.in", "r", stdin);
	freopen ("assign.out", "w", stdout);
	int T = IO::rnt ();
	while (T--) {
		SOLVE::In ();
		SOLVE::Solve ();
		SOLVE::Out ();
	}
	return 0;
} /*

*/