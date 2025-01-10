#include <bits/stdc++.h>
using namespace std;
int n;
struct num{
	int nxt;
}a[300005];
int h;
int main () {
	cin >> n;
	for (int i = 1; i <= n ; i++) {
		int x;
		cin >> x;
		if (x == -1) {
			h = i;
			continue;
		}
		a[x].nxt = i;
		
	}
	int tmp = h;
	while (tmp) {
		cout << tmp << ' ';
		tmp = a[tmp].nxt;
	}
	return 0;
}
