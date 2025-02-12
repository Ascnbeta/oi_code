#include <bits/stdc++.h>
using namespace std;
int a[4];
int main () {
	cin >> a[1] >> a[2] >> a[3];
	if (a[1]*a[2]==a[3]||a[1]*a[3]==a[2]||a[2]*a[3]==a[1]) cout << "Yes" << '\n';
	else cout << "No" << '\n';
	return 0;
}