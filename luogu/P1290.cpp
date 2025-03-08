#include <bits/stdc++.h>
using namespace std;
int T;
int m,n;
string solve(int x,int y) {
	if (x < y) swap(x,y);
	if (y == 0) {
		return "Ollie";
	}
	if (x / y == 1) {
		if (solve(x % y,y) == "Stan") {
			return "Ollie";
		}else{
			return "Stan";
		}
	}else if (x / y >= 2){
		return "Stan";
	}
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> T;
	while (T--) {
		cin >> m >> n;
		cout << solve(m,n) << " wins\n";
	}
	return 0;
}