#include <bits/stdc++.h>
using namespace std;
int T,n,p[1000004];
int main () {
	cin >> T;
	while(T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
		}
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 1) {
				cout << 1;
			}else{
				cout << 0;
			}
		}
		cout << '\n';
	}
	return 0;
}