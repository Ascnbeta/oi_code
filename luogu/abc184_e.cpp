#include <bits/stdc++.h>
using namespace std;
int h,w;
char m[2004][2004];
bool f[2004][2004];
struct door{
	int x,y;
};
struct node{
	int x,y,d;
};
vector<door> c[26];
int sx,sy,ex,ey;
int dx[5] = {0,0,0,-1,1},dy[5] = {0,-1,1,0,0};
queue<node> q;
void bfs(int sx,int sy) {
	f[sx][sy] = true;
	q.push({sx,sy,0});
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		for (int i = 1; i <= 4; i++) {
			int tx = t.x + dx[i],ty = t.y + dy[i];
			if (tx < 1 || ty < 1 || tx > h || ty > w) continue;
			if (f[tx][ty]) continue;
			if (m[tx][ty] == '#') continue;
			if (m[tx][ty] == 'G') {
				cout << t.d + 1 << '\n';
				exit(0);
			}
			f[tx][ty] = true;
			q.push({tx,ty,t.d+1});
		}
		if (m[t.x][t.y] >= 'a' && m[t.y][t.y] <= 'z') {
			int num = m[t.x][t.y] - 'a';
			for (int i = 0; i < c[num].size(); i++) {
				int tx = c[num][i].x,ty = c[num][i].y;
				if (f[tx][ty]) continue;
				f[tx][ty] = true;
				q.push({tx,ty,t.d+1}); 
			}
			c[num].clear();
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> m[i][j];
			if (m[i][j] == 'S') sx = i,sy = j;
			if (m[i][j] == 'G') ex = i,ey = j;
			if (m[i][j] >= 'a' && m[i][j] <= 'z') {
				c[m[i][j]-'a'].push_back({i,j});
			}
		}
	}
	bfs(sx,sy);
	cout << -1 << '\n';
	return 0;
}