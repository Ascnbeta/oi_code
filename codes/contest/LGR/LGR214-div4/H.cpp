#include <bits/stdc++.h>
#define int long long
using namespace std;
int ai,aj,ak,bi,bj,bk;
int ci,cj,ck,di,dj,dk;
int ans = 1;
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> ai >> aj >> ak >> bi >> bj >> bk;
	cin >> ci >> cj >> ck >> di >> dj >> dk;
	if (ci > bi || ai > di) return puts("0"),0;
	else ans *= max(min(bi-ci+1,di-ai+1),1ll);
	if (cj > bj || aj > dj) return puts("0"),0;
	else ans *= max(min(bj-cj+1,dj-aj+1),1ll);
	if (ck > bk || ak > dk) return puts("0"),0;
	else ans *= max(min(bk-ck+1,dk-ak+1),1ll);
	cout << ans << '\n';
	return 0;
}