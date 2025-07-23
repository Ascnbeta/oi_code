#include <iostream>
typedef long long ll;
using namespace std;
template <typename T>
inline void read(T &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
template <typename T>
inline void write(T x) {
    if (x<0) x=-x,putchar('-');
    if (x/10) write(x/10);
    putchar('0'+x%10);
}
const ll mod = 1e9+7;
int n;ll f[24],s;
ll ans,inv[24];
inline ll binpow(ll base,int b) {
    ll ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret;
}
inline ll C(ll n,ll m) {
    if (n == 0 && m == 0) return 1;
    if (m > n || n <= 0) return 0;
    ll ret = 1;
    for (ll i = 1; i <= m; i++) ret = ret * inv[i] % mod;
    for (ll i = n; i >= n-m+1; i--) ret = ret * (i%mod) % mod;
    return ret;
}
ll sum;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(s);
    for (int i = 1; i <= 20; i++) inv[i] = binpow(i,mod-2);
    for (int i = 1; i <= n; i++) read(f[i]),sum += f[i];
    // write(C(10,5)),putchar('\n');
    if (sum < s) {
        write(0);return 0;
    }
    ans = C(s+n-1,n-1);
    for (int t = 1; t < (1<<n); t++) {
        ll tmp = 1,ts = s;
        int cnt = __builtin_popcount(t);
        if (!(cnt&1)) tmp=-tmp;
        for (int i = 1; i <= n; i++) {
            if ((t>>(i-1))&1) ts -= f[i]+1;
        }
        tmp *= C(ts+n-1,n-1);
        ans = ((ans-tmp)%mod+mod)%mod;
    }   
    write(ans);
    return 0;
}