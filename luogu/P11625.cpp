#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
inline void read(ll &x){
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
inline void read(int &x){
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
const int maxn = 5e5+20;
int n,q;
ll c,d;
ll t1[maxn],t2[maxn];
int a[maxn];
inline int lowbit(int x) {
    return x&-x;
}
inline void modifyc(int p,int x) {
    while (p <= 5e5) {
        t1[p] += x;
        p += lowbit(p);
    }
}
inline ll queryc(int p) {
    ll ret = 0;
    while (p > 0) {
        ret += t1[p];
        p -= lowbit(p);
    }
    return ret;
}
inline void modifyd(int p,int x) {
    while (p <= 5e5) {
        t2[p] += x;
        p += lowbit(p);
    }
}
inline ll queryd(int p) {
    ll ret = 0;
    while (p > 0) {
        ret += t2[p];
        p -= lowbit(p);
    }
    return ret;
}
struct zone{
    int l,r,id;
    ll ans;
    bool operator < (const zone &y) const {
        return r < y.r;
    }
}z[maxn];
bool cmp(const zone &x,const zone &y) {
    return x.id < y.id;
}
ll cntc = 0,cntd = 0;
inline bool checkc(int p) {
    ll tmp = queryc(a[p]-1);
    if (cntc - tmp >= c) {
        modifyc(a[p],-1);
        cntc -= tmp;
        return true;
    }
    else return false;
}
#define ls p<<1
#define rs p<<1|1
ll sum[maxn<<2],tag[maxn<<2];
inline void pushup(int p) {
    sum[p] = sum[ls] + sum[rs];
}
inline void pushdown(int p,int l,int r) {
    int mid = (l + r) >> 1;
    sum[ls] += tag[p]*(mid-l+1);
    sum[rs] += tag[p]*(r-mid);
    tag[ls] += tag[p];
    tag[rs] += tag[p];
    tag[p] = 0;
}
inline void modify(int p,int s,int e,int v,int l,int r) {
    if (s <= l && r <= e) {
        sum[p] += 1ll*v*(r-l)+1;
        tag[p] += 1ll*v;
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p]) pushdown(p,l,r);
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
    pushup(p); 
}
inline ll query(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        return sum[p];
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p]) pushdown(p,l,r);
    ll ret = 0;
    if (s <= mid) ret += query(ls,s,e,l,mid);
    if (e > mid) ret += query(rs,s,e,mid+1,r);
    return ret;
}
int main () {
    read(n),read(c),read(d);
    for (int i = 1; i <= n; i++) read(a[i]);
    read(q);
    for (int i = 1; i <= q; i++) read(z[i].l),read(z[i].r),z[i].id=i;
    sort(z+1,z+q+1);
    int l = 1,r = 1;
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        ll tmp = queryc(5e5)-queryc(a[i]);
        cntc += tmp;
        modifyc(a[i],1);
        if (cntc >= c) {
            while (r<=i&&checkc(r)) ++r;
        }
        tmp = queryd(5e5)-queryd(a[i]);
        cntd += tmp;
        modifyd(a[i],1);
        if (cntd > d) {
            do{
                tmp = queryd(a[l]-1);
                modifyd(a[l],-1);
                cntd -= tmp;
                ++l;
            }while(l<i&&cntd>d);
        }
        if (l<=r&&cntc>=c&&cntd<=d) modify(1,l,r,1,1,n);
        while (z[cur].r <= i && cur <= q) {
            z[cur].ans = query(1,z[cur].l,z[cur].r,1,n);
            ++cur;
        }
    }
    sort(z+1,z+q+1,cmp);
    for (int i = 1; i <= q; i++) {
        printf("%lld\n",z[i].ans);
    }
    return 0;
}