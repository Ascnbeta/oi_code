#include <bits/stdc++.h>
using namespace std;
int x,y,p,q;
int main () {
	cin >> x >> y >> p >> q;
	int ans = p;
	ans = min(ans,x-p);
	ans = min(ans,q);
	ans = min(ans,y-q);
	cout << ans << '\n';
	return 0;
}