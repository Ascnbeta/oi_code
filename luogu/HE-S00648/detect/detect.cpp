#include <bits/stdc++.h>
#define int long long
using namespace std;
const int eps = 1e-8;
int T;
int n,m,l,V,ans2,ans1;
struct car{
	int d,v,a;
}c[100005];
int p[100005];
vector<int> cp[100005];
bool f[23],f1[100004];
bool a0,a1,a2;
void check1(int x,int q) {
	if (c[q].d > p[x]) return;
	double vi = sqrt(c[q].v*c[q].v+2*c[q].a*(p[x]-c[q].d));
	if (vi - V > eps) {
		if (!f1[q]) ++ans1;
		f1[q] = true;
		return;
	}
}

signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	while(T--) {
		cin >> n >> m >> l >> V;
		ans1 = 0;
		ans2 = 0;
		a0 = true,a1 = true,a2 = true;
		for (int i = 1; i <= n; i++) {
			cin >> c[i].d >> c[i].v >> c[i].a;
			f1[i] = false;
			if (c[i].a != 0) a0 = false;
			if (c[i].a >= 0) a1 = false;
			if (c[i].a <= 0) a2 = false;
		}
		for (int i = 1; i <= m; i++) {
			cin >> p[i];
			cp[i].clear();
		}
		if (n <= 20 && m <= 20) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (p[j] < c[i].d) continue;
					double vi = sqrt(c[i].v*c[i].v+2*c[i].a*(p[j]-c[i].d));
					if (0 - vi > eps) break;
					if (vi - V > eps) {
						if (!f1[i]) ++ans1;
						f1[i] = true;
						cp[j].push_back(i);
					}
				}
			}
//			for (int i = 1; i <= m; i++) {
//				for (int j = 0; j < cp[i].size(); j++) {
//					cout << cp[i][j] << ' ';
//				}
//				cout << '\n';
//			}
			int x = pow(2,m);
			for (int i = 0; i <= x - 1; i++) {
				int t = i,cnt = 0;
				for (int i = 1; i <= n; i++) f[i] = false;
				for (int j = 1;t;j++) {
					if (t&1) {
						for (int k = 0; k < cp[j].size(); k++) {
							f[cp[j][k]] = true;
						}
						++cnt;
					}
					t >>= 1;
				}
				bool f2 = false;
				for (int i = 1; i <= n; i++) {
					if (f1[i]&&!f[i]) {
						f2 = true;
						break;
					}
				}
				if (!f2) {
					ans2 = max(ans2,m-cnt);
				}
			}
			cout << ans1 << ' ' << ans2 << '\n';
		}else if (a0) {
			for (int i = 1; i <= n; i++) {
			 	if (c[i].v > V && c[i].d <= p[m]) ans1++;
			}
			if (ans1 == 0) cout << 0 << ' ' << m << '\n';
			else cout << ans1 << ' ' << m - 1 << '\n';
 		}else if (a2) {
			for (int i = 1; i <= n; i++) {
				check1(m,i);
			}
			if (ans1 == 0) cout << 0 << ' ' << m << '\n';
			else cout << ans1 << ' ' << m - 1 << '\n';
		}
		
	}
	return 0;
}
//现在是17:06，在写完前3st后想出了正解，但是先得去写T3暴力，希望有时间回来写完
//18:23,正解调不出来了 
