#include <bits/stdc++.h>
using namespace std;
string s;
int ans;
int main () {
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= s.size()-1; i++) {
		if (s[i] != '0') ++ans;
		else if (s[i+1] == '0') {
			i++;
			++ans;
		}else{
			++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}