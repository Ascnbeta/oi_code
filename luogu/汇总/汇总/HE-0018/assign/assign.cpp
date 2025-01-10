#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7 , M = 1e5 + 10;
int n , m , v;
struct node {
	int c , d;
}q[M]; int p[M]; int cnt;
bool cmp(node x , node y) {
	return x.c == y.c ? x.d < y.d : x.c < y.c;
}
int Powfast(int x , int y) {
	int sum = 1;
	while(y) {
		if(y & 1ll) sum = sum * x % mod;
		x = x * x % mod; y >>= 1ll;
	}
	return sum;
}
void solve() {
	int ans = 1;
	for(int i = 1;i < cnt;i ++) {
		int x = p[i + 1] - p[i];
		ans = ans * (Powfast(v , 2ll * x) - (Powfast(v , x - 1ll)
		 * (v - 1ll) % mod) % mod) % mod;
	}
//	cout << ans << endl;
	ans = ans * Powfast(v , 2ll * (p[1] - 1ll)) % mod; 
	ans = ans * Powfast(v , 2ll * (n - p[cnt])) % mod;
	printf("%lld\n",(ans + mod) % mod);
}

signed main() {
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int t; cin >> t;
	while(t --) {
		scanf("%lld%lld%lld",&n,&m,&v); cnt = 0;
		for(int i = 1;i <= m;i ++) {
			scanf("%lld%lld",&q[i].c,&q[i].d);
		}
		sort(q + 1 , q + m + 1 , cmp);
		bool flag = 1; p[++ cnt] = q[1].c;
		for(int i = 2;i <= m;i ++) {
			if(q[i].c == q[i - 1].c) {
				if(q[i].d != q[i - 1].d) {
					flag = 0; break;
				}
			}
			else p[++ cnt] = q[i].c;
		}
		if(!flag) {
			printf("0\n"); continue;
		}
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 2 1 2 1 1 
2 2 2 1 1 2 2 
2 2 2 1 1 1 2
*/
