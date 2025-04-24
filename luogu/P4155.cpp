#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5+30;
struct line {
	int l,r,id;
	bool operator < (const line &y) const{
		return l < y.l;
	}
}p[maxn];
int n,m;
int f[maxn][30],ans[maxn];
inline void prepare() {
	int r = 1;
	for (int l = 1; l <= 2*n; l++) {
		while (r <= 2*n) {
			if (p[r].l > p[l].r) break;
			++r;
		}
		--r;
		f[l][0] = r;
	}
	for (int i = 1; (1<<i) <= 2*n; i++) {
		for (int j = 1; j <= 2*n; j++) {
			if (f[j][i-1]) f[j][i] = f[f[j][i-1]][i-1];
		}
	}
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x,y;
		cin >> x >> y;
		if (x < y) {
			p[i].l = x,p[i].r = y,p[i].id = i;
		}else if (x > y) {
			p[i].l = x,p[i].r = y+m,p[i].id = i;
		}
	}
	sort(p+1,p+n+1);
	for (int i = 1; i <= n; i++) {
		p[i+n].l = p[i].l + m,p[i+n].r = p[i].r + m;
	}
	prepare();
	for (int i = 1; i <= n; i++) {
		int pt = i,cnt = 1;
		for (int j = __lg(n); j >= 0; j--) {
			if (f[pt][j] > 0 && p[f[pt][j]].r - p[i].l < m) {
				pt = f[pt][j];
				cnt += (1<<j);
			}
		}
		ans[p[i].id] = cnt+1;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}