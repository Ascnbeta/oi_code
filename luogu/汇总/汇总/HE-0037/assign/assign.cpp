#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void print(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
	return;
}

typedef long long i64;
const int N = 1e5 + 5, mod = 1e9 + 7;

i64 qpow(i64 a, i64 b) {
	a %= mod;
	b %= (mod - 1);
	i64 ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int A[N];
map<int, int> mp;
void solve() {
	mp.clear();

	int n = read(), m = read(), V = read();
	bool e = false;
	int tot = 0;
	for(int i = 1; i <= m; i++) {
		int c = read(), d = read();
		if(mp.count(c)) {
			if(mp[c] != d) e = true;
		} else {
			A[++tot] = c;
			mp[c] = d;
		}
	}
	if(e) {
		print(0);
		putchar('\n');
		return;
	}
	
	sort(A + 1, A + tot + 1);
	i64 ans = qpow(V, 2 * (A[1] - 1 + n - A[tot]));
	for(int i = 1; i < tot; i++) {
		int l1 = A[i], l2 = A[i + 1];
		ans = 1ll * ans * (qpow(V, 2 * (l2 - l1)) - 1ll * (V - 1) * qpow(V, l2 - l1 - 1) % mod + mod) % mod;
	}
	
	print(ans);
	putchar('\n');
	return;
}
int main() {
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);

	int T = read();
	while(T--) solve();
	return 0;
}
