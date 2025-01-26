#include <bits/stdc++.h>
using namespace std;
string s,t,tmp;
int k,cnt;
int main () {
	cin >> k >> s >> t;
	if (s.size() == t.size()) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != t[i]) ++cnt;
		}
		if (cnt <= 1) puts("Yes");
		else puts("No");
	}else if (s.size() == t.size()-1) {
		bool f = false;
		for (int i = 0,j = 0; i < s.size(); i++,j++) {
			if (s[i] != t[j] && !f) {
				++j;
				if (s[i] != t[j]) {
					puts("No");
					return 0;
				}
			}else if (s[i] != t[j] && f) {
				puts("No");
				return 0;
			}
		}
		puts("Yes");
	}else if (s.size()-1 == t.size()) {
		bool f = false;
		for (int i = 0,j = 0; i < t.size(); i++,j++) {
			if (t[i] != s[j] && !f) {
				++j;
				if (t[i] != s[j]) {
					puts("No");
					return 0;
				}
			}else if(t[i] != s[j] && f) {
				puts("No");
				return 0;
			}
		}
		puts("Yes");
	}else{
		puts("No");
	}
	return 0;
}