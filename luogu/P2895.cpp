#include <bits/stdc++.h>
using namespace std;
int m;
int mp[304][304],mp2[304][304];
struct meteor{
	int x,y,t;
}me[50004];
int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,1,-1};
int tot = 1;
struct node {
	int x,y,t;
};
bool vis[304][304];
queue<node> q;
bool cmp(meteor a,meteor b) {
	return a.t < b.t;
}
void bfs() {
	vis[0][0] = true;
	q.push(node{0,0,0});
	while(!q.empty()) {
		node t =q.front();
		q.pop();
		if (mp2[t.x][t.y] == 0) {
			cout << t.t << endl;
			exit(0);
		}
		for (int i = tot; i <= m; i++) {
			if (me[i].t - 1 == t.t) {
				mp[me[i].x][me[i].y] = 1;
				mp[me[i].x+1][me[i].y] = 1;
				mp[me[i].x][me[i].y+1] = 1;
				if (me[i].x-1 >= 0) mp[me[i].x-1][me[i].y] = 1;
				if (me[i].y-1 >= 0) mp[me[i].x][me[i].y-1] = 1;
			}else{
				break;
			}
		}
		for (int i = 1; i <= 4; i++) {
			int sx = t.x + dx[i],sy = t.y + dy[i];
			if (sx < 0 || sy < 0 || sx > 300 || sy > 300) continue;
			if (vis[sx][sy]) continue;
			if (mp[sx][sy] == 1) continue;
			vis[sx][sy] = true;
			q.push(node{sx,sy,t.t+1});
		}
	}
}
int main () {
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> me[i].x >> me[i].y >> me[i].t;
		mp2[me[i].x][me[i].y] = 1;
		mp2[me[i].x+1][me[i].y] = 1;
		mp2[me[i].x][me[i].y+1] = 1;
		if (me[i].x-1 >= 0) mp2[me[i].x-1][me[i].y] = 1;
		if (me[i].y-1 >= 0) mp2[me[i].x][me[i].y-1] = 1;
		if (me[i].t == 0) {
			mp[me[i].x][me[i].y] = 1;
			mp[me[i].x+1][me[i].y] = 1;
			mp[me[i].x][me[i].y+1] = 1;
			if (me[i].x-1 >= 0) mp[me[i].x-1][me[i].y] = 1;
			if (me[i].y-1 >= 0) mp[me[i].x][me[i].y-1] = 1;
		}
	}
	sort(me+1,me+m+1,cmp);
	bfs();
	cout << -1 << endl;
	return 0;
}
