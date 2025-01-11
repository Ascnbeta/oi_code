#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2+4,maxm = 4e4+3;
int n,m,q;
int t[maxn];
int e[maxn][maxn];
int dis[maxn][maxn];
int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> t[i];
	memset(e,0x3f,sizeof(e));
	memset(dis,0x3f,sizeof(dis));
	for (int i = 1; i <= m; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		dis[x][y] = z;
		dis[y][x] = z;
	}
	for (int i = 0; i < n; i++) dis[i][i] = 0;
	cin >> q;
	int k = 0;
	while (q--) {
		int x,y,T;
		cin >> x >> y >> T;
		for (; k < n && t[k] <= T; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dis[i][j] = min(dis[i][k]+dis[k][j],dis[i][j]);
				}
			}
		}
		if (t[x] > T || t[y] > T || dis[x][y] == 0x3f3f3f3f) {
			cout << -1 << '\n';
		}else{
			cout << dis[x][y] << '\n';
		}
	}
	return 0;
}