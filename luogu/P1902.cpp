#include <bits/stdc++.h>
using namespace std;
int n,m;
int p[1004][1004];
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};
bool f[1004][1004];
struct node {
	int x,y;
};
queue<node> q;
bool check(int x,int y,int d) {
	memset(f,0,sizeof(f));
	f[x][y] = true;
	while(!q.empty()) q.pop();
	q.push({x,y});
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		if (t.x == n) return true;
		f[t.x][t.y] = true;
		for (int i = 1; i <= 4; i++) {
			int tx = t.x + dx[i],ty = t.y + dy[i];
			if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
			if (f[tx][ty]) continue;
			if (p[tx][ty] > d) continue;
			f[tx][ty] = true;
			q.push({tx,ty});
		}
	}
	return false;
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> p[i][j];
		}
	}
	int l = 1,r = 1000;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(1,1,mid)) {
			r = mid - 1;
		}else {
			l = mid + 1;
		}
	}
	cout << l << '\n';
	return 0;
}