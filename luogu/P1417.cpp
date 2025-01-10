#include <bits/stdc++.h>
#define int long long
#define max(x,y) (((x)>(y))?(x):(y))
using namespace std;
int t,n;
struct node{
	int a,b,c;
}o[100004];
int f[100004],ans;
bool cmp(node x,node y) {
	return 1.0*x.c/x.b < 1.0*y.c/y.b;
}
signed main () {
	cin >> t >> n;
	for (int i = 1; i <= n; i++) cin >> o[i].a;
	for (int i = 1; i <= n; i++) cin >> o[i].b;
	for (int i = 1; i <= n; i++) cin >> o[i].c;
	sort(o+1,o+n+1,cmp);
	for (int i = 1; i <= n; i++) {
		for (int j = t; j >= o[i].c; j--) {
			f[j] = max(f[j],f[j-o[i].c]+o[i].a-j*o[i].b);
		}
	}
	for (int i = 1; i <= t; i++) {
		ans = max(ans,f[i]);
	}
	cout << ans << '\n';
	return 0;
} 
