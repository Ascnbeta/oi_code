#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define int long long
using namespace std;
const int maxn = 1e6+20;
const int mod = 19930726;
int n,k,ans = 1;
string s;
inline int binpow(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1; 
    }
    return ret % mod;
}
int cf[2000002],d[1000003],sum[1000003];
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> k;
    cin >> s;
    s = ' ' + s;
    int l = 1,r = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = 1;
        if (i > r) {
            int x = i-1,y = i+1;
            while (x>=1&&y<=n&&s[x]==s[y]) {
                ++d[i];
                --x,++y;
            }
            
        }else{
            int j = r-i+l;
            if (j-d[j]+1 <= l) {
                d[i] = r-i;
                int x = i-d[i],y=r;
                while (x>=1&&y<=n&&s[x]==s[y]) {
                    ++d[i];
                    --x,++y;
                }
            }else{
                d[i] = d[j];
            }
        }
        if (r < i+d[i]-1) l = i-d[i]+1,r = i+d[i]-1;
        else if (r == i+d[i]-1) l = min(l,i-d[i]+1);
    }
    for (int i = 1; i <= n; i++) d[i] = d[i]*2-1;
    for (int i = 1; i <= n; i++) {
        cf[(d[i]+1)/2+1]--,cf[1]++;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + cf[i];
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << 2*i-1 << ' ' << sum[i] << '\n';
    // }
    for (int i = n; i >= 1; i--) {
        if (sum[i] == 0) continue;
        if (sum[i] <= k) {
            k -= sum[i];
            ans = ans * binpow(i*2-1,sum[i]) % mod;
        }else{
            ans = ans * binpow(i*2-1,k) % mod;
            k = 0;
        }
    }
    if (k != 0) puts("-1");
    else cout << ans << '\n';
    return 0;
}