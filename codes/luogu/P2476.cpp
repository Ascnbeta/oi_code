<<<<<<< HEAD
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
int k,n,ans;
int cnt[10];
int f[16][16][16][16][16][6];
int dfs(int a,int b,int c,int d,int e,int lst) {
	if (f[a][b][c][d][e][lst] == 0xcfcfcfcf) return f[a][b][c][d][e][lst];
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) return 1;
	int ret = 0;
	if (a) ret += (a-(lst==2))*dfs(a-1,b,c,d,e,1)%mod;
	if (b) ret += (b-(lst==3))*dfs(a+1,b-1,c,d,e,2)%mod;
	if (c) ret += (c-(lst==4))*dfs(a,b+1,c-1,d,e,3)%mod;
	if (d) ret += (d-(lst==5))*dfs(a,b,c+1,d-1,e,4)%mod;
	if (e) ret += e*dfs(a,b,c,d+1,e-1,5)%mod;
	f[a][b][c][d][e][lst] = ret%mod;
	return ret%mod;
}
signed main () {
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int t;
		cin >> t;
		++cnt[t];
	}
	memset(f,0xcf,sizeof(f));
	cout << dfs(cnt[1],cnt[2],cnt[3],cnt[4],cnt[5],0) << '\n';
	return 0;
=======
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
int k,n,ans;
int cnt[10];
int f[16][16][16][16][16][6];
int dfs(int a,int b,int c,int d,int e,int lst) {
	if (f[a][b][c][d][e][lst] == 0xcfcfcfcf) return f[a][b][c][d][e][lst];
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) return 1;
	int ret = 0;
	if (a) ret += (a-(lst==2))*dfs(a-1,b,c,d,e,1)%mod;
	if (b) ret += (b-(lst==3))*dfs(a+1,b-1,c,d,e,2)%mod;
	if (c) ret += (c-(lst==4))*dfs(a,b+1,c-1,d,e,3)%mod;
	if (d) ret += (d-(lst==5))*dfs(a,b,c+1,d-1,e,4)%mod;
	if (e) ret += e*dfs(a,b,c,d+1,e-1,5)%mod;
	f[a][b][c][d][e][lst] = ret%mod;
	return ret%mod;
}
signed main () {
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int t;
		cin >> t;
		++cnt[t];
	}
	memset(f,0xcf,sizeof(f));
	cout << dfs(cnt[1],cnt[2],cnt[3],cnt[4],cnt[5],0) << '\n';
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}