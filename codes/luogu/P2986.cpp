<<<<<<< HEAD
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn =5e6+10;
int n,sa,sb,sc,sd,mod;
int a[maxn],b[maxn];
inline int f(int x) {
	return ((((sa%mod*x%mod)%mod*x%mod)*x%mod)%mod+((sb%mod*x%mod)%mod*x%mod)%mod+(sc%mod*x%mod)%mod+sd%mod)%mod;
}
inline bool check(int x) {
	a[1] = b[1] - x;
	for (int i = 2; i <= n; i++) {
		int t = abs(b[i]-a[i-1]);
		if (t <= x) a[i] = a[i-1];
		else if (b[i] > a[i-1]) a[i] =  b[i] - x;
		else return false;
	}
	return true;
}
signed main () {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> sa >> sb >> sc >> sd >> a[1] >> mod;
	for (int i = 2; i <= n; i++) {
		a[i] = (f(a[i-1])%mod+f(a[i-2])%mod)%mod;
	}
	for (int i = 1; i <= n; i++) b[i] = a[i];
	int l = 0,r = (int)1e9+1000,ans = r;;
	while (l <= r) {
		
		int mid = (l + r) >> 1;
		// cout << mid << '\n';
		if (check(mid)) {
			// puts("qwq");
			ans = mid;
			r = mid - 1;
		}else{
			// puts("awa");
			l = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
=======
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn =5e6+10;
int n,sa,sb,sc,sd,mod;
int a[maxn],b[maxn];
inline int f(int x) {
	return ((((sa%mod*x%mod)%mod*x%mod)*x%mod)%mod+((sb%mod*x%mod)%mod*x%mod)%mod+(sc%mod*x%mod)%mod+sd%mod)%mod;
}
inline bool check(int x) {
	a[1] = b[1] - x;
	for (int i = 2; i <= n; i++) {
		int t = abs(b[i]-a[i-1]);
		if (t <= x) a[i] = a[i-1];
		else if (b[i] > a[i-1]) a[i] =  b[i] - x;
		else return false;
	}
	return true;
}
signed main () {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> sa >> sb >> sc >> sd >> a[1] >> mod;
	for (int i = 2; i <= n; i++) {
		a[i] = (f(a[i-1])%mod+f(a[i-2])%mod)%mod;
	}
	for (int i = 1; i <= n; i++) b[i] = a[i];
	int l = 0,r = (int)1e9+1000,ans = r;;
	while (l <= r) {
		
		int mid = (l + r) >> 1;
		// cout << mid << '\n';
		if (check(mid)) {
			// puts("qwq");
			ans = mid;
			r = mid - 1;
		}else{
			// puts("awa");
			l = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}