#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+3;
int n,d;
int v[N],a[N];
int lst,oil,ans;
signed main () {
	cin >> n >> d;
	for (int i = 1; i <= n-1; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	lst = a[1];
	int s = 0;
	for (int i = 2; i <= n; i++) {
		if (i == n) {
			s += v[i-1];
			s -= oil;
	 		int my = ceil(1.0*s/d);
		 	ans += my * lst;
			break;
		}
		if (a[i] >= lst) {
			s += v[i-1];
			continue;
		}
		s += v[i-1];
		s -= oil;
		int my = ceil(1.0*s/d);
		ans +=  my * lst;
		oil = my * d;
		oil -= s;
		lst = a[i];
		s = 0;
	}
	
	cout << ans << endl;
	return 0;
}
