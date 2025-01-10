#include <bits/stdc++.h>
using namespace std;
int a[5];
int v1,cnt1,v2,cnt2;
int main () {
	cin >> a[1] >> a[2] >> a[3] >> a[4];
	sort(a+1,a+5);
	if (a[1] == a[2] && a[2] == a[3] && a[4] != a[3]) puts("Yes");
	else if (a[2] == a[3] && a[3] == a[4] && a[1] != a[2]) puts("Yes");
	else if (a[1] == a[2] && a[3] == a[4] && a[2] != a[3]) puts("Yes");
	else puts("No");
	return 0;
}