<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+21;
const int mod = 1e9+7;
long long ans = 1;
int n;
struct food{
	int a,b;
}f[maxn];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> f[i].a;
	for (int i = 1; i <= n; i++) {
		cin >> f[i].b;
		if (f[i].a == 1) {
			ans += f[i].b;
		}
	}
	double maxx = ans;
	int p = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i].a == 1) continue;
		double tmp = (1.0 * ans + f[i].b) / f[i].a;
		// cout << tmp << '\n';
		if (tmp > maxx) {
			p = i;
			maxx = tmp;
		}
	}
	ans += f[p].b;
	for (int i = 1; i <= n; i++) {
		if (f[i].a == 1) continue;
		if (p == i) continue;
		ans = ans * f[i].a % mod;
	}
	cout << ans << '\n';
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+21;
const int mod = 1e9+7;
long long ans = 1;
int n;
struct food{
	int a,b;
}f[maxn];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> f[i].a;
	for (int i = 1; i <= n; i++) {
		cin >> f[i].b;
		if (f[i].a == 1) {
			ans += f[i].b;
		}
	}
	double maxx = ans;
	int p = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i].a == 1) continue;
		double tmp = (1.0 * ans + f[i].b) / f[i].a;
		// cout << tmp << '\n';
		if (tmp > maxx) {
			p = i;
			maxx = tmp;
		}
	}
	ans += f[p].b;
	for (int i = 1; i <= n; i++) {
		if (f[i].a == 1) continue;
		if (p == i) continue;
		ans = ans * f[i].a % mod;
	}
	cout << ans << '\n';
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}