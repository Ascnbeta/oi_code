#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 5e6+10;
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
inline void exgcd(int a,int b,int &x,int &y) {
    if (b == 0) {
        x = 1,y = 0;return;
    }
    exgcd(b,a%b,y,x);
    y -= a / b * x;
}
ll n,p,k;
int a[maxn],prod[maxn],p_inv[maxn],inv[maxn];
ll ans;
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    read(n),read(p),read(k);
    prod[0] = 1;
    for (int i = 1; i <= n; i++) {
        read(a[i]);prod[i] = 1ll * prod[i-1] * a[i] % p;
    }
    int tmp;
    exgcd(prod[n],p,p_inv[n],tmp);
    p_inv[n] %= p,p_inv[n] = (p_inv[n]+p)%p;
    for (int i = n; i >= 2; i--) p_inv[i-1] = 1ll*p_inv[i]*a[i]%p;
    ll tmpk = k;
    for (int i = 1; i <= n; i++) {
        inv[i] = 1ll*prod[i-1]*p_inv[i]%p;
        // cout << inv[i] << ' ';
        ans += 1ll*k*inv[i]%p;ans %= p;
        k *= tmpk;k %= p;
    }
    write(ans);
    return 0;
}