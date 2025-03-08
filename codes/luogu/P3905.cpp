#include <bits/stdc++.h>
using namespace std;
int n,m,d;
int e[103][103],dis[103][103];
int main () {
	cin >> n >> m;
	memset(dis,0x3f,sizeof(dis));
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		e[x][y] = z;
		e[y][x] = z;
		dis[x][y] = 0;
		dis[y][x] = 0;
	}
	cin >> d;
	for (int i = 1; i <= d; i++) {
		int x,y;
		cin >> x >> y ;
		dis[x][y] = e[x][y];
		dis[y][x] = e[y][x];
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int a,b;
	cin >> a >> b;
	cout << dis[a][b] << '\n';
	return 0;
}