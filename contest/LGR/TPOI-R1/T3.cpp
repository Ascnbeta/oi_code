#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n,k;
string s;
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> t;
	while (t--) {
		cin >> n >> k >> s;
		if (s.size() == 1 || s[0] == s[1]) {
			n *= k;
			cout << (1+n)*n/2%998244353 << '\n';
		}else{
			n *= k;
			cout << (2+n)*(n/2)/2%998244353 << '\n';
		}
	}
	return 0;
}