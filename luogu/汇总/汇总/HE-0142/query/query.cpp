#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn =5e5+5; 

int n, q;
int u, v;
vector<int> a[maxn];
int l, r, k;
int dep[maxn];
int fa[maxn];
int du[maxn];
bool duis1;
int lx[maxn][20];
int ln[maxn][20];
int po[25];
int ans = 0;

void dfs(int u, int father) {
	fa[u] = father;
	dep[u] = dep[father] + 1;
	for (int i = 0; i < a[u].size(); i++) {
		if (a[u][i] == father) continue;
		dfs(a[u][i], u);
	}
}

int main () {
	
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	duis1 = true;
	for(int i = 1; i < n; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
		du[u]++;
		du[v]++;
		if (du[u] > 2) duis1 = false;
		if (du[v] > 2) duis1 = false;
	}
	
	dep[1] = 1;
	dfs(1, 0);
	
	po[0]=1;
	for (int i = 1; i <= 20; i++) po[i] = po[i-1]*2;
//	for (int i = 1; i <= n; i++) {
//		cout << i << ":i " << dep[i] << ' '  << fa[i] << endl;
//	}

	for (int i = 1; i <= n; i++) {
		lx[i][0] = dep[i];
		ln[i][0] = dep[i];
	}
	for (int i = 1; po[i] <= n-1; i++) {
		for (int j = 1; j <= n; j++) {
			lx[j][i] = max(lx[j][i-1], lx[j + po[i-1]][i-1]);
			if (j + po[i-1] > n) ln[j][i] = ln[j][i-1]; 
			else ln[j][i] = min(ln[j][i-1], ln[j + po[i-1]][i-1]);
			//cout << ln[j][i] << ' ';
		}
		//cout << endl;
	}
	
	
	cin >> q;
	while(q--) {
		cin >> l >> r >> k;
		if (k == 1) {
			int len = r - l + 1;
			int mi = 0;
			while (po[mi+1] < len) mi++;
			cout << max(lx[l][mi], lx[r-po[mi]+1][mi]) << endl;
		}
		//if (duis1 && du[1] == 1) {
			ans = 0;
			int mi = 0;
			while (po[mi + 1] < k) mi++;
			for (int i = l; i + k - 1 <= r; i++) {
				ans = max(ans, min(ln[i][mi], ln[i + k - po[mi]][mi]));
			}
	//	}
		cout << ans << endl;
		
	}
	
	return 0;
}
/*
6
5 6
6 1
6 2
2 3
2 4 
3
2 5 2
1 4 1
1 6 3

*/

