#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+30;
int k,n,ans = -1;
int a[maxn],sum[maxn],c[20];
int f[70000],tot;
inline int find(int val,int s) {
    int l = s,r = n,ret = s;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (sum[mid] <= val) ret = mid,l = mid+1;
        else r = mid-1;
    }
    assert(ret!=-1);
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> k >> n;
    for (int i = 1; i <= k; i++) cin >> c[i],tot += c[i];
    for (int i = 1; i <= n; i++) cin >> a[i],sum[i]=sum[i-1]+a[i];
    // cout << sum[2] << '\n';
    for (int i = 1; i < (1<<k); i++) {
        for (int j = 1; j <= k; j++) {
            if ((i>>(j-1))&1) {
                int t = i-(1<<(j-1));
                f[i] = max(f[i],(int)(upper_bound(sum+f[t],sum+n+1,c[j]+sum[f[t]])-sum-1));
            }
        }
        if (f[i] == n) {
            int t = i,cnt = 1,tmp = 0;
            while (t) {
                if ((t&1)) tmp += c[cnt];
                t >>= 1;
                ++cnt;
            }
            // cout << tmp << '\n';
            ans = max(ans,tot-tmp);
        }
        // cout << i << ' ' << f[i] << '\n';
    }
    cout << ans << '\n';
    return 0;
}   