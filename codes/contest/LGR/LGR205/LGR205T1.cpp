#include <bits/stdc++.h>
using namespace std;
int n,cnt;
string s,ans;
int f[27];
int id;
int main () {
	cin >> n >> s;
	for (int i = 0; i < s.size(); i++) {
		if (!f[s[i]-'a']) {
			++cnt;
		}
		f[s[i]-'a'] += 1;
	}
	if (cnt < 26) {
		for (int i = 0; i <= 25; i++) {
			if (f[i] == 0) {
				while(n--) {
					cout << (char)(i+'a');
				}
				return 0;
			}
		}
	}else{
		int tmp = INT_MAX;
		for (int i = 0; i <= 25; i++) {
			if (f[i] < tmp) {
				tmp = f[i];
				id = i;
			}
		}

		for (int i = 0; i < n; i++) {
			if (f[s[i]-'a'] == tmp) {
				ans += s[i];
			}else{
				ans += (char)(id-'a');
			}
		}
		cout << ans;
	}
	return 0;
}