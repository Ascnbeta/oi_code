#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+30;
int n;
int a[maxn],b[maxn];
inline int exgcd(int a,int b,__int128 &x,__int128 &y) {
	if (b == 0) {x = 1,y = 0;return a;}
	int d = exgcd(b,a%b,x,y);
	__int128 tmp = x;
	x = y;
	y = tmp - a / b * y;
	return d;
}
inline void merge(int p,int q) {
	__int128 x,y;
	int gcd = exgcd(b[p],b[q],x,y);
	a[q] = (__int128)x  * ((__int128)(a[q]-a[p])/ gcd % (b[q]/gcd)) % (b[q]/gcd);
	if (a[q] < 0) a[q] += b[q]/gcd;
	b[q] = (__int128)b[p]*b[q]/gcd; 
	a[q] = ((__int128)a[q] * b[p] % b[q] + a[p]) % b[q];
	if (a[q] < 0) a[q] += b[q]; 
}
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> b[i] >> a[i];
	for (int i = 2; i <= n; i++) {
		merge(i-1,i);
	}
	cout << a[n]%b[n] << '\n';
	return 0;
}