#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
inline bool is_prime(int x) {
	if (x == 1 || x == 0) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i+=2) {
		if (x % i == 0) return false;
	}
	return true;
}
inline int labs(int x) {
	return ((x>=0)?(x):(-x));
}
int ans[4005];
void dfs(int x,int y,int p) {
	if (p > 20) return;
	if (is_prime(labs(x-y))) {
		cout << p << '\n';
		for (int i = 1; i <= p - 1; i++) cout << ans[i] << ' ';
		cout << y;
		exit(0);
	}
	if (x != 2) {
		if (is_prime(x-2)) {
			ans[p] = x-2;
			dfs(x-2,y,p+1);
		}
		if (is_prime(x+2)) {
			ans[p] = x+2;
			dfs(x+2,y,p+1);
		}
		if (is_prime(x-2)) {
			ans[p] = 2;
			dfs(2,y,p+1);
		}
	}else{
		if (is_prime(y+2)) {
			ans[p] = y+2;
			dfs(y+2,y,p+1);
		}
	} 
}
signed main () {
	cin >> a >> b;
	if (is_prime(labs(a-b))) {
		printf("%d\n%lld %lld\n",2,a,b);
		return 0;
	}
	ans[1] = a;
	dfs(a,b,2);
	puts("-1");
	return 0;
}