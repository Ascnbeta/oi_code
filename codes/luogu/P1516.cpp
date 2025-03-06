#include <bits/stdc++.h>
#define int long long
using namespace std;
int X,Y,m,n,l;
inline int exgcd(int a,int b,int &x,int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b,a%b,y,x);
	y -= a / b * x;
	return d;
} 
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> X >> Y >> m >> n >> l;
	if (m < n) {
		swap(m,n);
		swap(X,Y);
	}
	int x,y;
	int gcd = exgcd(m-n,l,x,y);
	if ((Y-X) % gcd != 0) {
		puts("Impossible");
		return 0;
	}
	x = x * (Y - X) / gcd % (l / gcd);
	// cout << x << '\n';
	if (x < 0) x += (l / gcd);
	cout << x << '\n';
	return 0;
}