#include <bits/stdc++.h>
using namespace std;
int n,maxx,minn = 0x3f3f3f3f,ans;
int a[100005],v[100005];
int main () {
	// freopen("duel.in","r",stdin);
	// freopen("duel.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n ;i++) {
		cin >> a[i];
		v[a[i]]++;
		maxx = max(maxx,a[i]);
		minn = min(minn,a[i]);
	}
//	for (int i = minn; i <= maxx; i++) {
//		if (v[i] != 0) {
//			cout << i << ' ' << v[i] << '\n';
//		}
//	}
	int i = minn + 1,j = minn;
	for (; i <= maxx; i++) {
		if (v[i] > 0) {
			if (v[j] <= v[i]) {
				int y = v[i];
				while(j < i && v[j] <= y) {
					if (v[j] == 0) {
						++j;
						continue;
					}
					y -= v[j];
					v[j] = 0;
				}
				if (j != i && v[j] > y) {
					v[j] -= y;
				}
			}else{
				v[j] -= v[i];
			}
		}
	}
	for (int i = minn; i <= maxx; i++) {
		ans += v[i];
	}
	cout << ans << '\n';
	return 0;
}
//15:16 Í°ÅÅ+Ë«Ö¸Õë 
