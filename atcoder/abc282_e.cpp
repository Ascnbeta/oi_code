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
int n,mod;
inline int binpow(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = 1ll*ret*base%mod;
        base = 1ll*base*base%mod;
        b >>= 1;
    }
    return ret;
}
int a[maxn],father[maxn];
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
struct edge{
    int u,v,w;
    bool operator < (const edge &y) const{
        return w > y.w;
    }
}e[maxn*maxn];int tot;
int main() {
#ifdef LOCAL
    freopen("E:/OI/exe/a.in","r",stdin);
    freopen("E:/OI/exe/a.out","w",stdout);
#endif
    read(n),read(mod);
    for (int i = 1; i <= n; i++) read(a[i]),father[i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            e[++tot] = {i,j,(binpow(a[i],a[j])+binpow(a[j],a[i]))%mod};
        }
    }
    sort(e+1,e+tot+1);
    long long ans = 0;int cnt = 0;
    for (int i = 1; i <= tot; i++) {
        int p = find(e[i].u),q = find(e[i].v);
        if (p != q) {
            father[p] = q;
            ans += e[i].w;
            ++cnt;
            if (cnt == n-1) break;
        }
    }
    write(ans);
    return 0;
}