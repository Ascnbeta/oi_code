#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005];
int main () {
	cin >> n;
	for (int i = 1; i <= n ; i++) cin >> a[i];
	for (int i = 1; i <= n ; i++) cin >> b[i];
	sort(a+1,a+n+1,greater<int>());
	sort(b+1,b+n+1,greater<int>());
	int ai = 1,aj = n,bi = 1,bj = n,ans = 0;
	while (ai <= aj && bi <= bj) {
		if (a[ai] > b[bi]) {
			ans += 2;
			++ai,++bi;
		}else if (a[ai] < b[bi]) {
			++bi,--aj;
		}else{
			if (a[aj] > b[bj]) {
				ans += 2;
				--aj,--bj;
			}else{
				if (a[aj] == b[bi]) {
					ans += 1;
				}
				--aj,++bi;
			}
		}
	}
	cout << ans << ' ';
	ai = 1,aj = n,bi = 1,bj = n,ans = 0;
	while (ai <= aj && bi <= bj) {
		if (a[aj] < b[bj]) {
			--aj,--bj;
		}else if (a[aj] > b[bj]) {
			ans += 2;
			++ai,--bj;
		}else{
			if (a[ai] < b[bi]) {
				++ai,++bi;
			}else{
				if (a[ai] == b[bj]) {
					ans += 1;
				}else if (a[ai] > b[bj]) {
					ans += 2;
				}
				++ai,--bj;
			}
		}
	}
	cout << ans << ' ';
	return 0;
}