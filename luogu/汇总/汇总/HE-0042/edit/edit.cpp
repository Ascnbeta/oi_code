#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n;
char s1[N], s2[N], t1[N], t2[N];
struct arg { int l, r; } a1[N], a2[N];
int cnt1, cnt2, index[N], zero1[N], one1[N], zero2[N], one2[N], ans;
void solv() {
	ans = 0, cnt1 = 0, cnt2 = 0;
	memset(index, 0, sizeof(index));
	for (int i = 0; i < N; i++) a1[i].l = 0, a1[i].r = 0;
	for (int i = 0; i < N; i++) a2[i].l = 0, a2[i].r = 0;
	memset(zero1, 0, sizeof(zero1));
	memset(zero2, 0, sizeof(zero2));
	memset(one1, 0, sizeof(one1));
	memset(one2, 0, sizeof(one2));
	cin >> n;
	scanf("%s%s%s%s", s1 + 1, s2 + 1, t1 + 1, t2 + 1);
	for (int i = 1; i <= n; i++) {
		zero1[i] = zero1[i - 1] + (s1[i] == '0');
		zero2[i] = zero2[i - 1] + (s2[i] == '0');
		one1[i] = one1[i - 1] + (s1[i] == '1');
		one2[i] = one2[i - 1] + (s2[i] == '1');
	}
	for (int i = 1; i <= n; ) {
		cnt1++;
		if (t1[i] == '0') { a1[cnt1].l = i, a1[cnt1].r = i; i++; }
		else {
			a1[cnt1].l = i;
			for (; i <= n; i++) if (t1[i] == '0') break;
			a1[cnt1].r = i - 1;
		}
	}
	for (int i = 1; i <= n; ) {
		cnt2++;
		if (t2[i] == '0') {
			a2[cnt2].l = i, a2[cnt2].r = i;
			index[i] = cnt2;
			i++;
		}
		else {
			a2[cnt2].l = i;
			for (; i <= n; i++) {
				index[i] = cnt2;
				if (t2[i] == '0') break;
			}
			a2[cnt2].r = i - 1;
		}
	}
	int czero1 = 0, czero2 = 0, cone1 = 0, cone2 = 0;
	for (int i = 1; i <= cnt1; i++) {
		if (a2[index[a1[i].r]].r == a1[i].r) {
			ans += min(one1[a1[i].r] - cone1, one2[a1[i].r] - cone2) + min(zero1[a1[i].r] - czero1, zero2[a1[i].r] - czero2);
			czero1 += zero1[a1[i].r] - czero1, czero2 += zero2[a1[i].r] - czero2;
			cone1 += one1[a1[i].r] - cone1, cone2 += one2[a1[i].r] - cone2;
		} else {
			int p = min(one1[a1[i].r] - cone1, one2[a2[index[a1[i].r]].r] - cone2);
			int q = min(zero1[a1[i].r] - czero1, zero2[a2[index[a1[i].r]].r] - czero2);
			ans += p + q;
			if (one1[a1[i].r] - cone1 > one2[a2[index[a1[i].r]].r] - cone2) {
				int tmp = one2[a2[index[a1[i].r]].r] - cone2;
				cone2 += tmp;
				czero2 += (a1[i].r - a1[i].l + 1) - tmp;
			} else if (zero1[a1[i].r] - czero1 > zero2[a2[index[a1[i].r]].r] - czero2) {
				int tmp = zero2[a2[index[a1[i].r]].r] - czero2;
				czero2 += tmp;
				cone2 += (a1[i].r - a1[i].l + 1) - tmp;
			} else {
				czero2 += zero1[a1[i].r] - czero1, cone2 += one1[a1[i].r] - cone1;
			}
			czero1 += zero1[a1[i].r] - czero1, cone1 += one1[a1[i].r] - cone1;
		}
	}
	cout << ans << endl;
}
int main() {
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) solv();
	return 0;
}
