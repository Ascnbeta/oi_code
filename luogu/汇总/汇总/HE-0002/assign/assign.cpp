#include <bits/stdc++.h>
#define filein(x) freopen(x".in", "r", stdin);
#define file(x) {freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);}
using namespace std; // my guiding star.
const int N = 1e5 + 233, P = 1000000007;
int n, m, v;
map<int, int> M;
inline int qpow(int a, int n)
{
	int ans = 1;
	while (n)
	{
		if (n & 1) ans = 1ll * ans * a % P;
		a = 1ll * a * a % P; n >>= 1;
	}
	return ans;
}
int main()
{
	file("assign");
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &v); M.clear();
		bool qwq = true;
		for (int i=0, u, v; i<m; i++){scanf("%d%d", &u, &v); qwq &= M.find(u) == M.end() || M[u] == v; M[u] = v;}
		if (!qwq){puts("0"); continue;}
		int lst = -1, ans = 1, ed = 1;
		for (auto [u, ajdkfjjflsjl] : M)
		{
			ed = u;
			if (lst == -1){lst = u; ans = 1ll * ans * qpow(v, 2 * (u - 1)) % P; continue;}
			ans = ans * (qpow(v, 2 * (u - lst)) - 1ll * qpow(v, u - lst - 1) * (v - 1) % P) % P; lst = u;
		}
		ans = 1ll * ans * qpow(v, 2 * (n - ed)) % P;
;		printf("%d\n", (ans + P) % P);
	}
	return 0;
}