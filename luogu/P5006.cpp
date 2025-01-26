#include <bits/stdc++.h>
using namespace std;
int n,M;
char m[103][103];
int dx[5] = {0,0,0,-1,1},dy[5] = {0,-1,1,0,0};
int hp,st,de,sx,sy,q;
double hp0,st0,de0;
int main () {
	cin >> n >> M;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> m[i][j];
//			cout << m[i][j];
		}
//		cout << '\n';
	}
	cin >> hp0 >> st0 >> de0;
	cin >> sx >> sy;
	cin >> st >> de >> q;
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			cout << hp << ' ' << st << ' ' << de << '\n';
		}else{
			int d;
			cin >> d;
//			cout << d << '\n';
			sx += dx[d],sy += dy[d];
//			cout <<sx << ' ' << sy << '\n';
			if (m[sx][sy] == 'R') {
				hp -= 10;
				if (hp < 0) hp = 0;
			}
			if (m[sx][sy] == 'Q') st += 5;
			if (m[sx][sy] == 'Y') de += 5;
			if (m[sx][sy] == 'M') {
				int t1 = max(1,(int)(ceil(hp0/max(1.0,(double)(st-de0))))*max(1,(int)(st0-de)));
				hp += t1;
			}
		}
	}
	return 0;
}
