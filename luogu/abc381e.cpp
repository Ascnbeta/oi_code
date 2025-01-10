#include <bits/stdc++.h>
// #define int long long

using namespace std;
int n,q,l,q;
string s;
int s1[100004],s2[100004];
vector<int> p;
int main() {
	cin >> n >> q;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			s1[i] = s1[i-1]+1;
			s2[i] = s2[i-1];
		}else if (s[i] == '2') {
			s1[i] = s1[i-1];
			s2[i] = s2[i-1]+1;
		}else{
			p.push_back(i);
			s1[i] = s1[i-1];
			s2[i] = s2[i-1];
		}
	}
	for (int i = 0; i < p.size(); i++) {

	}
	while (q--) {
		int l,r;
		cin >> l >> r;


	}
	return 0;
}


