#include <bits/stdc++.h>

#define int long long

const int N = 114514, mod = 1e9 + 7;

std::map<int, int> a;

int t, n, m, v, c, d;
//int fac[N], ifac[N];

int read() {
	int res = 0, i = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') i = -i;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * i;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int qpow(int a, int b) {
//	write(a), putchar(' '), write(b), puts("");
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void sub1() {
    write(qpow(v, (n << 1) - 2)), puts("");
}

std::pair<int, int> vec[N];
int cnt, x, y, tot, ans;
void sub2() {
//    write(114514), puts("");
	x = 1;
	cnt = 0;
	ans = qpow(v, (n << 1) - 2);
	while (true) {
//		write(x), putchar(' '), write(y), puts("");
		while (!a[x] && x <= n) ++x;
		if (x > n) break;
		y = x + 1;
		while (!a[y] && y <= n) ++y;
		if (y > n) break;
		vec[++cnt].first = x, vec[cnt].second = y;
		x = y;
	}
//	for (int i = 1; i <= cnt; ++i)
//		write(vec[i].first), putchar(' '), write(vec[i].second), puts("");
	for (int i = 1; i < 1 << cnt; ++i) {
//		write(i), puts("");
		x = 0, y = 0, tot = 0;
		for (int j = 0; j < cnt; ++j) {
//			write(j), puts("-");
			if ((1 << j) & i) {
				++tot;
				x += vec[j + 1].second - vec[j + 1].first - 1;
				y += vec[j + 1].second - vec[j + 1].first;
			}
		}
//		write(x), putchar(' '), write(y), puts("");
		if (tot & 1) ans = (ans - qpow(v, x) * qpow(v * v % mod, n - 1 - y) % mod + mod) % mod;
		else ans = (ans + qpow(v, x) * qpow(v * v % mod, n - 1 - y) % mod) % mod;
	}
	write(ans), puts("");
}

//int C(int n, int m) {
//	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
//}

void subA() {
//	fac[0] = 1;
//	for (int i = 1; i <= n; ++i)
//		fac[i] = fac[i - 1] * i % mod;
//	ifac[0] = ifac[1] = 1;
//	for (int i = 2; i <= n; ++i)
//		ifac[i] = (mod - mod / i) * ifac[mod % i] % mod;
//	for (int i = 1; i <= n; ++i)
//		ifac[i] = ifac[i - 1] * ifac[i] % mod;
//	for (int i = 0; i <= n; ++i)
//		write(ifac[i] * fac[i] % mod), putchar(' ');
//	puts("");
//	ans = 0;
//	for (int i = 0; i < n; ++i)
//		if (i & 1)
//			ans = (ans - C(n, i) * qpow(v * v % mod, n - 1 - i) % mod + mod) % mod;
//		else
//			ans = (ans + C(n, i) * qpow(v * v % mod, n - 1 - i) % mod) % mod;
//	write(ans), puts("");
	write(qpow((v * v % mod - (v - 1) + mod) % mod, n - 1)), puts("");
}

void work() {
    n = read(), m = read(), v = read();
    a.clear();
	bool keyA = true;
	if (n != m) keyA = false;
    for (int i = 1; i <= m; ++i) {
        c = read(), d = read();
		if (c != i) keyA = false;
        if (a[c] && a[c] != d) {
            puts("0");
            return;
        }
        a[c] = d;
    }
	if (keyA && n > 12) return subA(), void();
    if (m == 1) return sub1(), void();
    return sub2(), void();
}

signed main() {
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
    t = read();
//    t = 2;
//    --t;
    while (t--) work();
    return 0;
}

/*
1
10 11 2
10 2
7 2
7 2
2 2
3 2
4 2
10 2
7 2
10 2
3 2
3 2

*/
