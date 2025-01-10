#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,b,ans;
struct chocolate{
	ll p,c;
}c[100005];
bool cmp(const chocolate x,const chocolate y) {
	return x.p < y.p;
}
int main () {
	cin >> n >> b;
	for (int i = 1; i <= n; i++) {
		cin >> c[i].p >> c[i].c;
	}
	sort(c+1,c+n+1,cmp);
	for (int i = 1; i <= n; i++) {
		if (b >= c[i].p) {
			ll tmp = b / c[i].p;
			ans += min(tmp,c[i].c);
			b -= min(tmp,c[i].c) * c[i].p;
		}else{
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}