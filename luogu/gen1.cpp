#include <bits/stdc++.h>
using namespace std;
int n,m;
int main () {
	cout << 2000 << ' ' << 2000 << '\n';
	for (int i = 1; i <= 2000; i++) {
		for (int j = 1; j <= 2000; j++) {
			if (i == 1 && j == 1) cout << 'S';
			else if (i == 2000 && j == 2000) cout << 'G';
			else cout << 'a';
		}
		cout << '\n';
	}
	return 0;
}