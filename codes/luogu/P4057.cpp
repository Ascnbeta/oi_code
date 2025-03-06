#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c;
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> a >> b >> c;
	cout << a*b/__gcd(a,b)*c/__gcd(a*b/__gcd(a,b),c) << '\n';
	return 0;
}