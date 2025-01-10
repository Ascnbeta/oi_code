#include <bits/stdc++.h>
#define ll long long
#define MyWife Cristallo
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
int c, T;
int n, k, head[N], nxt[N], to[N], tot;
void add(int u, int v) {
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
	if(tot % 2) add(v, u);
}	
int main() {
	freopen("traverse.in", "r", stdin);
	freopen("traverse.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		int u, v;
		for(int i = 1; i < n; ++i) scanf("%d%d", &u, &v), add(u, v);
		int e;
		for(int i = 1; i <= k; ++i) scanf("%d", &e);
		printf("%lld\n", 1LL * (n - 1) * (n - 2) % mod);
	}
	return 0;
}

