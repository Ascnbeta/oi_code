#include <bits/stdc++.h>
using namespace std;
int n;
int l[20004],r[20004];
int f[20004][2];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
	f[1][0] = abs(r[1]-1)+abs(r[1]-l[1]);
	f[1][1] = abs(r[1]-1);
	for (int i = 2; i <= n; i++) {
		f[i][0] = min(f[i-1][0]+abs(r[i]-l[i])+abs(r[i]-l[i-1]),f[i-1][1]+abs(r[i-1]-r[i])+abs(r[i]-l[i]))+1;
		f[i][1] = min(f[i-1][0]+abs(r[i]-l[i])+abs(l[i]-l[i-1]),f[i-1][1]+abs(r[i-1]-l[i])+abs(r[i]-l[i]))+1;
	}
	cout << min(f[n][0]+abs(n-l[n]),f[n][1]+abs(n-r[n])) << '\n';
	return 0;
}