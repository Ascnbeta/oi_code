#include <bits/stdc++.h>
using namespace std;
int n;
int a[300005];
bool up = true, down = true;
vector<int> ans;
int main () {
	cin >> n;
	
	if (n == 3 ){cout << 1 << ' ';
	for (int i = n; i >= 2; i--) cout <<i << ' '; 
	return 0;}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i >= 2 && a[i-1]<a[i]) {
			down = false;
		}else if (i >= 2 && a[i-1]>a[i]){
			up = false;
		}
	}
	if (down || up) {
		for (int i = 1; i <= n; i++) cout << i << ' ';
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		if (a[i-1] > a[i] && a[i+1] > a[i]) {
			if (a[i-1] > a[i+1]) {
				for (int j = i; j >= 1; j--) {
					cout << a[j] << ' ';
				}
				for (int j = i + 1; j <= n; j++) {
					cout << a[j] << ' ';
				}
				return 0;
			}
		}
	}
}