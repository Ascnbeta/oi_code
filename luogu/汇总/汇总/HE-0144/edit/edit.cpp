#include <bits/stdc++.h>
#define ll long long
#define MyWife Cristallo
using namespace std;
const int N = 1e5 + 5;
int T, n, ar[N];
char a[N], b[N], c[N];
bool fa[N], fb[N];
int dfs(int pos, char x[], char y[], int ans) {
	if(pos >= n - 1) {
		if(x[n - 1] == y[n - 1]) ++ans;
		return ans;
	}
	if(ar[pos]) return ar[pos];
	bool lnk = 0;
	if(x[pos] == y[pos]) ++ans, lnk = 1;
	int cnt = ans;
	int ccc = dfs(pos + 1, x, y, ans), ddd = 0, eee = 0, fff = 0;
	if(fa[pos] && fa[pos + 1] && x[pos] != x[pos + 1] && fb[pos] && fb[pos + 1] && y[pos] != y[pos + 1]) {
		swap(x[pos], x[pos + 1]), swap(y[pos], y[pos + 1]);
		if(bool(x[pos] == y[pos]) != lnk) {
			if(x[pos] == y[pos]) ++ans;
			else --ans;
		}
		fff = dfs(pos + 1, x, y, ans);
		swap(x[pos], x[pos + 1]), swap(y[pos], y[pos + 1]);
		ans = cnt;
	} else if(fa[pos] && fa[pos + 1] && x[pos] != x[pos + 1]) {
		swap(x[pos], x[pos + 1]);
		if(bool(x[pos] == y[pos]) != lnk) {
			if(x[pos] == y[pos]) ++ans;
			else --ans;
		}
		ddd = dfs(pos + 1, x, y, ans);
		swap(x[pos], x[pos + 1]);
		ans = cnt;
	} else if(fb[pos] && fb[pos + 1] && y[pos] != y[pos + 1]) {
		swap(y[pos], y[pos + 1]);
		if(bool(x[pos] == y[pos]) != lnk) {
			if(x[pos] == y[pos]) ++ans;
			else --ans;
		}
		eee = dfs(pos + 1, x, y, ans);
	}
	return ar[pos] = max(ccc, max(ddd, max(eee, fff)));
}
int main() {
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%s%s", &n, a, b);
		scanf("%s", c);
		for(int i = 0; i < n; ++i) fa[i + 1] = c[i] - '0';
		scanf("%s", c);
		for(int i = 0; i < n; ++i) fb[i + 1] = c[i] - '0';
		printf("%d\n", dfs(0, a, b, 0));
		memset(ar, 0, sizeof(ar));
	}
	return 0;
}

