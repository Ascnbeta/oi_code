#include <bits/stdc++.h>
using namespace std;
int T;
int ans = 1;
int a0,a1,b0,b1;
int p[20000],ka[20000],kb[20000],tot;
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> T;
	while (T--) {
		cin >> a0 >> a1 >> b0 >> b1;
		ans = 0;
		for (int i = 1; i * i <= b1; i++) {
			if (b1 % i == 0) {
				if (i != b1 / i) {
					if (i % a1 == 0 && __gcd(i/a1,a0/a1) == 1 && __gcd(b1/b0,b1/i) == 1) ++ans;
					int j = b1 / i;
					if (j % a1 == 0 && __gcd(j/a1,a0/a1) == 1 && __gcd(b1/b0,b1/j) == 1) ++ans;
				}else{
					if (i % a1 == 0 && __gcd(i/a1,a0/a1) == 1 && __gcd(b1/b0,b1/i) == 1) ++ans;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}