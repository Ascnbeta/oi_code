#include <bits/stdc++.h>
// #define int long long

using namespace std;
string s;
int ch[156];
#ifdef int
signed main () {
	
	return 0;
}
#else
int main() {
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	if (n % 2 != 0) {
		puts("No");
		return 0;
	}
	for (int i = 1; i <= n/2; i++) {
		if (s[2*i-1] != s[2*i]) {
			puts("No");
			return 0;
		}
		if (ch[s[2*i-1]] == 2) {
			puts("No");
			return 0;
		}
        ch[s[2*i-1]]+= 2;
	}
	puts("Yes");
	return 0;
}
#endif

