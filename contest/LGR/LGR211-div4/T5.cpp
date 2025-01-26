
#include <bits/stdc++.h>
using namespace std;
int n,p,cnt;
int t[1003];
int main () {
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		int x,y;
		cin >> x >> y;
		if (y == 1) t[x] = 1;
	}
	for (int i = 1; i <= p; i++) {
		if (t[i]) ++cnt;
	}
	cout << cnt << '\n';
	return 0;
}