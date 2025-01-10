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
	int n, X[2], Y[2], F[2][N][2], ans;
	char S[2][N], T[2][N];
	void In () {
		n = rnt ();
		scanf ("%s", S[0] + 1);
		scanf ("%s", S[1] + 1);
		scanf ("%s", T[0] + 1);
		scanf ("%s", T[1] + 1);
		return;
	}
	void Solve () {
		int L0 = 1, L1 = 1;
		_for (i, 1, n) {
			F[0][i][0] = F[0][i][1] = 0;
			F[1][i][0] = F[1][i][1] = 0;
		}
		_for (i, 1, n) {
			S[0][i] -= '0', S[1][i] -= '0';
			T[0][i] -= '0', T[1][i] -= '0';
			if (!T[0][i] || !T[0][i - 1]) L0 = i;
			if (!T[1][i] || !T[1][i - 1]) L1 = i;
			++F[0][L0][S[0][i]];
			++F[1][L1][S[1][i]];
		}
		ans = 0;
		X[0] = Y[0] = 0;
		X[1] = Y[1] = 0;
		_for (i, 1, n) {
			if (!T[0][i] || !T[0][i - 1]) X[0] = F[0][i][0], Y[0] = F[0][i][1];
			if (!T[1][i] || !T[1][i - 1]) X[1] = F[1][i][0], Y[1] = F[1][i][1];
			if (X[0] && X[1]) ++ans, --X[0], --X[1];
			else if (Y[0] && Y[1]) ++ans, --Y[0], --Y[1];
		}
		return;
	}
	void Out () {
		printf ("%d\n", ans);
		return;
	}
}
int main () {
	freopen ("edit.in", "r", stdin);
	freopen ("edit.out", "w", stdout);
	int T = IO::rnt ();
	while (T--) {
		SOLVE::In ();
		SOLVE::Solve ();
		SOLVE::Out ();
	}
	return 0;
} /*
18:58

Files are identical
*/