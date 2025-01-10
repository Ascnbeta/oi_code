#include <iostream>
#include <cstdio>
using namespace std;
int t;
int n;
char s1[500005], s2[500005], t1[500005], t2[500005];
int sum1, sum2, cnt1[500005][3], cnt2[500005][3], belog1[500005], belog2[500005];
int main() {
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) belog1[i] = belog2[i] = 0;
		for (int i = 1; i <= sum1; i++) {
			for (int j = 0; j <= 1; j++) {
				cnt1[i][j] = 0;
			}
		}
		for (int i = 1; i <= sum2; i++) {
			for (int j = 0; j <= 1; j++) {
				cnt2[i][j] = 0;
			}
		}
		sum1 = sum2 = 0;
		for (int i = 1; i <= n; i++) cin >> s1[i];
		for (int i = 1; i <= n; i++) cin >> s2[i];
		for (int i = 1; i <= n; i++) cin >> t1[i];
		for (int i = 1; i <= n; i++) cin >> t2[i];
		int ls = 1;
		for (int i = 1; i <= n; i++) {
			if (t1[i] == '0') {
				sum1++;
				for (int j = ls; j < i; j++) {
					cnt1[sum1][s1[j] - '0']++;
					belog1[j] = sum1;
				}
				ls = i + 1;
			}
		}
		sum1++;
		for (int j = ls; j <= n; j++) {
			cnt1[sum1][s1[j] - '0']++;
			belog1[j] = sum1;
		}
		ls = 1;
		for (int i = 1; i <= n; i++) {
			if (t2[i] == '0') {
				sum2++;
				for (int j = ls; j < i; j++) {
					cnt2[sum2][s2[j] - '0']++;
					belog2[j] = sum2;
				}
				ls = i + 1;
			}
		}
		sum2++;
		for (int j = ls; j <= n; j++) {
			cnt2[sum2][s2[j] - '0']++;
			belog2[j] = sum2;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (t1[i] == '0') {
				if (t2[i] == '0') {
					if (s1[i] == s2[i]) ans++;
					continue;
				} else {
					if (cnt2[belog2[i]][s1[i] - '0']) {
						cnt2[belog2[i]][s1[i] - '0']--;
						ans++;
					}
				}
			} else if (t2[i] == '0') {
				if (t1[i] == '0') {
					if (s1[i] == s2[i]) ans++;
					continue;
				} else {
					if (cnt1[belog1[i]][s2[i] - '0']) {
						cnt1[belog1[i]][s2[i] - '0']--;
						ans++;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (t1[i] == '0' || t2[i] == '0') continue;
			if (cnt1[belog1[i]][0] && cnt2[belog2[i]][0]) {
				cnt1[belog1[i]][0]--;
				cnt2[belog2[i]][0]--;
				ans++;
			} else if (cnt1[belog1[i]][1] && cnt2[belog2[i]][1]) {
				cnt1[belog1[i]][1]--;
				cnt2[belog2[i]][1]--;
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}