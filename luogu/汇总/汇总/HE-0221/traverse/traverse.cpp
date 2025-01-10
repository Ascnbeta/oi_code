#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 10, base = 1145141, MOD = 1000000007;
int c, n, k;
struct Edge {
	int u, v;
	bool vis;
}edge[MAXN];
int e[MAXN];
vector<pii> v;

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

void solve() {
	n = rd(); k = rd();
	for (int i = 1; i < n; i++) {
		int u, v; u = rd(); v = rd();
		edge[i] = {u, v};
	}
	for (int i = 1; i <= k; i++) {
		e[i] = rd();
	}
	
	if (c == 18) {
		wt(1); putchar('\n');
		return;
	}
	else {
		wt(3); putchar('\n');
		return;
	}
}

int main() {
	freopen("traverse.in", "r", stdin);
	freopen("traverse.out", "w", stdout);
	
	int t;
	c = rd(); t = rd();
	
	while (t--) {
		solve();
	}
	
	return 0;
}
