#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6+30;
int n,m;
int a[maxn];
ll val[maxn<<2],tag[maxn<<2];
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
inline void pushup(int p) {
    val[p] = min(val[ls],val[rs]);
}
inline void pushdown(int p) {
    val[ls] += tag[p];
    val[rs] += tag[p];
    tag[ls] += tag[p];
    tag[rs] += tag[p];
    tag[p] = 0;
}
inline void build(int p,int l,int r) {
    if (l == r) {
        val[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
inline void modify(int p,int s,int e,ll v,int l,int r) {
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
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    build(1,1,n);
    for (int i = 1; i <= m; i++) {
        int d,s,t;
        read(d),read(s),read(t);
        modify(1,s,t,-1ll*d,1,n);
        if (val[1] < 0ll) {
            puts("-1");
            printf("%d",i);
            return 0;
        }
    }
    puts("0");
    return 0;
}