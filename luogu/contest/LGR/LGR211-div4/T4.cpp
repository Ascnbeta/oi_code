#include <bits/stdc++.h>
using namespace std;
int n;
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k,sum = 0;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int s;
			cin >> s;
			sum += s;
		}
		double d = (1.0*k-1.0*sum)/(1.0*k);
		printf("%.8f\n",d);
	}
	return 0;
}