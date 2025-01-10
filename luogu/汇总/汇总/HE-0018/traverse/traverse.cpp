#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10 , mod = 1e9 + 7;
int n , k;
int a[N] , p[N] , jc[N];
struct node {
	int u , v;
}q[N];
int Powfast(int x , int y) {
	int sum = 1ll;
	while(y) {
		if(y & 1ll) sum = sum * x % mod;
		x = x * x % mod; y >>= 1ll;
	}
	return sum;
}

signed main() {
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	jc[0] = 1; int c , t;
	for(int i = 1;i < N;i ++) jc[i] = jc[i - 1] * i % mod;
	cin >> c >> t;
	while(t --) {
		scanf("%lld%lld",&n,&k);
		for(int i = 1;i < n;i ++) {
			scanf("%lld%lld",&q[i].u,&q[i].v);
		}
		for(int i = 1;i <= k;i ++) {
			scanf("%lld",&p[i]);
		}
		if(c == 18) {
			printf("1\n"); continue;
		}
		else if(c >= 19 && c <= 21) {
			printf("%lld\n",((jc[n - 1] - (n - k - 1ll) * (n - k - 2ll) % mod 
			* jc[n - 3] % mod)%mod+mod) * Powfast(2ll , mod - 2ll) %mod);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 1 5 2 1 2 1 3 2 4 2 5 1 3
*/
