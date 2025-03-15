#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e7+30;
int n,A,B,C,a[maxn];
double ans;
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    scanf("%lld%lld%lld%lld%lld", &n, &A, &B, &C, a + 1);
    for (int i = 2; i <= n; i++)
	    a[i] = ((long long) a[i - 1] * A + B) % 100000001;
    for (int i = 1; i <= n; i++)
	    a[i] = a[i] % C + 1;
    for (int i = 1; i <= n; i++) {
        if (i != n) {
            ans += 1.0 / max(a[i],a[i+1]);
        }else{
            ans += 1.0 / max(a[n],a[1]);
        }
    }
    cout << fixed << setprecision(3) << ans << '\n';
    return 0;
}