#include <bits/stdc++.h>
using namespace std; 
const int N = 1e5 + 100; 

int n, T; char s1[N], s2[N], t1[N], t2[N]; 
int sum1[N], sum2[N], pre1[N], pre2[N]; 
bool flager[N]; int ans, nums; 

struct node {
	int pos, id, num1, num2; 
	node(int P = 0, int I = 0, int N1 = 0, int N2 = 0) : pos(P), id(I), num1(N1), num2(N2) {}
}; vector <node> v; 

int num1[N], num2[N]; 

inline bool check1() {
	int lst = 0; 
	for (int i = 1; i <= n; ++ i) pre1[i] = num1[i] + pre1[i - 1]; 
	if (pre1[n] != sum1[n]) return false; 
	for (int i = 1; i <= n; ++ i) {
		if (t1[i] == '0') {
			if (num1[i] != s1[i] - '0') return false; 
			if (pre1[i - 1] - pre1[lst] != sum1[i - 1] - sum1[lst]) return false; 
			lst = i; 
		}
	}
	return true; 
}
inline bool check2() {
	int lst = 0; 
	for (int i = 1; i <= n; ++ i) pre2[i] = num2[i] + pre2[i - 1]; 
	if (pre2[n] != sum2[n]) return false; 
	for (int i = 1; i <= n; ++ i) {
		if (t2[i] == '0') {
			if (num2[i] != s2[i] - '0') return false; 
			if (pre2[i - 1] - pre2[lst] != sum2[i - 1] - sum2[lst]) return false; 
			lst = i; 
		}
	}
	return true; 
}
inline int Find() {
	int ans = 0; 
	for (int i = 1; i <= n; ++ i) {
		if (num1[i] == num2[i]) ++ ans; 
	}
	return ans; 
}

void dfs2(int x) {
	if (x == n + 1) {
		if (check2()) ans = max(ans, Find()); 
		return; 
	}
	num2[x] = 0; 
	dfs2(x + 1); 
	num2[x] = 1; 
	dfs2(x + 1); 
}

void dfs1(int x) {
	if (x == n + 1) {
		if (check1()) dfs2(1); 
		return; 
	}
	num1[x] = 1; 
	dfs1(x + 1); 
	num1[x] = 0; 
	dfs1(x + 1); 
}

signed main() {
	freopen("edit.in", "r", stdin); 
	freopen("edit.out", "w", stdout); 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	cin >> T; 

	while (T --) {
		cin >> n; int lst = 0; bool flag1 = 0, flag2 = 0; 
		cin >> s1 + 1 >> s2 + 1 >> t1 + 1 >> t2 + 1; 
		s1[n + 1] = 'a', s2[n + 1] = 'b'; 
		for (int i = 1; i <= n; ++ i) {
			if (t1[i] != t2[i]) flag1 = 1; 
			if (s1[i] != s2[i]) flag2 = 1; 
			sum1[i] = sum1[i - 1] + s1[i] - '0', sum2[i] = sum2[i - 1] + s2[i] - '0'; 
		}
		if (!flag1 || !flag2) {
			cout << n << '\n'; 
			continue; 
		}
		if (n <= 10) {
			ans = 0; 
			dfs1(1); 
			cout << ans << '\n'; 
		}
	}
}
