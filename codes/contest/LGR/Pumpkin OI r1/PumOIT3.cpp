<<<<<<< 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
inline int binpow(int x,int b) {
	int base = x % mod,ans = 1;
	while (b) {
		if (b&1) ans = ans * base % mod;
		base *= base % mod;
		b >>= 1;
		ans %= mod;
		base %= mod;
	}
	return ans % mod;
}
int n;
signed main () {
	cin >> n;
	if (n <= 3) cout << 1 << '\n';
	else{
		int tmp = 1;
		int tmp2 = binpow(2,n-3);
		for (int i = 3; i <= n - 1; i++) {
				tmp = tmp * i % mod;
		}
		//cout << tmp2 << ' ' << tmp << '\n';
		//cout << binpow(3,2) << '\n';
		cout << (tmp2 % mod * binpow(tmp,mod-2) % mod) % mod << '\n';
	}
	return 0;
=======
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
inline int binpow(int x,int b) {
	int base = x % mod,ans = 1;
	while (b) {
		if (b&1) ans = ans * base % mod;
		base *= base % mod;
		b >>= 1;
		ans %= mod;
		base %= mod;
	}
	return ans % mod;
}
int n;
signed main () {
	cin >> n;
	if (n <= 3) cout << 1 << '\n';
	else{
		int tmp = 1;
		int tmp2 = binpow(2,n-3);
		for (int i = 3; i <= n - 1; i++) {
				tmp = tmp * i % mod;
		}
		//cout << tmp2 << ' ' << tmp << '\n';
		//cout << binpow(3,2) << '\n';
		cout << (tmp2 % mod * binpow(tmp,mod-2) % mod) % mod << '\n';
	}
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}