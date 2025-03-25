#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+30;
int n,ans = LONG_LONG_MAX;
int a[maxn];
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/b.out","w",stdout);
#endif
    cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	do {	
		int sum = 0;
		for (int i = 1; i <= n-1; i++) {
			int minn = INT_MAX;
			for (int j = i+1; j <= n; j++) {
				minn = min(minn,a[j]);
			}
			minn = max(minn,a[i]);
			sum += minn;
		}
		ans = min(ans,sum);
	}while (next_permutation(a+1,a+n+1));
	cout << ans << '\n';
    return 0;
}