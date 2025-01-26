#include <bits/stdc++.h>
using namespace std;
int n,ans,maxx;
struct block{
	int h,c,a;
}b[403];
bool cmp(block x,block y) {
	return x.a < y.a;
}
bool f[40005];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b[i].h >> b[i].a >> b[i].c;
		maxx = max(maxx,b[i].a);
	}
	sort(b+1,b+n+1,cmp);
	f[0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = b[i].a; j >= 0; j--) {
			for (int k = 1; k <= b[i].c; k++) {
				if (j >= k * b[i].h) f[j] |= f[j-k*b[i].h];
			}
		}
	}
	for (int i = 0; i <= maxx; i++) {
		if (f[i]) ans = i;
	}
	cout << ans << '\n';
	return 0;
}