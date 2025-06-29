#include <bits/stdc++.h>
typedef long long ll;
typedef __int128 i128;
using namespace std;
const int maxn = 2e5+5;
int n;
const ll mod = 998244353; 
ll a[maxn],b[maxn],ans;
ll cnt[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        cnt[i] = 1ll*i*(n-i+1);
        // cout << cnt << ' ';
        cnt[i] *= a[i];
    }
    sort(cnt+1,cnt+n+1,greater<i128>());
    sort(b+1,b+n+1);
    for (int i = 1; i <= n; i++) ans = (ans+cnt[i]%mod*1ll*b[i]%mod)%mod;
    cout << ans << '\n';
    return 0;
}