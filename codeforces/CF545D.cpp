#include <bits/stdc++.h>
using namespace std;
int n,a[100005],tot,ans;
int main () {
	cin >> n; 
	for (int i = 1; i <= n ; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) {
		if (tot <= a[i]) {
			tot += a[i];
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
