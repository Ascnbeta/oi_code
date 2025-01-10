#include<bits/stdc++.h>
using namespace std;
#define N 100010
int t, n, ans, dif0, dif1, dif3, dif4, ai, bi, ci, di, ad;
string a, b, c, d;
bool l1, l2;
int main() {
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = dif0 = dif1 = dif3 = dif4 = 0;
		cin >> n >> a >> b >> c >> d;
		for (int i = 0; i < n; i++) {
			ai = a[i] - '0', bi = b[i] - '0', ci = c[i] - '0', di = d[i] - '0';
			if (ai == bi) ans++;
			else if (ai == 0 && ci) dif0++;
			else if (bi == 0 && di) dif1++;
			if (ai == bi);
			else if (ai == 1 && ci) dif3++;
			else if (bi == 1 && di) dif4++;
			ad = max(min(dif0, dif1), min(dif3, dif4));
			if ((!ci) && (!di)) {
				ans += 2 * ad;
				dif0 = dif1 = dif3 = dif4 = 0;
			} else if (!ci) {
				if (d[i - 1] == '0') ad = 0;
				ans += 2 * ad;
				dif1 -= min(dif0, dif1), dif4 -= min(dif3, dif4), dif0 = dif3 = 0;
			} else if (!di) {
				if (c[i - 1] == '0') ad = 0;
				ans += 2 * ad;
				dif0 -= min(dif0, dif1), dif3 -= min(dif3, dif4), dif1 = dif4 = 0;
			}
			if ((i == (n - 1)) && (ci && di)) {
				ans += 2 * ad;
			}
		}
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
