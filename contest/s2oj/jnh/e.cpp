#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5+5;
ll n,k,sum;
ll a[maxn];
inline bool check(ll x) {
    ll cnt = 0;
    if (a[n] > x) return false;
    int l = 1,r = n;
    for (; l <= r;) {
        if (l != r) {
            if (a[l] + a[r] <= x) ++cnt,++l,--r;
            else ++cnt,--r;
        }else{
            ++cnt;
            --r;
        }
    }
    return cnt <= k;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i],sum += a[i];
    ll l = 1,r = sum,ans = sum;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}