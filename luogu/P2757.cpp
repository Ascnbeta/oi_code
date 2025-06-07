#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 5e5+30;
const ll mod1 = 1e9+7;
const ll mod2 = 20220713;
const ll p1 = 131;
const ll p2 = 101;
int T;
int n,a[maxn];
inline void read(int &x) {
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
#define ls p<<1
#define rs p<<1|1
#define fi first
#define se second
#define pll pair<ll,ll>
pll val1[maxn<<2],val2[maxn<<2];
ll pow1[maxn],pow2[maxn];
pll operator + (const pll x,const pll y) {
    return make_pair((x.fi+y.fi)%mod1,(x.se+y.se)%mod2);
}
pll operator * (const pll x,const ll y) {
    return make_pair(x.fi*pow1[y]%mod1,x.se*pow2[y]%mod2);
}
inline void pushup1(int p,int l,int r) {
    int mid = (l + r) >> 1;
    val1[p] = val1[ls]+val1[rs]*(mid-l+1);
}
inline void pushup2(int p,int l,int r) {
    int mid = (l + r) >> 1;
    val2[p] = val2[ls]*(r-mid)+val2[rs];
}
inline void build(int p,int l,int r) {
    if (l == r) {
        val1[p]=val2[p]={0,0};
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup1(p,l,r),pushup2(p,l,r);
}
inline pll query1(int p,int s,int e,int l,int r) {
    if (s > e) return {mod1,mod2};
    if (s <= l && r <= e) {
        return val1[p];
    }
    int mid = (l + r) >> 1;
    if (s > mid) return query1(rs,s,e,mid+1,r);
    else if (e <= mid) return query1(ls,s,e,l,mid);
    else return query1(ls,s,e,l,mid)+query1(rs,s,e,mid+1,r)*(mid-max(s,l)+1);
}
inline pll query2(int p,int s,int e,int l,int r) {
    if (s > e) return {mod1,mod2};
    if (s <= l && r <= e) {
        return val2[p];
    }
    int mid = (l + r) >> 1;
    if (s > mid) return query2(rs,s,e,mid+1,r);
    else if (e <= mid) return query2(ls,s,e,l,mid);
    else return query2(ls,s,e,l,mid)*(min(e,r)-mid)+query2(rs,s,e,mid+1,r);
}
inline void modify1(int p,int pos,int l,int r) {
    if (l == r) {
        val1[p] = val1[p] + make_pair(1ll,1ll);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify1(ls,pos,l,mid);
    else modify1(rs,pos,mid+1,r);
    pushup1(p,l,r);
}
inline void modify2(int p,int pos,int l,int r) {
    if (l == r) {
        val2[p] = val2[p] + make_pair(1ll,1ll);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify2(ls,pos,l,mid);
    else modify2(rs,pos,mid+1,r);
    pushup2(p,l,r);
}
int main () {
#ifdef LOCAL
    freopen("D:\\codes\\exe\\a.in","r",stdin);
    freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
    read(T);
    pow1[0]=pow2[0]=1;
    for (int i = 1; i <= 5e5+5; i++) pow1[i]=pow1[i-1]*p1%mod1,pow2[i]=pow2[i-1]*p2%mod2;
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        build(1,1,n);
        bool so = false;
        for (int i = 1; i <= n; i++) {
            modify1(1,a[i],1,n);
            modify2(1,a[i],1,n);
            int len = min(a[i]-1,n-a[i]);
            pll tmp1 = query1(1,a[i]-len,a[i]-1,1,n),tmp2 = query2(1,a[i]+1,a[i]+len,1,n);
            if (tmp1 != tmp2) {
                puts("Y");so = true;
                break;
            }
        }
        if (!so) puts("N");
    }
    return 0;
}