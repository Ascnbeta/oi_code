#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
typedef long long ll;
using namespace std;
const int maxn = 1e5+30;
const ll mod = 1e9+7;
int n,m,a[maxn<<2];
ll val[maxn<<2],sum[maxn<<2];
inline void read(int &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-')f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
inline void pushup(int p) {
    val[p] = (val[ls]+val[rs])%mod;
    sum[p] = (sum[ls]+sum[rs])%mod;
}
inline void build(int p,int l,int r) {
    if (l == r) {
        val[p] = a[l];
        sum[p] = 1ll*a[l]*a[l]%mod;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
inline void modify(int p,int pos,ll v,int l,int r) {
    if (l == r) {
        val[p] = v;
        sum[p] = v*v%mod;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(ls,pos,v,l,mid);
    else modify(rs,pos,v,mid+1,r);
    pushup(p);
}
inline ll querysum(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        return val[p];
    }
    int mid = (l + r) >> 1;
    ll ret = 0;
    if (s <= mid) ret = querysum(ls,s,e,l,mid);
    if (e > mid) ret = (ret+querysum(rs,s,e,mid+1,r))%mod;
    return ret;
}
inline ll querysqsum(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        return sum[p];
    }
    int mid = (l + r) >> 1;
    ll ret = 0;
    if (s <= mid) ret = querysqsum(ls,s,e,l,mid);
    if (e > mid) ret = (ret+querysqsum(rs,s,e,mid+1,r))%mod;
    return ret;
}
inline ll binpow(ll base,ll b) {
    ll ret = 1;
    while (b) {
        if (b&1ll) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1ll;
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    build(1,1,n);
    while (m--) {
        int c,x,y;
        read(c),read(x),read(y);
        if (c == 1) {
            modify(1,x,y,1,n);
        }else{
            ll avg = querysum(1,x,y,1,n) * binpow(y-x+1,mod-2) % mod;
            ll ans = ((querysqsum(1,x,y,1,n)-2*avg%mod*querysum(1,x,y,1,n)%mod+mod)%mod+avg*avg%mod*(y-x+1)%mod)%mod*binpow(y-x+1,mod-2)%mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}