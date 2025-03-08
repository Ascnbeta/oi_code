#include <bits/stdc++.h>
using namespace std;
int n;
int mp[13][13],cnt[3][13][2];
int m1[40000],m2[40000];
inline bool check(int v,int x,int y) {
	//cout << v << x << y << '\n';
	if (x>=2&&mp[x-1][y]==mp[x-2][y]&&mp[x-2][y]==v) return false;
	if (x<=n-1&&mp[x+1][y]==mp[x+2][y]&&mp[x+2][y]==v) return false;
	if (x>=1&&x<=n&&mp[x-1][y]==mp[x+1][y]&&mp[x+1][y]==v) return false;
	if (y>=2&&mp[x][y-1]==mp[x][y-2]&&mp[x][y-2]==v) return false;
	if (y<=n-1&&mp[x][y+1]==mp[x][y+2]&&mp[x][y+2]==v) return false;
	if (y>=1&&y<=n&&mp[x][y-1]==mp[x][y+1]&&mp[x][y+1]==v) return false;
	if (cnt[1][x][v]+1 > n / 2) return false;
	if (cnt[2][y][v]+1 > n / 2) return false;
	mp[x][y] = v;
	if (x == n) {
		long long tmp = 0;
		for (int i = 1; i <= n; i++) {
			tmp = tmp | (mp[i][y]<<(i-1));
		}
		if (m1[tmp] == 1) {
			mp[x][y] = -1;
			return false;
		}
		m1[tmp] = 1;
	}
	if (y == n) {
		long long tmp = 0;
		for (int i = 1; i <= n; i++) {
			tmp = tmp | (mp[x][i]<<(i-1));
		}
		if (m2[tmp] == 1) {
			mp[x][y] = -1;
			return false;
		}
		m2[tmp] = 1;
	}
	cnt[1][x][v]++;
	cnt[2][y][v]++;
	return true;
}
void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << mp[i][j];
		}
		cout << '\n';
	}
}
void dfs(int x,int y) {
	//cout << x << ' ' << y << '\n';
	//print();
	if (mp[x][y] != -1) {
		if (x == n) {
			long long tmp = 0;
			for (int i = 1; i <= n; i++) {
				tmp = tmp | (mp[i][y]<<(i-1));
			}
			if (m1[tmp] == 1) {
				return;
			}
			m1[tmp] = 1;
		}
		if (y == n) {
			long long tmp = 0;
			for (int i = 1; i <= n; i++) {
				tmp = tmp | (mp[x][i]<<(i-1));
			}
			if (m2[tmp] == 1) {
				return;
			}
			m2[tmp] = 1;
		}
		if (y != n) dfs(x,y+1);
		else if (x != n) dfs(x+1,1);
		else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cout << mp[i][j];
				}
				cout << '\n';
			}
			exit(0);
		}
		if (x == n) {
			long long tmp = 0;
			for (int i = 1; i <= n; i++) {
				tmp = tmp | (mp[i][y]<<(i-1));
			}
			m1[tmp] = 0;
		}
		if (y == n) {
			long long tmp = 0;
			for (int i = 1; i <= n; i++) {
				tmp = tmp | (mp[x][i]<<(i-1));
			}
			m2[tmp] = 0;
		}
		return;
	}
	if (check(0,x,y)) {
		//cout << x << ' ' << y << '\n';
		if (y != n) dfs(x,y+1);
		else if (x != n) dfs(x+1,1);
		else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cout << mp[i][j];
				}
				cout << '\n';
			}
			exit(0);
		}
		if (x == n) {
			long long tmp = 0;
			for (int i = 1; i <= n; i++) {
				tmp = tmp | (mp[i][y]<<(i-1));
			}
			m1[tmp] = 0;
		}
		if (y == n) {
			long long tmp = 0;
			for (int i = 1; i <= n; i++) {
				tmp = tmp | (mp[x][i]<<(i-1));
			}
			m2[tmp] = 0;
		}
		mp[x][y] = -1;
		cnt[1][x][0]--;
		cnt[2][y][0]--;
	}
	if (check(1,x,y)) {
		//cout << x << ' ' << y << '\n';
		if (y != n) dfs(x,y+1);
		else if (x != n) dfs(x+1,1);
		else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cout << mp[i][j];
				}
				cout << '\n';
			}
			exit(0);
		}
		if (x == n) {
			long long tmp = 0;
			for (int i = 1; i <= n; i++) {
				tmp = tmp | (mp[i][y]<<(i-1));
			}
			m1[tmp] = 0;
		}
		if (y == n) {
			long long tmp = 0;
			for (int i = 1; i <= n; i++) {
				tmp = tmp | (mp[x][i]<<(i-1));
			}
			m2[tmp] = 0;
		}
		mp[x][y] = -1;
		cnt[1][x][1]--;
		cnt[2][y][1]--;
	}
}
int main () {
	cin >> n;
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= n+1; j++) {
			mp[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char ch;
			cin >> ch;
			if (ch == '1') {
				mp[i][j] = 1;
				cnt[1][i][1]++;
				cnt[2][j][1]++;

			}else if (ch == '0'){
				mp[i][j] = 0;
				cnt[1][i][0]++;
				cnt[2][j][0]++;
			}
		}
	}
	dfs(1,1);
	return 0;
}