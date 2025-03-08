#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans,cnt;
int prime[30] = {0,2,3,5,7,11,13,17,19,23,29};
inline int binpow(int base,int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret *= base;
		base *= base;
		b >>= 1;
	}
	return ret;
}
void dfs(int cur,int num,int lst,int c) {
	if (c > cnt) ans = max(ans,num),cnt = c;
	else if (c == cnt) ans = min(ans,num);
	if (cur == 11) return;
	for (int i = 0; i <= lst && num * binpow(prime[cur],i) <= n; i++) {
		dfs(cur+1,num*binpow(prime[cur],i),i,c*(i+1));
	}
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	if (n == 1) {
		puts("1");
		return 0;
	}
	ans = 0,cnt = 0;
	dfs(1,1,0x3f3f3f3f,1);
	cout << ans << '\n';
	return 0;
}