#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,x;
int main () {
	cin >> a >> b >> c >> d >> x;
	if (a > c) swap(d,b),swap(c,a);
	if (x < a) cout << 0 << '\n';
	else if (x >= a && x < c) cout << b << '\n';
	else cout << b + d << '\n';
	return 0;
}