#include <bits/stdc++.h>
using namespace std;
int t[15][15];
int fx,fy,cx,cy,fd = 1,cd = 1,cnt;
int dx[5] = {0,-1,0,1,0};
int dy[5] = {0,0,1,0,-1};
char ch;
int temp = 20;
bool ck[500006];
int main () {
	for (int i = 0; i <= 11; i++) {
		t[0][i] = 1;
	}
	for (int i = 0; i <= 11; i++) {
		t[11][i] = 1;
	}
	for (int i = 0; i <= 11; i++) {
		t[i][0] = 1;
	}
	for (int i = 0; i <= 11; i++) {
		t[i][11] = 1;
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> ch;
			if (ch == '*') {
				t[i][j] = 1;
			}
			if (ch == 'C') {
				cx = i,cy = j;
			}
			if (ch == 'F') {
				fx = i,fy = j;
			}
		}
	}
	/*for (int i = 0; i <= 11; i++) {
		for (int j = 0; j <= 11 ; j++) {
			cout << t[i][j];
		}
		cout << endl;
	}*/
	while(1) {
		++cnt;
		if (ck[fd * 100000 + cd * 10000 + (fx-1) * 1000 + (cx-1) * 100 + (fy-1) * 10 + cy - 1]) {
			cout << 0 << endl;
			return 0;
		}
		ck[fd * 100000 + cd * 10000 + (fx-1) * 1000 + (cx-1) * 100 + (fy-1) * 10 + cy - 1] = true;
		if (t[fx + dx[fd]][fy + dy[fd]] != 1) {
			fx += dx[fd];
			fy += dy[fd];
		}else{
			fd += 1;
			if (fd > 4) fd = 1; 
		}
		if (t[cx + dx[cd]][cy + dy[cd]] != 1) {
			cx += dx[cd];
			cy += dy[cd];
		}else{
			cd += 1;
			if (cd > 4) cd = 1; 
		}
		//cout << fx << ' ' << fy << ' ' << cx << ' ' << cy << endl;
		if (fx == cx && fy == cy) {
			cout << cnt << endl;
			return 0;
		}
		
	}
	return 0;
} 
