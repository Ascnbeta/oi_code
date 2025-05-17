#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6+30;
int T,n,m;
inline void read(int &v) {
    int x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    v = x*f;
    return; 
}
const ll mod = 1e9+7;
inline ll binpow(ll base,ll b) {
    ll ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret;
}
inline void write(int x) {
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
ll jc[maxn],jc_inv[maxn];
ll d[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(T);
    jc[0] = jc_inv[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        jc[i] = jc[i-1] * i % mod;
        jc_inv[i] = binpow(jc[i],mod-2);
    }
    d[1] = 0,d[2] = 1;
    for (int i = 3; i <= 1000000; i++) {
        d[i] = (i-1)*(d[i-1]+d[i-2])%mod;
    }
    while (T--) {
        read(n),read(m);
        if (n == m) {
            puts("1");
            continue;
        }
        ll c = jc[n]*jc_inv[m]%mod*jc_inv[n-m]%mod;
        write(c*d[n-m]%mod);putchar('\n');
    }
    return 0;
}