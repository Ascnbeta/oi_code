#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 10, MOD = 1000000007;
int n, m;
struct Node {
	int p, x;
	bool operator< (const Node node) const {
		return p < node.p;
	}
};
vector<Node> vec;
ll v;
map<int, int> mp;
struct Mat {
	int a00, a01, a10, a11;
	Mat() {
		a00 = a01 = a10 = a11 = 0;
	}
};
Mat operator* (Mat a, Mat b) {
	Mat res;
	res.a00 = (1ll * a.a00 * b.a00 + 1ll * a.a01 * b.a10) % MOD;
	res.a01 = (1ll * a.a00 * b.a01 + 1ll * a.a01 * b.a11) % MOD;
	res.a10 = (1ll * a.a10 * b.a00 + 1ll * a.a11 * b.a10) % MOD;
	res.a11 = (1ll * a.a10 * b.a01 + 1ll * a.a11 * b.a11) % MOD;
	return res;
}

inline int rd() {
	int x = 0, k = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') k = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return k * x;
}
inline void wt(int num) {
	if (num < 0) putchar('-'), num = -num;
	int st[25], top = 0;
	do {st[++top] = num % 10; num /= 10;} while (num);
	while (top) putchar(st[top--] + '0');
}

ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}
ll calc(ll num) {
	Mat res, qwq;
	res.a00 = 1; res.a10 = res.a11 = 0;
	res.a01 = (v - 1) * qpow(v, MOD - 2) % MOD;
	qwq.a00 = v;
	qwq.a10 = v * v % MOD;
	qwq.a01 = 0;
	qwq.a11 = v * v % MOD;
	num -= 1;
	while (num) {
		if (num & 1) res = res * qwq;
		qwq = qwq * qwq;
		num >>= 1;
	}
	return res.a00;
}

void solve() {
	n = rd(); m = rd(); v = rd();
	bool flag = 1;
	for (int i = 1; i <= m; i++) {
		int p, x; p = rd(); x = rd();
		if (mp.count(p) && mp[p] != x) {
			flag = 0;
		}
		else if (!mp.count(p)) {
			mp[p] = x;
			vec.push_back({p, x});
		}
	}

	if (!flag) {
		wt(0); putchar('\n');
		return;
	}

	sort(vec.begin(), vec.end());
	ll ans = calc(n - vec.back().p + 1);
	for (int i = vec.size() - 2; i >= 0; i--) {
		int l = vec[i + 1].p - vec[i].p;
		if (l == 1) {
			ans = ans * ((v - 1) * v % MOD + 1) % MOD;
		}
		else {
			ll tmp = 1;
			tmp = tmp * qpow(v, l - 1) * (v * v % MOD - v + 1) % MOD;
			tmp = (tmp + (calc(l) - qpow(v, l - 1)) * v % MOD * v) % MOD;
			ans = ans * tmp % MOD;
		}
	}
	ans = ans * qpow(v, 2 * (vec[0].p - 1)) % MOD;

	wt((ans + MOD) % MOD); putchar('\n');
}

void init() {
	mp.clear();
	vec.clear();
}

int main() {
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);

	int t = rd();
	while (t--) {
//		cerr << t << endl;
		solve();
		init();
	}

	return 0;
}

/*
3
2 1 2
1 1
2 2 2
1 1
2 2
2 2 2
1 1
1 2
*/
/*
3
5 1 2
1 2
6 5 2
4 2
5 1
4 2
2 2
2 1
7 1 2
4 1
*/

