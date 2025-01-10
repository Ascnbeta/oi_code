#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 105 ;
const int mod = 1e9 + 7 ;
int a[MAXN], b[MAXN], n, m, v ;
int k[MAXN], ans ;
inline void dfs (int x) {
	if (x == n) {
		bool key = 1 ;
		for (int i = 1 ; i <= n - 1 ; i++) {
			if (a[i] == k[i] && b[i] != k[i + 1] && k[i + 1] != 0) {
				key = 0 ;
				break ;
			}	
		}
		if (key) {
//			for (int i = 1 ; i <= n - 1 ; i++) cout << a[i] << ' ' << b[i] << '\n' ;
			ans++ ;
			ans %= mod ;
		}
		return ;
	}
	for (int i = 1 ; i <= v ; i++) {
		for (int j = 1 ; j <= v ; j++) {
			a[x] = i ;
			b[x] = j ;
			dfs(x + 1) ;
		}
	}
}
inline long long quick_pow (int a, int b) {
	long long res = 1 ; 
	while (b) {
		if (b & 1) res = res * a % mod ;
		a = a * a % mod ;
		b >>= 1 ;
	}
	return res ;
}
int main () {
	freopen("assign.in","r",stdin) ;
	freopen("assign.out","w",stdout) ;
	int t ;
	cin >> t ;
	while (t--) {
		ans = 0 ;
		bool key = 0 ;
		int c, d ;
		cin >> n >> m >> v ;
		if (v > 2) {
			cout << quick_pow(2, v + v - 1) << '\n' ;
			continue ;
		}
		for (int i = 1 ; i <= n ; i++) k[i] = 0 ;
		for (int i = 1 ; i <= m ; i++) {
			cin >> c >> d ; 
			if (k[c] != d && k[c]) {
				key = 1 ;
				break ;
			}
			k[c] = d ;
		}
		if (key) {
			cout << 0 << '\n' ;
			continue ;
		}
		dfs (1) ;
		cout << ans % mod << '\n' ;
	}
}
