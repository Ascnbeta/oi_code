#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+30;
const int mod = 998244353;
string s,s1;
int n,T;
vector<char> v;
inline int binpow(int base,int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = ret * base % mod;
		base = base * base % mod;
		b >>= 1;
	} 
	return ret % mod;
}
signed main () {
	cin >> T;
	while (T--) {
		cin >> n >> s;
		s = ' ' + s;
		s1 = s;
		int ans = 0;
		for (int i = 1; i <= n/2; i++) {
			s1[n+1-i] = s1[i];
		}
		v.clear();
		for (int i = (n+1)/2; i >= 1; i--) {
			v.push_back(s1[i]-'A');
		}
		for (int i = 0; i < v.size(); i++) {
			ans = (ans + v[i]*binpow(26,i)) % mod;
		}
		if (s1 <= s) ans = (ans + 1) % mod;
		cout << ans << '\n';
	}
	return 0;
}