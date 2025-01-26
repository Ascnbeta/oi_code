#include <bits/stdc++.h>
// #define int long long

using namespace std;
int l,r,ans;
int f[8];
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
	sort(f+1,f+tot+1);
	if (f[1]+f[2]>f[3]||f[4]+f[5]>f[6]) return true;
	else return false;
}
int main() {
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		if (check(i)) {
			// cout << i << '\n';
			++ans;
		}
	}
	cout << ans;
	return 0;
}

