#include <bits/stdc++.h>
using namespace std;
int n,d;
int t[103],l[103];
int main () {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> t[i] >> l[i];
	for (int i = 1; i <= d; i++) {
		int maxx = 0;
		for (int j = 1; j <= n; j++) {
			maxx = max(maxx,t[j]*(l[j]+i));
		}
		cout << maxx << '\n';
	}
	return 0;
}
