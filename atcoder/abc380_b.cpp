#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
vector<int> ans;
int main () {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '|') {
			ans.push_back(cnt);
			cnt = 0;
		}else{
			cnt++;
		}
	}
	for (int i = 1; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}