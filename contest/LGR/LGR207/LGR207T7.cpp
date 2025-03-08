#include <bits/stdc++.h>
// #define int long long

using namespace std;
int L,R,ans;
int f[8];
int a[9];
bool check(int x){
	f[1] = f[2] = f[3] = f[4] = f[5] = f[6] = 0;
	int tot = 0;
	int tmp = x;
	while (tmp) {
		int p = tmp % 10;
		if (p == 0) return false;
		tmp /= 10;
		f[++tot] = p;
	}
	for (int i = 1; i <= 6; i++) {
		for (int j = i + 1; j <= 6; j++) {
			for (int k = j + 1; k <= 6; k++) {
				a[1] = f[i];
				a[2] = f[j];
				a[3] = f[k];
				sort(a+1,a+4);
				int g = 3;
				for (int l = 1;l <= 6; l++) {
					if (l != i&&l != j&&l !=k) {
						a[++g] = f[l];
					}
				}
				sort(a+4,a+7);
				if (a[1]+a[2]>a[3]&&a[4]+a[5]>a[6]) return true;
			}
		}
	}
	return false;
}
int main() {
	cin >> L >> R;
	for (int i = L; i <= R; i++) {
		if (check(i)) {
			// cout << i << '\n';
			++ans;
		}
	}
	cout << ans;
	return 0;
}

