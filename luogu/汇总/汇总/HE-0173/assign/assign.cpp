#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
const int N = 1e5 + 10;
int fpm (int x,int power) {
	int ans = 1;
	for(; power; power >>= 1,x*=x%mod) 
		if(power & 1) ans *= x %= mod;
	return ans % mod;
}
int me[N]; 
set<int> Set;
signed main () {
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin >>T;
	while (T--) {
		memset(me,0,sizeof(me));
		int n,m,v,ans = 1;
		cin >> n >> m >> v;
		while (m--) {
			int u,v;
			cin >> u >> v;
			if(me[u] && me[u] != v) ans = 0;
			me[u] = v;
			Set.insert(u);
		}
		int res = 0;
		for(int i : Set) {
			ans *= fpm(v,i-res);
			ans %= mod;
			res = i;
		}
		cout << ans % mod << '\n';
	}
}
