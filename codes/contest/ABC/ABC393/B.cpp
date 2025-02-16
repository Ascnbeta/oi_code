#include <bits/stdc++.h>
using namespace std;
string s;
int n,ans;
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> s;n = s.size();
	s = ' ' + s;
	for (int i = 1; 1+2*i<=n; i++) {
		for (int j = 1; j+2*i <= n; j++) {
			if (s[j] == 'A' && s[j+i] == 'B' && s[j+2*i] == 'C') ++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}