#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,k,si;
int res[56];
void solve(int d,int s) {
	int mid = (s + 1) / 2;
	if (mid == k) {
		cout << d << endl;
		exit(0);
	}
	if (k > mid) k -= mid;
	solve(d-1,res[d-1]-1);
}
signed main () {
	cin >> n >> k;
	int tmp = 1;
	res[0] = tmp;
	for (int i = 1; i <= n ; i++) {
		tmp *= 2;
		res[i] = tmp;
//		cout <<res[i] << ' ';
	}
	si = res[n] - 1;
	solve(n,si);
	return 0;
}
