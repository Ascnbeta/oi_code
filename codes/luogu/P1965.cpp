#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,x;
inline int binpow(int base,int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = ret * base % n;
		base = base * base % n;
		b >>= 1;
	}
	return ret % n;
}
vector<int> ans;
bool f[1000004];
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> m >> k >> x;
	int k1 = binpow(10,k);
	for (int i = 1; i <= k1; i++) {
		x = (x + m) % n;
		if (f[x]) {
			k1 %= i-1;
			if (k1 == 0) k1 = i-1;
			cout << ans[k1-1] << '\n';
			return 0;
		}else{
			ans.push_back(x);
			f[x] = true;
		}
	}
	cout << x << '\n';
	return 0;
}