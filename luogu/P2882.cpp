#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 5e3+30;
int n,ans = 0x3f3f3f3f,k;
int cf[maxn],now;
int a[maxn];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char ch;
		cin >> ch;
		if (ch == 'F') {
			a[i] = 1;
		}else{
			a[i] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		now = 0;
		memset(cf,0,sizeof(cf));
		int j = 1;
		for (; j+i-1 <= n; j++) {
			now += cf[j];
			int tmp = now % 2;
			if ((tmp^a[j]) == 0) {
				cf[j] += 1,cf[j+i] -= 1;
				++now;
				++cnt;
			}
		}
		bool f = false;
		for (; j <= n; j++) {
			now += cf[j];
			int tmp = now % 2;
			if ((tmp^a[j]) == 0) {
				f = true;
				break;
			}
		}
		if (f) continue;
		if (cnt < ans) {
			ans = cnt;
			k = i;
		}
	}
	cout << k << ' ' << ans << '\n';
	return 0;
}