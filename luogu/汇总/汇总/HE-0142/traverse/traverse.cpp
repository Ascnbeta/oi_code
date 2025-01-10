#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const long long ll1 = 1;

int c, t;
int n, k;
struct edge{
	int u, v, id;
} a[maxn];
vector<int> v[maxn];
bool vis[maxn];
int e[maxn];
int cc[505][505];
int siz;
long long ans, ans1;

//int getc(int n, int m) {
//	if (c[n][m] != 0) return c[n][m];
//	if (n <= 503 && m <= 503) return c[n][m] = (getc(n-1, m-1) + getc(n-1,m))% mod; 
//	return (getc(n-1,m-1)) % mod;
//}
void dfs(int u, int fa, int cnt) {
	cout << u << ' ' << fa << ' ' << cnt << endl;
	if (cnt == siz) {
		ans1++;
		return ;
	} 
	for (int i = 0; i < v[u].size(); i++) {
		if (vis[v[u][i]]) continue;
		int to = 0;
		if (u = a[v[u][i]].u) to = a[v[u][i]].v;
		else to = a[v[u][i]].u;
		if (to == fa) continue;
		vis[v[u][i]] = 1;
		dfs(to, u, cnt + 1); 
		vis[v[u][i]] = 0;
	}
}

int getsiz(int u, int fa) {
	int cnt = 1;
	for (int i = 0; i < v[u].size(); i++) {
		if (v[u][i] == fa) continue;
		cnt += getsiz(v[u][i], u);
	}
	return cnt;
}

int main () {
	
	freopen("traverse.in", "r", stdin);
	freopen("traverse.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> t;
	while (t--) {
		ans = 1;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			cin >> a[i].u >> a[i].v;
			v[a[i].u].push_back(i);
			v[a[i].v].push_back(i);
		}
		for (int i = 1; i <= k; i++) {
			cin >> e[i];
		}
		sort(e + 1, e + k + 1);
		
//		for (int i = 1; i <= n; i++) {
//			for (int j = 0; j < v[i].size(); j++) {
//				cout << v[i][j] << ' ';
//			}
//			cout << endl;
//		}
		
		if (c == 18) {
			ans = 1;
			cout << ans << endl;
			continue;
		}
		if (c >= 19 && c <= 21) {
			ans1 = ll1 * (n-2) * (n-1) / 2;
			//ans1 %= mod;
			ans = 1;
			for (int i = 1; i <= n-1; i++) {
				ans = (ll1 * ans * i) % mod;
			} 
			cout << ans << endl;
			continue;
		}
		
			ans = 1;
			for (int i = 1; i <= k ; i++) {
				vis[i] = 0;
			}
			
			//cout << getsiz(1, 2) << endl;
			//cout << getsiz(2,1) << endl;
			
			for (int i = 1; i <= k; i++) {
				int from = a[i].u, to = a[i].v;
				vis[e[i]] = 1;
				ans1 = 0;
				siz = getsiz(from,to);
				dfs(from, to, 1);
				ans1 %= mod;
				ans = (ll1 * ans1 * ans) % mod; 
				
				ans1 = 0;
				siz = getsiz(to, from);
				dfs(to, from, 1);
				ans1 %= mod;
				ans = (ll1 * ans1 * ans) % mod; 
			}
		cout << ans << endl;
	}
	
	return 0;
}
/*
1 1
4 1
1 2
2 3
2 4
1
*/
