#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-4;
const int maxn = 5e2+10;
int s,n;
double x[maxn],y[maxn];
double dis[maxn];
bool vis[maxn];
inline double calc(int i,int j) {
	return sqrt(fabs(x[i]-x[j])*fabs(x[i]-x[j])+fabs(y[i]-y[j])*fabs(y[i]-y[j]));
}
inline bool check(double x) {
	for (int i = 1; i <= n; i++) dis[i] = 1e9,vis[i] = false;
	int cnt = 0;
	for (int k = 1; k <= n; k++) {
		if (dis[k] != 1e9) continue;
		dis[k] = 0;
		++cnt;
		if (cnt > s) return false;
		for (int i = 1; i < n; i++) {
			int p = 0;
			for (int j = 1; j <= n; j++) {
				if (!vis[j]&&(p==0||dis[j]<dis[p])) p = j;
			}
			if (p == 0) break;
			vis[p] = true;
			for (int j = 1; j <= n; j++) {
				if (!vis[j]) {
					if (calc(p,j) <= x) {
						dis[j] = min(dis[j],calc(p,j));
					}
				}
			}
		}
	}
	return true;
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> s >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	double l = 0,r = 20000;
	while (r - l > eps) {
		double mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		}else{
			l = mid;
		}
	}
	printf("%.2f\n",l);
	return 0;
}