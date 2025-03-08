#include <bits/stdc++.h>
using namespace std;
int n;
string a,b,c;
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		c.erase(c.size()-1,1);
		if (a == "eat" && c == "eat") puts("or");
		else if (a == "eat") cout << c << '\n';
		else cout << a << '\n';
	}
	return 0;
}