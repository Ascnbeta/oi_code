#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int f[103][103];
int num[103];
bool check(int l,int k,int r) {
	int len = k - l + 1;
	if ((r-l+1)%len != 0) return false;
	for (int i = l; i <= r; i++) {
		if (s[i] != s[(i-l)%len+l]) return false;
	}
	return true;
}
int main() {
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= 9; i++) num[i] = 1;
	for (int i = 10; i <= 99; i++) num[i] = 2;
	num[100] = 3;
	memset(f,0x3f,sizeof(f));
	for (int i = 1; i <= n; i++) f[i][i] = 1;
	for (int len = 2; len <= n; len++){
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			for (int k = i; k < j; k++) {
				f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]);
			}
			for (int k = i; k < j; k++) {
				if (check(i,k,j)) {
					f[i][j] = min(f[i][j],num[len/(k-i+1)]+2+f[i][k]);
				}
			}
		}
	}
	cout << f[1][n] << '\n';
	return 0;
}