#include <bits/stdc++.h>
#define int long long

using namespace std;
int K,D,A,t,tmp,ans;
#ifdef int
signed main () {
	cin >> t;
	int x = t;
	while (t--) {
		scanf("%lld/%lld/%lld",&K,&D,&A);
		if (K - D >= 10) {
			if (K*(K-D)+A>tmp) {
				tmp = K*(K-D)+A;
				ans = x - t;
			}
		}else if (K >= D) {
			if ((K-D+1)*3+A >tmp) {
				tmp = (K-D+1)*3+A;
				ans = x - t;
			}
		}else{
			if (A * 2 > tmp) {
				tmp = A * 2;
				ans = x - t;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
#else
int main() {
	

	return 0;
}
#endif

