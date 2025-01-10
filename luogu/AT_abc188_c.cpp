#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	int num,val;
}a[65570];
int main () {
	cin >> n;
	n = pow(2,n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].val;
		a[i].num = i; 
	}
	while (n > 2) {
		for (int i = 1; i <= n; i+=2) {
			if (a[i].val < a[i+1].val) {
				a[i].val = a[i+1].val;
				a[i].num = a[i+1].num;
			}
		}
		for (int i = 1; i <= n/2; i++) {
			a[i].val = a[2*i-1].val;
			a[i].num = a[2*i-1].num;
		}
		n /= 2;
//		for (int i = 1; i <= n; i++) {
//			cout << a[i].num << ' ';
//		}
//		cout << '\n';
	}
	if (a[1].val < a[2].val) {
		cout << a[1].num << endl;
	}else{
		cout << a[2].num << endl;
	}
	return 0;
}
