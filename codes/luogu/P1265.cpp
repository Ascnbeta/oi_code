#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+10;
int n;
double ans;
double x[maxn],y[maxn];
double dis[maxn];
bool vis[maxn];
inline double calc(int i,int j) {
	return sqrt(fabs(x[i]-x[j])*fabs(x[i]-x[j])+fabs(y[i]-y[j])*fabs(y[i]-y[j]));
}
inline void prim() {
	for (int i = 1; i <= n; i++) dis[i] = 1e9;
	dis[1] = 0;
	for (int i = 1; i < n; i++) {
		int p = 0;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]&&(p==0||dis[j]<dis[p])) p = j;
		}
		vis[p] = true;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) dis[j] = min(dis[j],calc(p,j));
		}
	}
	for (int i = 1; i <= n; i++) ans += dis[i];
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	prim();
	printf("%.2f\n",ans);
	return 0;
}