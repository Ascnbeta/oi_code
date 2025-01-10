#include <bits/stdc++.h>
using namespace std;
int n,m;
string s[10];
bool str[10];
int o[10];
bool check(int a,int b) {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (s[a][i] != s[b][i]) ++cnt;
		if (cnt > 1) return false;
	}
	return true; 
}
void dfs(int x,int p) {
	o[p] = x;
	str[x] = true;
	if (p == n) {
		cout << "Yes" << endl;
		exit(0);
	}
	for (int i = 1; i <= n; i++) {
		if (str[i]) continue;
		if (!check(x,i)) continue;
		dfs(i,p+1);
	}
	str[x] = false;
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n ; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n ; i++) {
		dfs(i,1);
	}
	cout << "No" << endl;
	return 0;
}
