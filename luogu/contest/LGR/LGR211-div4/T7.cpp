#include <bits/stdc++.h>
using namespace std;
int n,m;
string s[103],t[103];
bool f[103];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> t[i];
		for (int j = 1; j <= n; j++) {
			if (f[j]) continue;
			bool tui = false;
			int k = 0,l = 0;
			for (; k < s[j].size() && l < t[i].size();) {
				if (s[j][k] == t[i][l]) {
					++k,++l;
				}else{
					k = k - l + 1;
					l = 0;
				}
			}
			if (l == t[i].size()) f[j] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (f[i]) puts("Yes");
		else puts("No");
	}
	return 0;
}