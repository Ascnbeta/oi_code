#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[14];
int main () {
	cin >> n;
	while(n) {
		int p = n % 10;
		cnt[p]++;
		n /= 10;
	}
	if (cnt[1] == 1 && cnt[2] == 2 && cnt[3] == 3) puts("Yes");
	else puts ("No");
	return 0;
}