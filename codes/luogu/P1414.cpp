#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+30;
const int maxk = 1e6+40;
int n;
int k[maxn];
int cnt[maxk];
inline void solve(int x) {
	cnt[x]++;
	if (x != 1) cnt[1]++;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			if (i != x / i) {
				cnt[i]++;
				cnt[x/i]++;
			}else{
				cnt[i]++;
			}
		}
	}
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		solve(k[i]);
	}
	int tgt = 1;
 	for (int i = 1000000; i >= 1 && tgt <= n; i--) {
		if (cnt[i] >= tgt) {
			while (tgt <= cnt[i] && tgt <= n) {
				cout << i << '\n';
				++tgt;
			}
		}
	}
	return 0;
}