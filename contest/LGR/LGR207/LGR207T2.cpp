#include <bits/stdc++.h>
// #define int long long

using namespace std;
int a,b,c,k;
#ifdef int
signed main () {
	
	return 0;
}
#else
int main() {
	cin >> a >> b >> c >> k;
	if (a + b >= k) {
		cout << "Yes" << '\n';
	}else{
		cout << "No" << '\n';
	}
	if (a + c >= k) {
		cout << "Yes" << '\n';
	}else{
		cout << "No" << '\n';
	}
	if (c + b >= k) {
		cout << "Yes" << '\n';
	}else{
		cout << "No" << '\n';
	}
	return 0;
}
#endif

