#include <bits/stdc++.h>
// #define int long long

using namespace std;
int n,m;
string s[1004];
bool q[1004][1004];
#ifdef int
signed main () {
	
	return 0;
}
#else
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		int a = 0,b = 0;
		bool h = false;
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'A') ++a;
			else if (s[i][j] == 'B') ++b;
			else if (s[i][j] == 'H') h = true;
		}
		if (h) {
			for (int j = 0; j < a; j++) s[i][j] = 'A';
			for (int j = a; j < m - b; j++) {
				if (s[i][j] == 'H') {
					continue;
				}else{
					s[i][j] = '#';
				}
			} 
			for (int j = m - b; j < m; j++) s[i][j] = 'B';
		}else{
			if (a > b) {
				for (int j = 0; j < m - a; j++) s[i][j] = '#';
				for (int j = m - a; j < m; j++) s[i][j] = 'A';
			}else if (a < b) {
				for (int j = 0; j < b; j++) s[i][j] = 'B';
				for (int j = b; j < m; j++) s[i][j] = '#';
			}else{
				for (int j = 0; j < m; j++) s[i][j] = '#';
			}
		}
	}
	// for (int i = 1; i <= n; i++) cout << s[i] << '\n';
		for (int i = 0; i < m; i++) {
			for (int j = 1; j <= n; j++) {
				if (s[j][i] != '#' && s[j][i] != 'H') {
					if (j != 1) {
						if (s[j-1][i] == s[j][i]) q[j][i] = true;
					}
					if (j != n) {
						if (s[j+1][i] == s[j][i]) q[j][i] = true;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (q[i][j]) cout << '#';
				else cout << s[i][j];
			}
			cout << '\n';
		}
	return 0;
}
#endif

/*
5 8
#A#AH#B#
#A##B#B#
##AA##BB
AAA###BB
AAA#ABBB
*/