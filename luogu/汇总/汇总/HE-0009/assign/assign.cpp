#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

typedef long long ll;
typedef std::pair < ll, ll > pai;
const ll mod = 1e9 + 7;
const ll M = 1e5 + 10;
ll n, m, v, cnt, ans;
pai a[M], b[M];

ll quickly_pow (ll a, ll b) {
	ll ans = 1, base = a % mod;
	while (b) {
		if (b & 1) ans = ans * base % mod;
		base = base * base % mod;
		b >>= 1;
	}
	return ans;
} 

void Main() {
	std::cin >> n >> m >> v;
	for (ll i = 1; i <= m; i++) 
		std::cin >> b[i].first >> b[i].second;
	std::sort (b + 1, b + m + 1);
	a[cnt = 1] = b[1];
	for (ll i = 2; i <= m; i++) {
		if (b[i] == b[i - 1]) continue;
		a[++cnt] = b[i];
	}
	m = cnt;
	for (ll i = 2; i <= m; i++) 
		if (a[i].first == a[i - 1].first) {
			std::cout << "0\n";
			return ;
		}
	ans = quickly_pow(v * v, a[1].first - 1);
	for (ll i = 2; i <= m; i++) {
		ll now = quickly_pow(v * v, a[i].first - a[i - 1].first);
		now = now + mod - quickly_pow(v, a[i].first - a[i - 1].first - 1) * (v - 1) % mod;
		now %= mod;
		ans = ans * now % mod;
	} 
	ans = ans * quickly_pow (v * v, n - a[m].first) % mod;
	std::cout << ans << '\n';
}

int main() {
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	ll T = 1;
	std::cin >> T;
	while (T--) Main();
	return 0;	
}
