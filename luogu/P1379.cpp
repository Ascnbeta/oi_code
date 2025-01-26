#include <bits/stdc++.h>
using namespace std;
int f[5][5],ans[5][5];
int tmpx,tmpy;
struct node{
	int m[5][5];
	int cnt,x,y;
	node(int a[][5],int p,int px,int py) {
		cnt = p;
		m[1][1] = a[1][1];
		m[1][2] = a[1][2];
		m[1][3] = a[1][3];
		m[2][1] = a[2][1];
		m[2][2] = a[2][2];
		m[2][3] = a[2][3];
		m[3][1] = a[3][1];
		m[3][2] = a[3][2];
		m[3][3] = a[3][3];
		x = px;
		y = py;
	}
};
queue<node> q[3];
map<int,int> mp1,mp2;
int dx[5] = {0,0,0,-1,1},dy[5] = {0,-1,1,0,0};
inline int g(int a[][5]) {
	return a[1][1]*100000000+a[1][2]*10000000+a[1][3]*1000000+a[2][1]*100000+a[2][2]*10000+a[2][3]*1000+a[3][1]*100+a[3][2]*10+a[3][3];
}
inline void bfs() {
	q[1].push(node(f,0,tmpx,tmpy));
	q[2].push(node(ans,0,2,2));
	mp1[g(f)] = 0,mp2[g(ans)] = 0;
	while(!q[1].empty()&&!q[2].empty()) {
		node t = q[1].front();
		q[1].pop();
		if (mp2.find(g(t.m)) != mp2.end()) {
			cout << (*mp2.find(g(t.m))).second + t.cnt<< '\n';
			exit(0);
		}
		for (int i = 1; i <= 4; i++) {
			int tx = t.x + dx[i],ty = t.y + dy[i];
			if (tx < 1 || tx > 3 || ty < 1 || ty > 3) continue;
			swap(t.m[tx][ty],t.m[t.x][t.y]);
			if (mp1.find(g(t.m)) != mp1.end()) {
				swap(t.m[tx][ty],t.m[t.x][t.y]);
				continue;
			}
			q[1].push(node(t.m,t.cnt+1,tx,ty));
			mp1[g(t.m)] = t.cnt+1;
			swap(t.m[tx][ty],t.m[t.x][t.y]);
		}
		t = q[2].front();
		q[2].pop();
		if (mp1.find(g(t.m)) != mp1.end()) {
			cout << (*mp1.find(g(t.m))).second + t.cnt << '\n';
			exit(0);
		}
		for (int i = 1; i <= 4; i++) {
			int tx = t.x + dx[i],ty = t.y + dy[i];
			if (tx < 1 || tx > 3 || ty < 1 || ty > 3) continue;
			swap(t.m[tx][ty],t.m[t.x][t.y]);
			if (mp2.find(g(t.m)) != mp2.end()) {
				swap(t.m[tx][ty],t.m[t.x][t.y]);
				continue;
			}
			q[2].push(node(t.m,t.cnt+1,tx,ty));
			mp2[g(t.m)] = t.cnt+1;
			swap(t.m[tx][ty],t.m[t.x][t.y]);
		}
	}	
}
int main () {

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			char ch;
			cin >> ch;
			f[i][j] = ch - '0';
			if (f[i][j] == 0) tmpx = i,tmpy = j;
		}
	}
	ans[1][1] = 1;ans[1][2] = 2;ans[1][3] = 3;ans[2][1] = 8;ans[2][2] = 0;ans[2][3] = 4;ans[3][1] = 7;ans[3][2] = 6;ans[3][3] = 5;
	bfs();
	return 0;
}