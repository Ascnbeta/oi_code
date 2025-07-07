#include <bits/stdc++.h>
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
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
ll k;
ll p[60],cnt[60],tot;
inline void solve(ll x) {
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            p[++tot] = i;
            while (x % i == 0) x /= i,++cnt[tot];
        }
    }
    if (x > 1) p[++tot] = x,++cnt[tot];
}
ll ans = 1;
inline ll binpow(ll base,int b) {
    ll ret = 1;
    while (b) {
        if (b&1) ret *= base;
        base *= base;
        b >>= 1; 
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    scanf("%lld",&k);
    if (k == 1) {
        puts("-1");
        return 0;
    }
    solve(k);
    for (int i = 1; i <= tot; i++) {
        if (cnt[i] % 2 == 1) {
            ans *= binpow(p[i],(cnt[i]+1)/2);
        }else{
            ans *= binpow(p[i],cnt[i]/2);
        }
    }
    if (ans % k == 0) puts("-1");
    else printf("%lld",ans);
    return 0;
}