#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+30;
int n,a[maxn],b[maxn];
int cnta[maxn],cntb[maxn];
long long ans;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int l = n/2+1,r=n/2;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            ans += (long long)(i-1)*i/2+(long long)(n-i+1)*(n-i)/2;
            ans += min(i,n-i+1);
        }
    }
    for (int i = 1; i <= (n+1)/2; i++) {
        if (++r > n) break;
        ans += (long long)(cntb[a[r]]+cnta[b[r]])*(n-r+1);
        ++cnta[a[r]],++cntb[b[r]];
        if (--l > n) break;
        ans += (long long)(cntb[a[l]]+cnta[b[l]])*l;
        ++cnta[a[l]],++cntb[b[l]];
    }
    cout << ans << '\n';
    return 0;
}