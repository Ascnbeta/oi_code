#include <bits/stdc++.h>
#define lep(i, a, b) for (int i = a; i <= b; ++i)
#define rep(i, a, b) for (int i = a; i >= b; --i)
#define ep(i, u) for (int i = H[u]; i; i = e[i].n)

typedef long long ll;
typedef std::pair<ll, ll> PLL;
const int _ = 2e5 + 7;
const int mod = 1e9 + 7;

ll T, n, m, v; PLL a[_];

ll P(ll a, ll b) { ll ans = 1;
	for (; b; b >>= 1, a = a * a % mod)
		if (b & 1) ans = ans * a % mod;
	return ans;
}

int main() {
	
	freopen("assign.in", "r", stdin);
	freopen("assign.out","w",stdout);
	
	scanf("%lld", & T);
	while (T--) {
		scanf("%lld%lld%lld", & n, & m, & v);
		lep(i, 1, m) scanf("%lld%lld", & a[i].first, & a[i].second);
		std::sort(a + 1, a + 1 + m);
		m = std::unique(a + 1, a + 1 + m) - a - 1;
		
		bool flag = true;
		lep(i, 2, m) if (a[i].first == a[i - 1].first and a[i].second != a[i - 1].second) { flag = false; break; }
		if (!flag) { puts("0"); continue; }
		
		ll ans = 0, t = 1;
		
		lep(i, 2, m) {
			ll r = P(v * v % mod, n - 1 - (a[i].first - a[1].first)), l = a[i].first - a[i - 1].first;
			ll w = (P(v, l - 1) * (v - 1) % mod) % mod;
			ans = (ans + (t * r % mod) * w % mod) % mod,
			t = t * (P(v * v % mod, l) - w) % mod;
		}
		
		ans = ((P(v * v % mod, n - 1) - ans) % mod + mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
