#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+30;
int n,m,V;
int w[maxn],v[maxn];
int father[maxn],rk[maxn];
inline int find(int x) {
	int t = x;
	while (x != father[x]) x = father[x];
	int w;
	while (t != father[t]) w = father[t],father[t] = x,t = w;
	return x;
}
inline void merge(int x,int y) {
	int p = find(x),q = find(y);
	if (p == q) return;
	if (rk[p] < rk[q]) {
		father[p] = q;
		rk[q] = max(rk[p]+1,rk[q]);
	}else{
		father[q] = p;
		rk[p] = max(rk[q]+1,rk[p]);
	}
}
vector<int> f[maxn];
int sumw[maxn],sumv[maxn];
int dp[maxn];
int main () {
	cin >> n >> m >> V;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= m; i++) {
		int x,y;
		cin >> x >> y;
		merge(x,y);
	}
	for (int i = 1; i <= n; i++) f[find(i)].push_back(i),sumw[find(i)] += w[i],sumv[find(i)] += v[i];
	for (int i = 1; i <= n; i++) {
		int tot = f[i].size();
		if (tot == 0) continue;
		for (int j = V; j >= 0; j--) {
			for (int kk = 0; kk < tot; kk++) {
				int k = f[i][kk];
				if (j >= w[k]) dp[j] = max(dp[j],dp[j-w[k]]+v[k]);
			}
			if (j >= sumw[i]) dp[j] = max(dp[j],dp[j-sumw[i]]+sumv[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= V; i++) ans = max(ans,dp[i]);
	cout << ans << '\n';
	return 0;
}