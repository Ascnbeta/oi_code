#include <bits/stdc++.h>
using namespace std;
int a,b,l;
double minn = 0x3f3f3f3f;
int ansa,ansb;
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> a >> b >> l;
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++) {
			if (__gcd(i,j) != 1) continue;
			if (1.0*i/j < 1.0*a/b) continue;
			if (1.0*i/j - 1.0*a/b < minn) {
				minn = min(minn,1.0*i/j - 1.0*a/b);
				ansa = i;
				ansb = j;
			}
		}
	}
	cout << ansa << ' ' << ansb << '\n';
	return 0;
}