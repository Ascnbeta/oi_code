#include <bits/stdc++.h>
using namespace std;
int n;
char c1,c2;
string s;
int main () {
	cin >> n >> c1 >> c2 >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		if (s[i] != c1) s[i] = c2;
	}
	cout << s << '\n';
	return 0;
}