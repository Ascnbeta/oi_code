#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+39;
const int mod = 10007;
int n,m,ans;
struct node{
	int id,num;
};
vector<node> color[maxn][2];
int c[maxn],num[maxn];
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> num[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) { 
		color[c[i]][i%2].push_back({i,num[i]});
	}
	// for (int i = 1; i <= m; i++) {
	// 	cout << i << ' ' << 0 << ":\n";
	// 	for (int j = 0; j < color[i][0].size(); j++) {
	// 		cout << color[i][0][j].id << ' ' << color[i][0][j].num << '\n';
	// 	}
	// 	cout << i << ' ' << 1 << ":\n";
	// 	for (int j = 0; j < color[i][1].size(); j++) {
	// 		cout << color[i][1][j].id << ' ' << color[i][1][j].num << '\n';
	// 	}
	// }
	for (int i = 1; i <= m; i++) {
		int sumnum,sumid,sumf;
		sumnum = sumid = sumf = 0;
		for (int j = 0; j < color[i][0].size(); j++) {
			ans = (ans + color[i][0][j].id * sumnum % mod) % mod;
			ans = (ans + color[i][0][j].id * color[i][0][j].num % mod * j  % mod) % mod;
			ans = (ans + sumid * color[i][0][j].num % mod) % mod;
			ans = (ans + sumf % mod) % mod;
			sumf = (sumf + color[i][0][j].id * color[i][0][j].num % mod) % mod;
			sumid = (sumid + color[i][0][j].id) % mod;
			sumnum = (sumnum + color[i][0][j].num) % mod;
		}
		// cout << i << ' ' << 0 << ":" << ans << '\n';
		sumnum = sumid = sumf = 0;
		for (int j = 0; j < color[i][1].size(); j++) {
			ans = (ans + color[i][1][j].id * sumnum % mod) % mod;
			ans = (ans + color[i][1][j].id * color[i][1][j].num % mod * j  % mod) % mod;
			ans = (ans + sumid * color[i][1][j].num % mod) % mod;
			ans = (ans + sumf % mod) % mod;
			sumf = (sumf + color[i][1][j].id * color[i][1][j].num % mod) % mod;
			sumid = (sumid + color[i][1][j].id) % mod;
			sumnum = (sumnum + color[i][1][j].num) % mod;
		}
		// cout << i << ' ' << 1 << ":" << ans << '\n';
	}
	cout << ans << '\n';
	return 0;
}