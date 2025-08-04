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
    if (x<0) x=-x,putchar(' ');
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
const int mod = 998244353;
const int maxn = 2e5+5;
int n,m,a[maxn];
#define ls p<<1
#define rs p<<1|1
int val[maxn<<2],tag[maxn<<2];
inline int binpow(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = 1ll * ret * base % mod;
        base = 1ll * base * base % mod;
        b >>= 1;
    }
    return ret;
}
inline void pushup(int p) {
    val[p] = (val[ls] + val[rs]) % mod;
}
inline void pushdown(int p,int l,int r) {
    int mid = (l + r) >> 1;
    tag[ls] = tag[rs] = tag[p];
    val[ls] = 1ll*tag[p]*(mid-l+1)%mod;
    val[rs] = 1ll*tag[p]*(r-mid)%mod;
    tag[p] = -1;
}
inline void build(int p,int l,int r) {
    tag[p] = -1;
    if (l == r) {
        val[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
inline void modify(int p,int s,int e,int v,int l,int r) {
    if (s <= l && r <= e) {
        val[p] = 1ll*v*(r-l+1)%mod;
        tag[p] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p] != -1) pushdown(p,l,r);
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
    pushup(p);
}
inline int query(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        return val[p];
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p] != -1) pushdown(p,l,r);
    int ret = 0;
    if (s <= mid) ret += query(ls,s,e,l,mid),ret %= mod;
    if (e > mid) ret += query(rs,s,e,mid+1,r),ret %= mod;
    return ret; 
}
inline void solve(int p,int l,int r) {
    if (l == r) {
        write(val[p]),putchar(' ');
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p] != -1) pushdown(p,l,r);
    solve(ls,l,mid);
    solve(rs,mid+1,r);
}
int main() {
#ifdef LOCAL
    freopen("E:/OI/exe/a.in","r",stdin);
    freopen("E:/OI/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    build(1,1,n);
    while (m--) {
        int l,r;
        read(l),read(r);
        int sum = query(1,l,r,1,n);
        sum = 1ll*sum*binpow(r-l+1,mod-2)%mod;
        modify(1,l,r,sum,1,n);
    }
    solve(1,1,n);
    return 0;
}