#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
struct node{
	int x,y;
	bool operator < (const node &a) const{
		if (x == a.x) return y < a.y;
		return x < a.x;
	}
}a[504];
int f[504][203];
inline int calc(int sx,int sy,int tx,int ty) {
	return abs(sx-tx)+abs(sy-ty);
}
signed main () {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) {
		f[i][k] = 1;
		for (int j = 0; j <= k; j++) {
			for (int l = 1; l <= i-1; l++) {
				if (a[l].x > a[i].x || a[l].y > a[i].y) continue;
				int tmp = calc(a[l].x,a[l].y,a[i].x,a[i].y)-1;
				if (tmp+j>k) continue;
				f[i][j] = max(f[i][j],f[l][j+tmp]+tmp+1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			ans = max(ans,f[i][j]+j);
		}
	}
	cout <<	ans << '\n';
	return 0;
}