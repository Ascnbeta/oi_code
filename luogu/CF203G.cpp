#include <bits/stdc++.h>
using namespace std;
int t;
int main () {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << "1 0" << endl;
		int x;
		cin >> x;
		cout << "1 00" << endl;
		int y;
		cin >> y;
		cout << "1 01" << endl;
		int z;
		cin >> z;
		if (z == x - y) {
			cout << "0 " << n << " 1" << endl;
		}else{
			cout << "0 " << n << " 0" << endl;
		}
		int op;
		cin >> op;
		if (op == -1) return 0;
	}
	return 0;
}