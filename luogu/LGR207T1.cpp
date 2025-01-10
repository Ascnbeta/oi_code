#include <bits/stdc++.h>
// #define int long long

using namespace std;
int t,a,b,c,d;
#ifdef int
signed main () {
	
	return 0;
}
#else
int main() {
	cin >> t >> a >> b >> c >> d;
	if (t == 0) {
		cout << a + b << '\n';
	}else{
		cout << max(a-c,0)+max(b-d,0) << '\n';
	}
	return 0;
}
#endif

 