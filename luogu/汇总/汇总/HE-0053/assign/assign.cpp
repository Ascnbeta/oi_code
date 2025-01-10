#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,v;
struct op{
	int c,d;
}o[100004];
const int mod = 1e9+7;
inline int binpow(int x,int p) {
	if (p == 0) return 1;
	int base = x % mod,ret = 1;
	while (p) {
		if (p&1) ret = (ret * (base % mod)) % mod;
		base = ((base % mod) * (base % mod)) % mod;
		p >>= 1;
	}
	return ret % mod;
}
bool cmp(op x,op y) {
	if (x.c == y.c) return x.d < y.d;
	return x.c < y.c;
}
bool cmp1(op x,op y) {
	return x.c == y.c && x.d == y.d;
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin >> T;
	while (T--) {
		cin >> n >> m >> v;
		for (int i = 1;i <= m; i++) {
			cin >> o[i].c >> o[i].d;
		} 
		sort(o+1,o+m+1,cmp);
		m = unique(o+1,o+m+1,cmp1)-o-1;
//		cout << m << '\n';
		bool f = false;
		for (int i = 2; i <= m; i++) {
			if (o[i-1].c == o[i].c && o[i-1].d != o[i].d) {
				cout << 0 << '\n';
				f = true;
				break;
			}
		}
		if (f) continue;
		if (m == 1) {
			cout << binpow(v,2*(n-1)) << '\n';
		}else if (n == m) {
			cout << binpow(binpow(v,2)-1,n-1) << '\n';
		}//20+?pts
	}
	return 0;
}
