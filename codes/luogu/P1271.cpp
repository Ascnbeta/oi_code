#include <bits/stdc++.h>
using namespace std;
int n,m;
int p[1005];
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m ; i++) {
		int x;
		cin >> x;
		p[x]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= p[i]; j++) {
			cout << i << ' ';
		}
	}
	return 0;
}
