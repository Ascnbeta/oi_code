#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6+5;
int n;
int a[maxn];
ll ans = 0;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1,r = n;
    while (l < r) {
        ll t1 = 1ll*a[l]*a[l+1];
        ll t2 = 1ll*a[r]*a[r-1];
        if (a[l] > a[r]) {
            ans += t1;
            ++l;
        }else if(a[l] <= a[r]){
            ans += t2;
            --r;
        }
    }
    ans += a[l];
    cout << ans << '\n';
    return 0;
}