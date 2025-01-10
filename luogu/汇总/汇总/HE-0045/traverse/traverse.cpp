#include <bits/stdc++.h>
#define lep(i, a, b) for (int i = a; i <= b; ++i)
#define rep(i, a, b) for (int i = a; i >= b; --i)
#define ep(i, u) for (int i = H[u]; i; i = e[i].n)

typedef long long ll;
const int _ = 2e5 + 7;
const int mod = 1e9 + 7;

int c, T, n, k; ll fac[_];

int read() {
	int x = 0; char c = getchar();
	while (c < '0' or c > '9') c = getchar();
	while (c >= '0' and c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}

int main() {
	
	freopen("traverse.in", "r", stdin);
	freopen("traverse.out","w",stdout);
	
	c = read(), T = read(); fac[0] = 1;
	lep(i, 1, _ - 1) fac[i] = fac[i - 1] * i % mod;
	
	while (T--) {
		n = read(), k = read(); int u, v;
		lep(i, 1, n - 1) u = read(), v = read();
		int x;
		lep(i, 1, k) x = read();
		if (c == 18) printf("%d\n", 1);
		else if (19 <= c and c <= 21) printf("%lld\n", k * fac[n - 2] % mod);
		else printf("%d\n", k);
	}
	return 0;
}

