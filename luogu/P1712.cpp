#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch == '-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
const int maxn = 5e5+30;
int n,m;
struct zone{
    int l,r,tl,tr;
    bool operator < (const zone &y) const {
        return r-l < y.r-y.l;
    }
}z[maxn];
#define ls p<<1
#define rs p<<1|1
int val[maxn<<3],tag[maxn<<3];
inline void pushup(int p) {
    val[p] = max(val[ls],val[rs]);
}
inline void pushdown(int p) {
    val[ls] += tag[p];
    val[rs] += tag[p];
    tag[ls] += tag[p];
    tag[rs] += tag[p];
    tag[p] = 0;
}
inline void modify(int p,int s,int e,int v,int l,int r) {
    if (s == 0 || e == 0 || s > e) assert(0);
    if (s <= l && r <= e) {
        val[p] += v;
        tag[p] += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p]) pushdown(p);
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
    pushup(p);
}
int b[maxn<<1],tot,ans = 0x3f3f3f3f;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= n; i++) read(z[i].l),read(z[i].r),b[++tot] = z[i].l,b[++tot] = z[i].r;
    sort(b+1,b+tot+1);
    tot = unique(b+1,b+tot+1)-b-1;
    for (int i = 1; i <= n; i++) {
        z[i].tl = lower_bound(b+1,b+tot+1,z[i].l)-b;
        z[i].tr = lower_bound(b+1,b+tot+1,z[i].r)-b;
    }
    sort(z+1,z+n+1);
    int l = 1,r = 0;
    for (; l <= n && r <= n; ++l) {
        while(r < n && val[1] < m) {
            ++r;
            modify(1,z[r].tl,z[r].tr,1,1,tot);
        }
        if (val[1] < m) break;
        ans = min(z[r].r-z[r].l-z[l].r+z[l].l,ans);
        modify(1,z[l].tl,z[l].tr,-1,1,tot);
    }
    if (ans == 0x3f3f3f3f) puts("-1");
    else printf("%d",ans);
    return 0;
}