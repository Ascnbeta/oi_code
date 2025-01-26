#include <bits/stdc++.h>
// #define int long long

using namespace std;
int n,m;
int h[1004];
#ifdef int
signed main () {
	
	return 0;
}
#else
int main() {
	cin >> n >> m;
	while (m--) {
		string s;
		int l,r;
		cin >> s >> l >> r;
		if (s == "water") {
			for (int i = l; i <= r; i++) {
				h[i]++;
			}
		}else{
			int k,ans = 0;
			cin >> k;
			for (int i = l; i <= r; i++) {
				if (h[i] >= k) {
					h[i] = 0;
					ans++;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
#endif

