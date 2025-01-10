#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
const int N = 1e5 + 10;

int T, n, tot1, tot2, ans;
int k1[N], k2[N];
int b1[N][5], b2[N][5], a[2], b[2];
char s1[N], s2[N], t1[N], t2[N];
struct zx { int z, y; };

void Main () {
	for(int i = 1; i <= tot1; ++i) b1[i][0] = b1[i][1] = k1[i] = 0;
	for(int i = 1; i <= tot2; ++i) b2[i][0] = b2[i][1] = k2[i] = 0;
	tot1 = tot2 = 1, ans = 0;
	s1[n + 1] = '3', s2[n + 1] = '4';
	for(int i = 1; i <= n; ++i) {
		if(t1[i] == '0') k1[++tot1] = i;
		else b1[tot1][s1[i] - '0']++;
	}
	for(int i = 1; i <= n; ++i) {
		if(t2[i] == '0') k2[++tot2] = i;
		else b2[tot2][s2[i] - '0']++;
	}
	k1[tot1 + 1] = n + 1, k2[tot2 + 1] = n + 1;
	int j = 1, i = 1;
	while(1) {
		if(j > tot2 || i > tot1) break;
		cout << k1[i + 1] << ' ' << k2[i + 1] << endl;
		if(k1[i + 1] >= k2[j + 1]) {
			ans += min(b1[i][0], b2[j][0]), b1[i][0] = max(b1[i][0] - b2[j][0], 0);
			ans += min(b1[i][1], b2[j][1]), b1[i][1] = max(b1[i][1] - b2[j][1], 0);
			if(k1[i + 1] == k2[j + 1]) ans += s1[k1[i + 1]] == s2[k2[j + 1]], i++;
			else if(b1[i][s2[k2[j + 1]] - '0']) ans++, b1[i][s2[k2[j + 1]] - '0']--;
			j++;
		} else {
			ans += min(b1[i][0], b2[j][0]), b2[j][0] = max(b2[j][0] - b1[i][0], 0);
			ans += min(b1[i][1], b2[j][1]), b2[j][1] = max(b2[j][1] - b1[i][1], 0);
			if(b2[j][s1[k1[i + 1]] - '0']) ans++, b2[j][s1[k1[i + 1]] - '0']--;
			i++;
		}
		cout << ans << endl;
	}
	cout << ans << endl;
}

void solve () {
	cin >> n >> (s1 + 1) >> (s2 + 1) >> (t1 + 1) >> (t2 + 1);
	for(int i = 1; i <= n; ++i)
		a[i] = b[i] = 0;
	bool flag = 1, key = 1;
	for(int i = 2; i <= n; ++i)
		if(s1[i] != s1[i - 1]) flag = 0;
	for(int i = 1; i <= n; ++i)
		if(t1[i] != t2[i]) key = 0;
	if(flag) {
		for(int i = 1; i <= n; ++i)
			a[s2[i] - '0']++;
		cout << a[s1[1] - '0'] << endl;
	} else if(key) {
		for(int i = 1; i <= n; ++i) {
			if(t1[i] == '0') {
				ans += s1[i] == s2[i];
				ans += min(a[0], b[0]) + min(a[1], b[1]);
				a[0] = a[1] = b[0] = b[1] = 0;
			} else {
				a[s1[i] - '0']++, b[s2[i] - '0']++;
			}
		cout << ans << endl;
		}
	} else Main();
}

int main () {
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	cin >> T;
	while(T--) solve();
	return 0;
}
