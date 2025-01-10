#include <bits/stdc++.h>
#define ll long long
#define MyWife Cristallo
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;
int T, n, m, v, a[N];
ll ans;
int main() {
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		for(int i = 1; i <= n; ++i) a[i] = 0;
		ans = 1;
		scanf("%d%d%d", &n, &m, &v);
		int c, d;
		bool fl = 0;
//		for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
//		puts("");
		for(int i = 1; i <= m; ++i) {
			scanf("%d%d", &c, &d);
			if(!a[c] || a[c] == d) a[c] = d;
			else fl = 1;
		}
		if(fl) {puts("0"); continue; }
//		cerr << "T:" << T << endl;
		for(int i = 1; i < n; ++i) {
			ll cnt = v * v;
			if(a[i] && a[i + 1]) cnt -= v - 1;
			ans *= cnt % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

