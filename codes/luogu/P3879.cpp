#include <bits/stdc++.h>
using namespace std;
unordered_map<string,bitset<1001>> mp;
int n,m;
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l;
		cin >> l;
		for (int j = 1; j <= l; j++) {
			string s;
			cin >> s;
			mp[s][i] = 1;
		}
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= 1000; j++) {
			if (mp[s][j] == 1) {
				cout << j << ' ';
			}
		}
		cout << '\n';
	}	
	return 0;
}