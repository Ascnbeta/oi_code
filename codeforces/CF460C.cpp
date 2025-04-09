#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+30;
int a[maxn];
int cf[maxn],cf2[maxn];
int n,w,m;
inline bool check(int x) {
    int now = 0,cnt = 0;
    memcpy(cf2,cf,sizeof(cf));
    for (int i = 1; i <= n; i++) {
        now += cf2[i];
        if (now < x) {
            int p = x - now;
            cf2[i] += p,cf2[min(n+1,i+w)] -= p;
            now += p;
            cnt += p;
        }
        if (cnt > m) return false;
    }
    return true;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++) cin >> a[i],cf[i] = a[i]-a[i-1];
    int l = 1,r = 1e9+1e5,ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}