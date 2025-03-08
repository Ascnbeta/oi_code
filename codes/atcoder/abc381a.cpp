#include <bits/stdc++.h>
// #define int long long

using namespace std;
int n;
string s;
#ifdef int
signed main () {
	

	return 0;
}
#else
int main() {
	cin >> n;
	cin >> s;
	if (n % 2 != 1) {puts("No");return 0;}
	int mid = (n + 1) / 2;
	s = ' ' + s;
	for (int i = 1; i < mid; i++) {
		if (s[i] != '1') {
			puts("No");
			return 0;
		}
	}
	if (s[mid] != '/') {
		puts("No");
		return 0;
	}
	for (int i = 1; i < mid; i++) {
		if (s[i] != '2') {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}
#endif

