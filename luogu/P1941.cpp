#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans = 0x3f3f3f3f,cnt;
struct node{
	int x,y;
}s[10005];
struct tube{
	int l,h;
	tube() {
		l=0,h=1000;
	}
}t[10005];
int pos[10005];
int f[1005][2],f1[1005][2];
int main () {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i].x >> s[i].y;
	}
	for (int i = 1; i <= k; i++) {
		int p;
		cin >> p;
		cin >> t[p].l >> t[p].h;
		pos[p]++;
	}
	memset(f,0x3f,sizeof(f));
	for (int i = 1; i <= m; i++) f[i][0] = f[i][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) f1[j][0] = f[j][0],f1[j][1] = f[j][1];
		for (int j = 1; j <= m; j++) {
			if (j + s[i-1].y <= m) {
				f[j][0] = min(f[j+s[i-1].y][0],f[j+s[i-1].y][1]);
			}else{
				f[j][0] = 0x3f3f3f3f;
			}
			if (j - s[i-1].x > 0) {
				f[j][1] = min(f[j-s[i-1].x][1]+1,min(f1[j-s[i-1].x][0]+1,f1[j-s[i-1].x][1]+1));
			}else{
				f[j][1] = 0x3f3f3f3f;
			}
		}
		for (int j = 1; j <= m; j++) if (j <= t[i].l || j >= t[i].h) f[j][0] = f[j][1] = 0x3f3f3f3f;
	}
	for (int i = 1; i <= m; i++) {
		//cout << f[i] << ' ';
		if (f[i][0] != 0x3f3f3f3f || f[i][1] != 0x3f3f3f3f) ans = min(ans,min(f[i][1],f[i][0]));
	}
	//cout << '\n';
	if (ans != 0x3f3f3f3f) {
		cout << 1 << '\n';
		cout << ans << '\n';
	}else{
		cout << 0 << '\n';
		cout << cnt << '\n';
	}
	return 0;
}