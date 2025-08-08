#include <bits/stdc++.h>

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
    putchar(x%10+'0');
}
const int maxn = 504;
const int mod = 1e9+7;
int n,d;
int a[maxn],l[maxn],r[maxn];
inline int binpow(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = 1ll*ret*base%mod;
        base = 1ll*base*base%mod;
        b >>= 1;
    }
    return ret;
} 
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
#ifndef LOCAL
    freopen("wizard.in","r",stdin);
    freopen("wizard.out","w",stdout);
#endif 
    // read(n),read(d);
    // for (int i = 1; i <= n; i++) read(a[i]);
    // for (int i = 1; i <= n; i++) read(l[i]),read(r[i]);
    printf("%lld\n",1ll*2*binpow(7,mod-2)%mod);
    if (n == 1) {
        int ll = a[1] - d,rr = a[1] + d;
        ll = max(1,ll);
        if (ll <= r[1] && rr >= l[1]) {
            int tmp = min(min(rr,r[1])-ll,min(rr,r[1])-l[1]);
            printf("%lld",1ll*tmp*binpow(r[1]-l[1],mod-2)%mod);
            // printf("\n%lld",1ll*1*binpow(4,mod-2)%mod);
            return 0;
        }else{
            puts("0");
            return 0;
        }
    }
    return 0;
}