<<<<<<< HEAD
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int ans = 1;
int T;
int n,m;
int a[10000004],cnt;
inline long long binpow(int a,int cnt) {
	int ret = 1;
	while (cnt) {
		if (cnt & 1) ret = ret * (a % mod) % mod;
		a = ((a % mod) * (a % mod)) % mod;
		cnt >>= 1;
	}
	return ret % mod;
}
int f[10000003],g[10000003],s[10000003],t[10000004];
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin >> T;
	g[1] = 1;
	for (int i = 2; i <= 10000002; i++) {
		g[i] = g[i-1] * i % mod;
	}
	s[0] = 1;
	for (int i = 1; i <= 10000002; ++i) s[i] = s[i - 1] * g[i] % mod;
	t[10000002] = binpow(s[10000002], mod - 2);
	for (int i = 10000002; i >= 1; --i) t[i - 1] = t[i] * g[i] % mod;
	f[0] = 1;
	for (int i = 1; i <= 10000002; ++i) f[i] = t[i] * s[i - 1] % mod;
	while (T--) {
		cin >> n >> m;
//		cout << binpow(2,n-1) << '\n';
		for (int i = 1; i <= n; i++) cin >> a[i];
		cnt = 0,ans = 0;
		for (int i = 1; i <= n; i++) if (a[i] <= a[i-1]) ++cnt;
		if (cnt + 1 > m) {
			cout << 0 << '\n';
			continue;
		}else if (cnt + 1 == m) {
			cout << 1 << '\n';
			continue;
		}else{
			int N = (n - 1 - cnt) % mod;
			for (int i = 0; i <= m - 1 - cnt; i++) {
				int a = g[N] % mod;
				int b = ((f[i] % mod) * (f[N - i] % mod)) % mod;
				ans = (ans + (a * b % mod ) % mod) % mod;
			}
			cout << ans % mod<< '\n';
			continue;
		}
	}
	return 0;
=======
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int ans = 1;
int T;
int n,m;
int a[10000004],cnt;
inline long long binpow(int a,int cnt) {
	int ret = 1;
	while (cnt) {
		if (cnt & 1) ret = ret * (a % mod) % mod;
		a = ((a % mod) * (a % mod)) % mod;
		cnt >>= 1;
	}
	return ret % mod;
}
int f[10000003],g[10000003],s[10000003],t[10000004];
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin >> T;
	g[1] = 1;
	for (int i = 2; i <= 10000002; i++) {
		g[i] = g[i-1] * i % mod;
	}
	s[0] = 1;
	for (int i = 1; i <= 10000002; ++i) s[i] = s[i - 1] * g[i] % mod;
	t[10000002] = binpow(s[10000002], mod - 2);
	for (int i = 10000002; i >= 1; --i) t[i - 1] = t[i] * g[i] % mod;
	f[0] = 1;
	for (int i = 1; i <= 10000002; ++i) f[i] = t[i] * s[i - 1] % mod;
	while (T--) {
		cin >> n >> m;
//		cout << binpow(2,n-1) << '\n';
		for (int i = 1; i <= n; i++) cin >> a[i];
		cnt = 0,ans = 0;
		for (int i = 1; i <= n; i++) if (a[i] <= a[i-1]) ++cnt;
		if (cnt + 1 > m) {
			cout << 0 << '\n';
			continue;
		}else if (cnt + 1 == m) {
			cout << 1 << '\n';
			continue;
		}else{
			int N = (n - 1 - cnt) % mod;
			for (int i = 0; i <= m - 1 - cnt; i++) {
				int a = g[N] % mod;
				int b = ((f[i] % mod) * (f[N - i] % mod)) % mod;
				ans = (ans + (a * b % mod ) % mod) % mod;
			}
			cout << ans % mod<< '\n';
			continue;
		}
	}
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}