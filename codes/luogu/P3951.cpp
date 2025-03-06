#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> a >> b;
	cout << a*b-a-b << '\n';
	return 0;
}