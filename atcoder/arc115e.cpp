#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define int long long
using namespace std;
const int maxn = 5e5+30;
const int mod = 998244353;
int n,n1,a[maxn],b[maxn];
int val[maxn<<2],taga[maxn<<2],tagm[maxn<<2],base[maxn<<2];
inline void pushup(int p) {
    val[p] = (val[ls] + val[rs]) % mod;
}
inline void pushdown(int p,int l,int r) {
    int mid = (l + r) >> 1;
    val[ls] = (val[ls]*tagm[p]%mod+taga[p]*(mid-l+1)%mod*base[ls]%mod)%mod;
    val[rs] = (val[rs]*tagm[p]%mod+taga[p]*(r-mid)%mod*base[rs]%mod)%mod;
    tagm[ls] = tagm[ls]*tagm[p]%mod;
    tagm[rs] = tagm[rs]*tagm[p]%mod;
    taga[ls] = (taga[ls]*tagm[p]%mod+taga[p])%mod;
    taga[rs] = (taga[rs]*tagm[p]%mod+taga[p])%mod;
    taga[p] = 0,tagm[p] = 1;
}
inline void build(int p,int l,int r) {
    tagm[p] = 1;
    if (l == r) {
        base[p] = b[l]-b[l-1];
        if (l <= a[1]) val[p] = base[p];
        else val[p] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    base[p] = (base[ls] + base[rs]) % mod;
    pushup(p);
}
inline void add(int p,int s,int e,int v,int l,int r) {
    if (s <= l && r <= e) {
        val[p] = (base[p]*v%mod*(r-l+1)%mod+val[p])%mod;
        taga[p] = (taga[p]+v)%mod;
        return;
    }
    int mid = (l + r) >> 1;
    if ((taga[p] || tagm[p] != 1) && l != r) pushdown(p,l,r);
    if (s <= mid) add(ls,s,e,v,l,mid);
    if (e > mid) add(rs,s,e,v,mid+1,r);
    pushup(p);
}
inline void multi(int p,int s,int e,int v,int l,int r) {
    if (s > e) return;
    if (s <= l && r <= e) {
        val[p] = val[p]*v%mod;
        taga[p] = taga[p]*v%mod;
        tagm[p] = tagm[p]*v%mod;
        return;
    }
    int mid = (l + r) >> 1;
    if ((taga[p] || tagm[p] != 1) && l != r) pushdown(p,l,r);
    if (s <= mid) multi(ls,s,e,v,l,mid);
    if (e > mid) multi(rs,s,e,v,mid+1,r);
    pushup(p);
}
inline int query(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) return val[p];
    int mid = (l + r) >> 1;
    if ((taga[p] || tagm[p] != 1) && l != r) pushdown(p,l,r);
    int ret = 0;
    if (s <= mid) ret = (ret + query(ls,s,e,l,mid)) % mod;
    if (e > mid) ret = (ret + query(rs,s,e,mid+1,r)) % mod;
    return ret;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++ ) cin >> a[i],b[i] = a[i];
    sort(b+1,b+n+1);
    n1 = unique(b+1,b+n+1)-b-1;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b+1,b+n1+1,a[i])-b;
    build(1,1,n1);
    for (int i = 2; i <= n; i++) {
        int tmp = query(1,1,a[i-1],1,n1);
        multi(1,1,a[i-1],-1,1,n1);
        add(1,1,a[i],tmp,1,n1);
        multi(1,a[i]+1,n1,0,1,n1);
    }
    cout << (query(1,1,n1,1,n1)+mod)%mod << '\n';
    return 0;
}