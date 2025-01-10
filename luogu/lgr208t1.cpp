#include <bits/stdc++.h>
// #define int long long

using namespace std;
int n,m,k,p,T;
#ifdef int
signed main () {
	
	return 0;
}
#else
int main() {
	cin >> T;
	while (T--) {
		cin >> n >> m >> k >> p;
		int a = p / n;
		int b = p % n;
		int c = p / m;
		int d = p % m;
		bool f1 = false,f2 = false;
		if (d > 0) {
			c += 1;
		}
		if (n - c > 0 || m - d >= k) f1 = true;
		if (b > 0) {
			a += 1;
		}
		if (m - a >= k || (b > 0 && m + 1 - a >= k)) f2 = true;
		if (f1&&f2) puts("Together");
		else if (f1||f2) puts("Chance");
		else puts("Divide");
	}
	
	return 0;
}
#endif

