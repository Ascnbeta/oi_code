#include<bits/stdc++.h> 
const int maxn = 1e6 , mod = 1e9 + 7;
using namespace std;
int T , n ,m ,v ;
int ans;
int c[maxn] , d[maxn] , bo[maxn] , a[maxn], b[maxn];
long long dfs(int pos) {
	if(pos == n) return 1; 
	return (1 + (dfs(pos + 1)*v))% mod;
}
int bop[maxn];
void dfs1(int pos) {
	if(pos == n) {
		for(int j=1;j<=n;++j) bop[j] = bo[j];
		int w = 0;
		for(int i=1;i<=n-1;++i) {
			if(bop[i] == a[i])
		    {
				if(bop[i+1] != b[i] and bo[i + 1] != 0 ) 
				{
					w = 1;
				}
				bop[i+1] = b[i];
			}
		}
		if(w == 1) return ;
		ans ++;
		ans %= mod;
		return ;
	}
	a[pos] = 1, b[pos] = 1;
	dfs1(pos + 1);
	a[pos] = 1, b[pos] = 2;
	dfs1(pos + 1);
	a[pos] = 2, b[pos] = 1;
	dfs1(pos + 1);
	a[pos] = 2, b[pos] = 2;
	dfs1(pos + 1);
	return ;
} 
void dfs2(int pos) {
	if(pos == n) {
		for(int j=1;j<=n;++j) bop[j] = bo[j];
		int w = 0;
		for(int i=1;i<=n-1;++i) {
			if(bop[i] == a[i])
		    {
				if(bop[i+1] != b[i] and bo[i + 1] != 0 ) 
				{
					w = 1;
				}
				bop[i+1] = b[i];
			}
		}
		if(w == 1) return ;
		ans ++;
		ans %= mod;
		return ;
	}
	a[pos] = 1, b[pos] = 1;
	dfs2(pos + 1);
	return ;
}
long long dfs4(int pos) {
	if(pos == n) {
		if(bo[n]) return 1;
		else return v;
	}
	if(bo[pos]) return v%mod*dfs4(pos + 1)%mod;
	else return v%mod * v%mod * dfs4(pos + 1) % mod; 
}
signed main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin >> T;
	while(T --) {
		cin >> n >> m >> v;
		bool qp = 0;
		for(int i=1;i<=n;++i) bo[i] = 0;
		for(int i=1;i<=m;++i) {
			cin >> c[i] >> d[i];
			if(bo[c[i]] and bo[c[i]] != d[i]) {
				qp = 1;
			}
			bo[c[i]] = d[i];
		} 
		if(qp == 1) {
			cout << 0 << endl;
			continue;
		} 
		if(n == m) {
			cout << dfs(1)%mod << endl;
		}
		else if(v <= 2) {
			ans = 0;
			if(v == 2) dfs1(1),
			cout << ans%mod << endl;
			else dfs2(1),cout << ans%mod << endl;
		}
		else if(m == 1) {
			cout << dfs4(1)%mod << endl;
		}
		else {
			cout << 0 << endl;
		}
	} 
} 
