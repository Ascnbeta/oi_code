#include <bits/stdc++.h>
// #define int long long

using namespace std;
string s;
int n,ans = 1;
vector<int> p;
#ifdef int
signed main () {
	
	return 0;
}
#else
int main() {
	cin >> n >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '/') p.push_back(i);
	}
	for (int i = 0; i < p.size(); i++) {
		int tmp = 1;
		for (int j = 1; p[i] - j >= 1 && p[i] + j <= n; j++) {
			if (s[p[i]-j] == '1' && s[p[i]+j] == '2') {
				tmp += 2;
			}else{
				break;
			}
		}
		ans = max(ans,tmp);
	}
	cout << ans << '\n';
	return 0;
}
#endif

